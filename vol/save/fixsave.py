
import binascii
import struct

def crc32(dat):
    return struct.pack('>i', binascii.crc32(dat))

with open('rp_savedata.dat', 'rb') as f:
    data = f.read()

data = data[:0xC] + crc32(data[:0xC]) + data[0x10:]
for i in range(12):
    data = data[:0x210 + 0x204 * i] + crc32(data[0x10 + 0x204 * i : 0x210 + 0x204 * i]) + data[0x214 + 0x204 * i:]

data = data[:0x1840 + 0x3608] + crc32(data[0x1840:0x1840 + 0x3608]) + data[0x1840 + 0x360C:]
data = data[:0x4EF0] + crc32(data[0x4E4C:0x4EF0]) + data[0x4EF4:]
data = data[:0xAE28] + crc32(data[0x4EF4:0xAE28]) + data[0xAE2C:]
data = data[:0xB130] + crc32(data[0xAEC0:0xB130])

with open('rp_savedata.dat', 'wb') as f:
    f.write(data)
