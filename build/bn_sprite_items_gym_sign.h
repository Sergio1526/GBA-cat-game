#ifndef BN_SPRITE_ITEMS_GYM_SIGN_H
#define BN_SPRITE_ITEMS_GYM_SIGN_H

#include "bn_sprite_item.h"

//{{BLOCK(gym_sign_bn_gfx)

//======================================================================
//
//	gym_sign_bn_gfx, 32x96@8, 
//	+ palette 64 entries, not compressed
//	+ 48 tiles not compressed
//	Total size: 128 + 3072 = 3200
//
//	Time-stamp: 2024-08-16, 16:15:55
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GYM_SIGN_BN_GFX_H
#define GRIT_GYM_SIGN_BN_GFX_H

#define gym_sign_bn_gfxTilesLen 3072
extern const bn::tile gym_sign_bn_gfxTiles[96];

#define gym_sign_bn_gfxPalLen 128
extern const bn::color gym_sign_bn_gfxPal[64];

#endif // GRIT_GYM_SIGN_BN_GFX_H

//}}BLOCK(gym_sign_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item gym_sign(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(gym_sign_bn_gfxTiles, 96), bpp_mode::BPP_8, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(gym_sign_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

