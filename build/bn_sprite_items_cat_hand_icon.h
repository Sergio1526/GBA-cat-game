#ifndef BN_SPRITE_ITEMS_CAT_HAND_ICON_H
#define BN_SPRITE_ITEMS_CAT_HAND_ICON_H

#include "bn_sprite_item.h"

//{{BLOCK(cat_hand_icon_bn_gfx)

//======================================================================
//
//	cat_hand_icon_bn_gfx, 32x32@8, 
//	+ palette 64 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 128 + 1024 = 1152
//
//	Time-stamp: 2024-08-15, 13:14:37
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CAT_HAND_ICON_BN_GFX_H
#define GRIT_CAT_HAND_ICON_BN_GFX_H

#define cat_hand_icon_bn_gfxTilesLen 1024
extern const bn::tile cat_hand_icon_bn_gfxTiles[32];

#define cat_hand_icon_bn_gfxPalLen 128
extern const bn::color cat_hand_icon_bn_gfxPal[64];

#endif // GRIT_CAT_HAND_ICON_BN_GFX_H

//}}BLOCK(cat_hand_icon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cat_hand_icon(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(cat_hand_icon_bn_gfxTiles, 32), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(cat_hand_icon_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

