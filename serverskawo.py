
import os
import socket
import socketserver
import struct

# ip stores local IP of the computer that has the
# files with which the game's files should be patched.
ip = "192.168.0.102"

class TCPHandler(socketserver.BaseRequestHandler):
    def setup(self):
        print('Connection')
        self.files = {}
        self.fhandle = 0x12345678

    def handle(self):
        while True:
            try:
                rawcmd = self.request.recv(1)
            except Exception as e:
                import traceback
                print('Error while serving file:\n' + traceback.format_exc())
                return

            if not rawcmd:
                return

            cmd = ord(rawcmd)
            if cmd == 1: # Patches
                print('Sending patches')
                self.sendFile('NewerU/Patches.hax')
                self.sendFile('NewerU/Code.bin')
                self.sendFile('NewerU/Data.bin')
                self.sendFileList()
                self.sendFile('NewerU/Ctors.bin')

            elif cmd == 2: # Open file
                length = struct.unpack('>I', self.request.recv(4))[0]
                path = self.request.recv(length).lstrip('/')
                print(path)
                self.files[self.fhandle] = open(path, 'rb')
                self.request.sendall(struct.pack('>I', self.fhandle))
                self.fhandle += 1

            elif cmd == 3: # Read file
                print('Read')
                handle = struct.unpack('>I', self.request.recv(4))[0]
                length = struct.unpack('>I', self.request.recv(4))[0]

                data = self.files[handle].read(length)
                self.request.sendall(struct.pack('>I', len(data)))
                self.request.sendall(data)

            elif cmd == 4: # Write file
                print('Write')
                handle = struct.unpack('>I', self.request.recv(4))[0]
                length = struct.unpack('>I', self.request.recv(4))[0]

                data = self.request.recv(length)
                while len(data) < length:
                    data += self.request.recv(length - len(data))
                self.files[handle].write(data)

            elif cmd == 5: # Close file
                print('Close')
                handle = struct.unpack('>I', self.request.recv(4))[0]
                self.files.pop(handle).close()

            elif cmd == 6: # Save open file
                length = struct.unpack('>I', self.request.recv(4))[0]
                path = self.request.recv(length)
                mode = self.request.recv(1)
                print('SAVEOpenFile(%s, %s)' % (path, mode))
                savepath = 'vol/save/%s' % path
                if os.path.isfile(savepath) or mode == 'w':
                    self.files[self.fhandle] = open(savepath, mode+'b')
                    self.request.sendall(struct.pack('>I', self.fhandle))
                    self.fhandle += 1
                else:
                    self.request.sendall(b'\0\0\0\0')

            elif cmd == 7: # Debug message
                length = struct.unpack('>I', self.request.recv(4))[0]
                message = self.request.recv(length)
                print('DEBUG:', message)

            else:
                print('Invalid command: %i' % cmd)

    def sendFile(self, fn):
        with open(fn, 'rb') as f:
            data = f.read()
        self.request.sendall(struct.pack('>I', len(data)))
        self.request.sendall(data)

    def sendFileList(self):
        print('Sending list of files')
        fileList = b''
        fileCount = 0
        for dirname, subdirs, files in os.walk('vol'):
            for filename in files:
                filepath = '/' + dirname.replace('\\', '/') + '/' + filename
                fileList += bytes([len(filepath)]) + filepath.encode('latin-1')
                fileCount += 1

        message = struct.pack('>I', fileCount) + fileList
        self.request.sendall(struct.pack('>I', len(message)))
        self.request.sendall(message)

    def finish(self):
        print('Finish')

server = socketserver.TCPServer((ip, 2557), TCPHandler)
print('Server has been started')
print('Listening at (%s, 2557)' % ip)
server.serve_forever()
