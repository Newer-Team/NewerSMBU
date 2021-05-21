
names = []
addr = 0x148 + 0x4E4
while addr <= 0x148 + 0x7FC:
    names.append('\t' + Name(Dword(addr)) + ' = ')
    addr += 8

with open('names.txt', 'w') as f:
    f.write('\n'.join(names))
