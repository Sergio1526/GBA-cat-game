#ifndef BN_SPRITE_ITEMS_CAT_HAND_H
#define BN_SPRITE_ITEMS_CAT_HAND_H

#include "bn_sprite_item.h"

//{{BLOCK(cat_hand_bn_gfx)

//======================================================================
//
//	cat_hand_bn_gfx, 64x64@8, 
//	+ palette 64 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 128 + 4096 = 4224
//
//	Time-stamp: 2024-08-13, 17:44:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CAT_HAND_BN_GFX_H
#define GRIT_CAT_HAND_BN_GFX_H

#define cat_hand_bn_gfxTilesLen 4096
extern const bn::tile cat_hand_bn_gfxTiles[128];

#define cat_hand_bn_gfxPalLen 128
extern const bn::color cat_hand_bn_gfxPal[64];

#endif // GRIT_CAT_HAND_BN_GFX_H

//}}BLOCK(cat_hand_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cat_hand(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(cat_hand_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(cat_hand_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

