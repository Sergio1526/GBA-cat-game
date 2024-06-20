#ifndef BN_REGULAR_BG_ITEMS_CATS_INTRO_H
#define BN_REGULAR_BG_ITEMS_CATS_INTRO_H

#include "bn_regular_bg_item.h"

//{{BLOCK(cats_intro_bn_gfx)

//======================================================================
//
//	cats_intro_bn_gfx, 512x512@8, 
//	+ palette 32 entries, not compressed
//	+ 717 tiles (t|f reduced) lz77 compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 64 + 13548 + 8192 = 21804
//
//	Time-stamp: 2024-06-20, 15:51:41
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CATS_INTRO_BN_GFX_H
#define GRIT_CATS_INTRO_BN_GFX_H

#define cats_intro_bn_gfxTilesLen 13548
extern const bn::tile cats_intro_bn_gfxTiles[1434];

#define cats_intro_bn_gfxMapLen 8192
extern const bn::regular_bg_map_cell cats_intro_bn_gfxMap[4096];

#define cats_intro_bn_gfxPalLen 64
extern const bn::color cats_intro_bn_gfxPal[32];

#endif // GRIT_CATS_INTRO_BN_GFX_H

//}}BLOCK(cats_intro_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item cats_intro(
            regular_bg_tiles_item(span<const tile>(cats_intro_bn_gfxTiles, 1434), bpp_mode::BPP_8, compression_type::LZ77), 
            bg_palette_item(span<const color>(cats_intro_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(cats_intro_bn_gfxMap[0], size(64, 64), compression_type::NONE, 1, false));
}

#endif

