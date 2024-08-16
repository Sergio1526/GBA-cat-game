#ifndef BN_SPRITE_ITEMS_FLOWER_H
#define BN_SPRITE_ITEMS_FLOWER_H

#include "bn_sprite_item.h"

//{{BLOCK(flower_bn_gfx)

//======================================================================
//
//	flower_bn_gfx, 8x16@4, 
//	+ palette 16 entries, not compressed
//	+ 2 tiles not compressed
//	Total size: 32 + 64 = 96
//
//	Time-stamp: 2024-08-16, 12:45:24
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FLOWER_BN_GFX_H
#define GRIT_FLOWER_BN_GFX_H

#define flower_bn_gfxTilesLen 64
extern const bn::tile flower_bn_gfxTiles[2];

#define flower_bn_gfxPalLen 32
extern const bn::color flower_bn_gfxPal[16];

#endif // GRIT_FLOWER_BN_GFX_H

//}}BLOCK(flower_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item flower(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(flower_bn_gfxTiles, 2), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(flower_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

