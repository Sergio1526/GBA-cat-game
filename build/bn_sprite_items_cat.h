#ifndef BN_SPRITE_ITEMS_CAT_H
#define BN_SPRITE_ITEMS_CAT_H

#include "bn_sprite_item.h"

//{{BLOCK(cat_bn_gfx)

//======================================================================
//
//	cat_bn_gfx, 32x64@4, 
//	+ palette 16 entries, not compressed
//	+ 32 tiles not compressed
//	Total size: 32 + 1024 = 1056
//
//	Time-stamp: 2024-07-12, 12:17:16
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CAT_BN_GFX_H
#define GRIT_CAT_BN_GFX_H

#define cat_bn_gfxTilesLen 1024
extern const bn::tile cat_bn_gfxTiles[32];

#define cat_bn_gfxPalLen 32
extern const bn::color cat_bn_gfxPal[16];

#endif // GRIT_CAT_BN_GFX_H

//}}BLOCK(cat_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cat(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(cat_bn_gfxTiles, 32), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(cat_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

