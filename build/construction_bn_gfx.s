
@{{BLOCK(construction_bn_gfx)

@=======================================================================
@
@	construction_bn_gfx, 32x16@4, 
@	+ palette 16 entries, not compressed
@	+ 8 tiles not compressed
@	Total size: 32 + 256 = 288
@
@	Time-stamp: 2024-08-16, 09:15:46
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global construction_bn_gfxTiles		@ 256 unsigned chars
	.hidden construction_bn_gfxTiles
construction_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x11111111,0x31133311,0x33113331,0x33311331,0x13331110,0x11333110
	.word 0x00000000,0x11111111,0x33311333,0x13331133,0x11333113,0x31133311,0x33113331,0x33311333
	.word 0x00000000,0x11111111,0x31133311,0x33113331,0x33311333,0x13331133,0x11333113,0x31133311
	.word 0x01111111,0x01311333,0x01331133,0x01333113,0x11133311,0x13113331,0x13311333,0x11111111
	.word 0x31133310,0x11111110,0x00420000,0x00420000,0x00420000,0x00420000,0x00420000,0x00420000
	.word 0x11111111,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x11111111,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000042,0x00000042,0x00000042,0x00000042,0x00000042,0x00000042,0x00000042,0x00000042

	.section .rodata
	.align	2
	.global construction_bn_gfxPal		@ 32 unsigned chars
	.hidden construction_bn_gfxPal
construction_bn_gfxPal:
	.hword 0x03E0,0x0000,0x56B5,0x035F,0x6F9A,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(construction_bn_gfx)
