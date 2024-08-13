#ifndef BN_SPRITE_ITEMS_CONSTRUCTION_H
#define BN_SPRITE_ITEMS_CONSTRUCTION_H

#include "bn_sprite_item.h"

//{{BLOCK(construction_bn_gfx)

//======================================================================
//
//	construction_bn_gfx, 32x16@4, 
//	+ palette 16 entries, not compressed
//	+ 8 tiles not compressed
//	Total size: 32 + 256 = 288
//
//	Time-stamp: 2024-08-13, 11:45:08
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CONSTRUCTION_BN_GFX_H
#define GRIT_CONSTRUCTION_BN_GFX_H

#define construction_bn_gfxTilesLen 256
extern const bn::tile construction_bn_gfxTiles[8];

#define construction_bn_gfxPalLen 32
extern const bn::color construction_bn_gfxPal[16];

#endif // GRIT_CONSTRUCTION_BN_GFX_H

//}}BLOCK(construction_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item construction(sprite_shape_size(sprite_shape::WIDE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(construction_bn_gfxTiles, 8), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(construction_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

