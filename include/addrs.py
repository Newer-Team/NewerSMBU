
with open('D:\\Benutzer\\Yannik\\Desktop\\compiler\\boss\\objs\\names.txt') as f:
    lines = f.readlines()

print len(lines)

vt = 0x1050782C
i = 0
for addr in range(vt + 0x4E4, vt + 0x7FC + 1, 8):
    print hex(addr - vt)
    lines[i] = lines[i][:-1] + '0x' + hex(Dword(addr))[2:].zfill(8).upper() + ';'
    i += 1

with open('D:\\Benutzer\\Yannik\\Desktop\\compiler\\boss\\objs\\syms.txt', 'w') as f:
    f.writelines('\n'.join(lines))
