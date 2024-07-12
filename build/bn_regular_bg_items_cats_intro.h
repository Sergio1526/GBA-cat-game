#ifndef BN_REGULAR_BG_ITEMS_CATS_INTRO_H
#define BN_REGULAR_BG_ITEMS_CATS_INTRO_H

#include "bn_regular_bg_item.h"

//{{BLOCK(cats_intro_bn_gfx)

//======================================================================
//
//	cats_intro_bn_gfx, 256x256@8, 
//	+ palette 64 entries, not compressed
//	+ 914 tiles (t|f reduced) lz77 compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 128 + 24936 + 2048 = 27112
//
//	Time-stamp: 2024-07-12, 10:19:24
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CATS_INTRO_BN_GFX_H
#define GRIT_CATS_INTRO_BN_GFX_H

#define cats_intro_bn_gfxTilesLen 24936
extern const bn::tile cats_intro_bn_gfxTiles[1828];

#define cats_intro_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell cats_intro_bn_gfxMap[1024];

#define cats_intro_bn_gfxPalLen 128
extern const bn::color cats_intro_bn_gfxPal[64];

#endif // GRIT_CATS_INTRO_BN_GFX_H

//}}BLOCK(cats_intro_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item cats_intro(
            regular_bg_tiles_item(span<const tile>(cats_intro_bn_gfxTiles, 1828), bpp_mode::BPP_8, compression_type::LZ77), 
            bg_palette_item(span<const color>(cats_intro_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(cats_intro_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

