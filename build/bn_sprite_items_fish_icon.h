#ifndef BN_SPRITE_ITEMS_FISH_ICON_H
#define BN_SPRITE_ITEMS_FISH_ICON_H

#include "bn_sprite_item.h"

//{{BLOCK(fish_icon_bn_gfx)

//======================================================================
//
//	fish_icon_bn_gfx, 32x96@8, 
//	+ palette 64 entries, not compressed
//	+ 48 tiles not compressed
//	Total size: 128 + 3072 = 3200
//
//	Time-stamp: 2024-08-14, 17:35:19
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FISH_ICON_BN_GFX_H
#define GRIT_FISH_ICON_BN_GFX_H

#define fish_icon_bn_gfxTilesLen 3072
extern const bn::tile fish_icon_bn_gfxTiles[96];

#define fish_icon_bn_gfxPalLen 128
extern const bn::color fish_icon_bn_gfxPal[64];

#endif // GRIT_FISH_ICON_BN_GFX_H

//}}BLOCK(fish_icon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item fish_icon(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(fish_icon_bn_gfxTiles, 96), bpp_mode::BPP_8, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(fish_icon_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

