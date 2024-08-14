#ifndef BN_REGULAR_BG_ITEMS_CATS_INTRO_H
#define BN_REGULAR_BG_ITEMS_CATS_INTRO_H

#include "bn_regular_bg_item.h"

//{{BLOCK(cats_intro_bn_gfx)

//======================================================================
//
//	cats_intro_bn_gfx, 256x256@8, 
//	+ palette 64 entries, not compressed
//	+ 911 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 128 + 58304 + 2048 = 60480
//
//	Time-stamp: 2024-08-13, 18:42:34
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CATS_INTRO_BN_GFX_H
#define GRIT_CATS_INTRO_BN_GFX_H

#define cats_intro_bn_gfxTilesLen 58304
extern const bn::tile cats_intro_bn_gfxTiles[1822];

#define cats_intro_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell cats_intro_bn_gfxMap[1024];

#define cats_intro_bn_gfxPalLen 128
extern const bn::color cats_intro_bn_gfxPal[64];

#endif // GRIT_CATS_INTRO_BN_GFX_H

//}}BLOCK(cats_intro_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item cats_intro(
            regular_bg_tiles_item(span<const tile>(cats_intro_bn_gfxTiles, 1822), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(cats_intro_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(cats_intro_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

