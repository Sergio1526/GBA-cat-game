
@{{BLOCK(dino_bn_gfx)

@=======================================================================
@
@	dino_bn_gfx, 64x64@4, 
@	+ palette 16 entries, not compressed
@	+ 64 tiles not compressed
@	Total size: 32 + 2048 = 2080
@
@	Time-stamp: 2024-06-17, 11:21:51
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global dino_bn_gfxTiles		@ 2048 unsigned chars
	.hidden dino_bn_gfxTiles
dino_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x10000000,0x11000000,0x11110000,0xA1111000,0xAAA11100
	.word 0x00000000,0x00000000,0x00000000,0x11111111,0x11111111,0xAAAAAAA1,0xAAAAAAAA,0x11AAAAAA
	.word 0x00000000,0x00000000,0x00000000,0x00000111,0x00001111,0x000111AA,0x11111AAA,0x1111AAAA
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000111

	.word 0x00000000,0x00000000,0x01111000,0x11111100,0x11AA1110,0xAAAAA111,0xAAAAAA11,0xAAAAAA11
	.word 0x00000000,0x00000000,0x00000000,0x00000001,0x00000111,0x01111111,0x11111AAA,0x11AAAAAA
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x11111000,0x11111110,0xAAAA1111,0xAAAAA111
	.word 0x00000000,0x00000000,0x10000000,0x11000000,0x11000111,0x11111111,0x111111AA,0xAA11AAAA
	.word 0xAAAA1110,0xAAAAA111,0xAAAAAA11,0xAAAAAA11,0xAAAAAAA1,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x11AAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xABBBBBAA,0xBBBBBBBA
	.word 0x1AAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x00001111,0x000111AA,0x00111AAA,0x0111AAAA,0x0111AAAA,0x011AAAAA,0x011AAAAA,0x011AAAAA

	.word 0xAAAAAD11,0xAAAAAD11,0xAAAAAD11,0xAAAAAD11,0xAAAAAD11,0xAAAAAD11,0xAAAAD111,0xAAA66111
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAABBAA,0xAAAABBAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBB,0xBBBBBBBA,0xABBBBBAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAB,0xAAAAAAAB,0xAAAAAAAB,0xAAAAAAAB,0xAAAAAAAA,0xAAAAAAAA,0x444AAAAA,0x44444AAA
	.word 0x011AAAAA,0x011AAAAA,0x011AAAAA,0x011AAAAA,0x011AAAAA,0x011AAAAA,0x01144444,0x01144444

	.word 0xAA666110,0xA6661110,0x66611100,0x66111000,0x61110000,0x11100000,0x11000000,0x10000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA6,0xAAAAAA66,0xAAAAAA66,0xAAAAAA11,0xAAAAAA11
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x666AAAAA,0x6666AAAA,0x116666AA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x666AAAAA,0x6666AAAA,0x66666666,0x16666666,0x11111111
	.word 0x0111AAAA,0x0011AAAA,0x00111AAA,0x00011666,0x00011166,0x00001116,0x00000111,0x00000011

	.word 0x10000000,0x10000000,0x11000000,0x11000000,0x11000000,0x11100000,0xA1100000,0xA1100000
	.word 0xAAAAAA11,0xAAAAAAA1,0xAAAAAAA1,0xAAAAAAA1,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x6666666A,0x6666666A,0x666666AA,0x6666644A
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAA66A,0xAAAAA666,0xAAAAA666,0xAAAA6666,0xAAAA1166
	.word 0xAAAAAAAA,0xAAAAAAAA,0x4AAAAAAA,0x4AAAAAAA,0x4AAAAAAA,0x1AAAAAAA,0x1AAAAAAA,0x1AAAAAAA
	.word 0x116666AA,0x11166666,0x01116664,0x00111664,0x00111464,0x00111441,0x00111441,0x00114441
	.word 0x11111111,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0xA1110000,0xAA110000,0xAA110000,0xAA110000,0x11110000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x11111111,0x00000000,0x00000000,0x00000000
	.word 0x111114AA,0x111111AA,0x114411AA,0x144411AA,0x11111111,0x00000000,0x00000000,0x00000000
	.word 0xAAA11111,0xAAA11111,0xAA111001,0xAA110001,0x11110001,0x00000000,0x00000000,0x00000000
	.word 0x1AAAAAAA,0x1AAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x11111111,0x00000000,0x00000000,0x00000000
	.word 0x01114441,0x01144411,0x11144411,0x11144411,0x11111111,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global dino_bn_gfxPal		@ 32 unsigned chars
	.hidden dino_bn_gfxPal
dino_bn_gfxPal:
	.hword 0x03E0,0x0C84,0x2904,0x3589,0x0CB0,0x2591,0x4ED5,0x3238
	.hword 0x66A2,0x4F1A,0x157C,0x167E,0x7F2D,0x7FFF,0x001F,0x001F

@}}BLOCK(dino_bn_gfx)
