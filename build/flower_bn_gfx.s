
@{{BLOCK(flower_bn_gfx)

@=======================================================================
@
@	flower_bn_gfx, 8x16@4, 
@	+ palette 16 entries, not compressed
@	+ 2 tiles not compressed
@	Total size: 32 + 64 = 96
@
@	Time-stamp: 2024-08-21, 10:51:16
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global flower_bn_gfxTiles		@ 64 unsigned chars
	.hidden flower_bn_gfxTiles
flower_bn_gfxTiles:
	.word 0x11111111,0x11111111,0x11111511,0x11115851,0x11511511,0x15851111,0x11511111,0x11111111
	.word 0x11111111,0x11111151,0x11111585,0x11151151,0x11585111,0x11151111,0x11111111,0x11111111

	.section .rodata
	.align	2
	.global flower_bn_gfxPal		@ 32 unsigned chars
	.hidden flower_bn_gfxPal
flower_bn_gfxPal:
	.hword 0x0000,0x2398,0x4304,0x739C,0x031E,0x401F,0x4210,0x318C
	.hword 0x03FF,0x77F8,0x7FE0,0x7EA0,0x7F60,0x7BFE,0x4AB8,0x38E8

@}}BLOCK(flower_bn_gfx)
