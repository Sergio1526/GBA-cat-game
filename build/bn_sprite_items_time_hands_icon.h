#ifndef BN_SPRITE_ITEMS_TIME_HANDS_ICON_H
#define BN_SPRITE_ITEMS_TIME_HANDS_ICON_H

#include "bn_sprite_item.h"

//{{BLOCK(time_hands_icon_bn_gfx)

//======================================================================
//
//	time_hands_icon_bn_gfx, 32x32@8, 
//	+ palette 64 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 128 + 1024 = 1152
//
//	Time-stamp: 2024-08-16, 09:15:47
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TIME_HANDS_ICON_BN_GFX_H
#define GRIT_TIME_HANDS_ICON_BN_GFX_H

#define time_hands_icon_bn_gfxTilesLen 1024
extern const bn::tile time_hands_icon_bn_gfxTiles[32];

#define time_hands_icon_bn_gfxPalLen 128
extern const bn::color time_hands_icon_bn_gfxPal[64];

#endif // GRIT_TIME_HANDS_ICON_BN_GFX_H

//}}BLOCK(time_hands_icon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item time_hands_icon(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(time_hands_icon_bn_gfxTiles, 32), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(time_hands_icon_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

