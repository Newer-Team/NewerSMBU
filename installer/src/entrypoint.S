
.set r1, 1

_start:
	lis r1, 0x1AB5
	ori r1, r1, 0xD138
	b _main__Fv
	