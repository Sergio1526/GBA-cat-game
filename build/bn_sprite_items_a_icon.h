#ifndef BN_SPRITE_ITEMS_A_ICON_H
#define BN_SPRITE_ITEMS_A_ICON_H

#include "bn_sprite_item.h"

//{{BLOCK(a_icon_bn_gfx)

//======================================================================
//
//	a_icon_bn_gfx, 32x64@8, 
//	+ palette 64 entries, not compressed
//	+ 32 tiles not compressed
//	Total size: 128 + 2048 = 2176
//
//	Time-stamp: 2024-08-16, 09:15:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_A_ICON_BN_GFX_H
#define GRIT_A_ICON_BN_GFX_H

#define a_icon_bn_gfxTilesLen 2048
extern const bn::tile a_icon_bn_gfxTiles[64];

#define a_icon_bn_gfxPalLen 128
extern const bn::color a_icon_bn_gfxPal[64];

#endif // GRIT_A_ICON_BN_GFX_H

//}}BLOCK(a_icon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item a_icon(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(a_icon_bn_gfxTiles, 64), bpp_mode::BPP_8, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(a_icon_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

