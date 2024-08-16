
@{{BLOCK(limit_bn_gfx)

@=======================================================================
@
@	limit_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2024-08-15, 20:10:13
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global limit_bn_gfxTiles		@ 128 unsigned chars
	.hidden limit_bn_gfxTiles
limit_bn_gfxTiles:
	.word 0x00000000,0x11111110,0x22333331,0x22333331,0x22333331,0x23333331,0x23333331,0x33333331
	.word 0x00000000,0x00111111,0x01333322,0x01333322,0x01333322,0x01333332,0x01333332,0x01333333
	.word 0x23333331,0x23333331,0x11111110,0x10000000,0x10000000,0x31000000,0x31000000,0x10000000
	.word 0x01333332,0x01333332,0x00113333,0x00013333,0x00001133,0x00000013,0x00000001,0x00000000

	.section .rodata
	.align	2
	.global limit_bn_gfxPal		@ 32 unsigned chars
	.hidden limit_bn_gfxPal
limit_bn_gfxPal:
	.hword 0x03E0,0x7C00,0x001F,0x7FFF,0x4000,0x4010,0x4200,0x6318
	.hword 0x4210,0x001F,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(limit_bn_gfx)
