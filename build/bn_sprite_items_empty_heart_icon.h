#ifndef BN_SPRITE_ITEMS_EMPTY_HEART_ICON_H
#define BN_SPRITE_ITEMS_EMPTY_HEART_ICON_H

#include "bn_sprite_item.h"

//{{BLOCK(empty_heart_icon_bn_gfx)

//======================================================================
//
//	empty_heart_icon_bn_gfx, 32x16@8, 
//	+ palette 64 entries, not compressed
//	+ 8 tiles not compressed
//	Total size: 128 + 512 = 640
//
//	Time-stamp: 2024-08-15, 10:25:27
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_EMPTY_HEART_ICON_BN_GFX_H
#define GRIT_EMPTY_HEART_ICON_BN_GFX_H

#define empty_heart_icon_bn_gfxTilesLen 512
extern const bn::tile empty_heart_icon_bn_gfxTiles[16];

#define empty_heart_icon_bn_gfxPalLen 128
extern const bn::color empty_heart_icon_bn_gfxPal[64];

#endif // GRIT_EMPTY_HEART_ICON_BN_GFX_H

//}}BLOCK(empty_heart_icon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item empty_heart_icon(sprite_shape_size(sprite_shape::WIDE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(empty_heart_icon_bn_gfxTiles, 16), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(empty_heart_icon_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

