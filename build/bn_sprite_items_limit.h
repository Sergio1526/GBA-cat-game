#ifndef BN_SPRITE_ITEMS_LIMIT_H
#define BN_SPRITE_ITEMS_LIMIT_H

#include "bn_sprite_item.h"

//{{BLOCK(limit_bn_gfx)

//======================================================================
//
//	limit_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2024-07-10, 19:57:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LIMIT_BN_GFX_H
#define GRIT_LIMIT_BN_GFX_H

#define limit_bn_gfxTilesLen 32
extern const bn::tile limit_bn_gfxTiles[1];

#define limit_bn_gfxPalLen 32
extern const bn::color limit_bn_gfxPal[16];

#endif // GRIT_LIMIT_BN_GFX_H

//}}BLOCK(limit_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item limit(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(limit_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(limit_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

