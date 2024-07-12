
@{{BLOCK(collider_bn_gfx)

@=======================================================================
@
@	collider_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2024-07-12, 09:43:02
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global collider_bn_gfxTiles		@ 32 unsigned chars
	.hidden collider_bn_gfxTiles
collider_bn_gfxTiles:
	.word 0x00000000,0x01111110,0x01111110,0x01111110,0x01111110,0x01111110,0x01111110,0x00000000

	.section .rodata
	.align	2
	.global collider_bn_gfxPal		@ 32 unsigned chars
	.hidden collider_bn_gfxPal
collider_bn_gfxPal:
	.hword 0x7FFF,0x7C00,0x001F,0x0210,0x4000,0x4010,0x4200,0x6318
	.hword 0x4210,0x001F,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(collider_bn_gfx)
