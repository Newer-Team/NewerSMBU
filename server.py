
import socketserver, socket, struct, os

# ip stores local IP of the computer that has the 
# files by which the game's files should be patched.
ip = socket.gethostbyname(socket.gethostname())

class TCPHandler(socketserver.BaseRequestHandler):
    def setup(self):
        print('Connection')
        self.files = {}
        self.fhandle = 0x12345678

    def handle(self):
        while True:
            try: rawcmd = self.request.recv(1)
            except: return
	    
            if not rawcmd:
                return
            
            cmd = ord(rawcmd)
            if cmd == 1:
                print('Going to send patches (hopefully).')

            elif cmd == 0x80: self.sendFile('NewerU/Patches.hax')
            elif cmd == 0x81: self.sendFile('NewerU/Code.bin')
            elif cmd == 0x82: self.sendFile('NewerU/Data.bin')
            elif cmd == 0x83: self.sendFileList()
            elif cmd == 0x84: self.sendFile('NewerU/Ctors.bin')
                
            elif cmd == 2: #Open file
                length = struct.unpack('>I', self.request.recv(4))[0]
                path = self.request.recv(length).lstrip(b'/')
                print('FSOpenFile(%s)' %path)
                self.files[self.fhandle] = open(path, 'rb')
                self.request.sendall(struct.pack('>I', self.fhandle))
                self.fhandle += 1

            elif cmd == 3: #Read file
                print(' - Read')
                handle = struct.unpack('>I', self.request.recv(4))[0]
                size = struct.unpack('>I', self.request.recv(4))[0]
                count = struct.unpack('>I', self.request.recv(4))[0]

                data = self.files[handle].read(size * count)
                self.request.sendall(struct.pack('>I', len(data) // size))
                self.request.sendall(struct.pack('>I', len(data)))
                self.request.sendall(data)

            elif cmd == 4: #Write file
                print(' - Write')
                handle = struct.unpack('>I', self.request.recv(4))[0]
                length = struct.unpack('>I', self.request.recv(4))[0]

                data = self.recvall(length)
                self.files[handle].write(data)

            elif cmd == 5: #Close file
                print(' - Close')
                handle = struct.unpack('>I', self.request.recv(4))[0]
                self.files.pop(handle).close()

            elif cmd == 6: #Save open file
                length = struct.unpack('>I', self.request.recv(4))[0]
                path = self.request.recv(length)
                mode = chr(self.request.recv(1)[0])
                print('SAVEOpenFile(%s, %s)' %(path, mode))
                savepath = b'vol/save/' + path
                if os.path.isfile(savepath) or mode == 'w':
                    self.files[self.fhandle] = open(savepath, mode+'b')
                    self.request.sendall(struct.pack('>I', self.fhandle))
                    self.fhandle += 1
                else:
                    self.request.sendall(b'\x00\x00\x00\x00')
            
            elif cmd == 7: #Debug message
                length = struct.unpack('>I', self.request.recv(4))[0]
                message = self.request.recv(length)
                print('DEBUG:', message)

            elif cmd == 8: #Get stat file
                print(' - GetStatFile')
                handle = struct.unpack('>I', self.request.recv(4))[0]
                file = self.files[handle]
                pos = file.tell()
                file.seek(0, 2)
                size = file.tell()
                file.seek(pos)
                self.request.sendall(struct.pack('>I', size))

            elif cmd == 9: #Set pos file
                handle = struct.unpack('>I', self.request.recv(4))[0]
                pos = struct.unpack('>I', self.request.recv(4))[0]
                print(' - SetPosFile(%i)' %pos)
                self.files[handle].seek(pos)

            elif cmd == 10: #Crash report
                length = struct.unpack('>I', self.request.recv(4))[0]
                report = self.request.recv(length).decode('ascii', 'ignore')
                print(report)

                length = struct.unpack('>I', self.request.recv(4))[0]
                stackTrace = struct.unpack('>' + 'I' * length, self.request.recv(length * 4))
                print('Stack trace:')
                for address in stackTrace:
                    print('\t' + hex(address))

            elif cmd == 11: #Debug file
                fnlength, length = struct.unpack('>II', self.request.recv(8))
                filename = self.request.recv(fnlength).decode('ascii')
                data = self.recvall(length)
                with open('DebugFiles/' + filename, 'wb') as f:
                    f.write(data)
            else:
                print('Invalid command: %i' %cmd)

    def recvall(self, length):
        data = self.request.recv(length)
        while len(data) < length:
            data += self.request.recv(length - len(data))
        return data

    def sendFile(self, fn):
        print('Sending file:', fn)
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
                fileList += bytes([len(filepath)]) + filepath.encode('ascii')
                fileCount += 1

        message = struct.pack('>I', fileCount) + fileList
        self.request.sendall(struct.pack('>I', len(message)))
        self.request.sendall(message)

    def finish(self):
        print('Finish')

class TCPServer(socketserver.TCPServer, socketserver.ThreadingMixIn): pass

server = TCPServer((ip, 2557), TCPHandler)
print('Server has been started')
print('Listening at (%s, 2557)' %ip)
server.serve_forever()
