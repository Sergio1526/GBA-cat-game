#ifndef BN_SPRITE_ITEMS_HEART_ICON_H
#define BN_SPRITE_ITEMS_HEART_ICON_H

#include "bn_sprite_item.h"

//{{BLOCK(heart_icon_bn_gfx)

//======================================================================
//
//	heart_icon_bn_gfx, 32x16@8, 
//	+ palette 64 entries, not compressed
//	+ 8 tiles not compressed
//	Total size: 128 + 512 = 640
//
//	Time-stamp: 2024-08-15, 09:56:25
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HEART_ICON_BN_GFX_H
#define GRIT_HEART_ICON_BN_GFX_H

#define heart_icon_bn_gfxTilesLen 512
extern const bn::tile heart_icon_bn_gfxTiles[16];

#define heart_icon_bn_gfxPalLen 128
extern const bn::color heart_icon_bn_gfxPal[64];

#endif // GRIT_HEART_ICON_BN_GFX_H

//}}BLOCK(heart_icon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item heart_icon(sprite_shape_size(sprite_shape::WIDE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(heart_icon_bn_gfxTiles, 16), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(heart_icon_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

