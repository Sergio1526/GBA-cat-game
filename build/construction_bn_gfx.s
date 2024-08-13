
@{{BLOCK(construction_bn_gfx)

@=======================================================================
@
@	construction_bn_gfx, 32x16@4, 
@	+ palette 16 entries, not compressed
@	+ 8 tiles not compressed
@	Total size: 32 + 256 = 288
@
@	Time-stamp: 2024-08-12, 21:40:07
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global construction_bn_gfxTiles		@ 256 unsigned chars
	.hidden construction_bn_gfxTiles
construction_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x33333333,0x43344433,0x44334443,0x44433443,0x34443330,0x33444330
	.word 0x00000000,0x33333333,0x44433444,0x34443344,0x33444334,0x43344433,0x44334443,0x44433444
	.word 0x00000000,0x33333333,0x43344433,0x44334443,0x44433444,0x34443344,0x33444334,0x43344433
	.word 0x03333333,0x03433444,0x03443344,0x03444334,0x33344433,0x34334443,0x34433444,0x33333333
	.word 0x43344430,0x33333330,0x00210000,0x00210000,0x00210000,0x00210000,0x00210000,0x00210000
	.word 0x33333333,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x33333333,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000021,0x00000021,0x00000021,0x00000021,0x00000021,0x00000021,0x00000021,0x00000021

	.section .rodata
	.align	2
	.global construction_bn_gfxPal		@ 32 unsigned chars
	.hidden construction_bn_gfxPal
construction_bn_gfxPal:
	.hword 0x03E0,0x56B5,0x6F9A,0x0000,0x035F,0x4010,0x4200,0x6318
	.hword 0x4210,0x001F,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(construction_bn_gfx)
