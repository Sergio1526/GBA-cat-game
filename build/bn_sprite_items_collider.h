#ifndef BN_SPRITE_ITEMS_COLLIDER_H
#define BN_SPRITE_ITEMS_COLLIDER_H

#include "bn_sprite_item.h"

//{{BLOCK(collider_bn_gfx)

//======================================================================
//
//	collider_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2024-07-10, 20:16:02
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_COLLIDER_BN_GFX_H
#define GRIT_COLLIDER_BN_GFX_H

#define collider_bn_gfxTilesLen 32
extern const bn::tile collider_bn_gfxTiles[1];

#define collider_bn_gfxPalLen 32
extern const bn::color collider_bn_gfxPal[16];

#endif // GRIT_COLLIDER_BN_GFX_H

//}}BLOCK(collider_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item collider(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(collider_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(collider_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

