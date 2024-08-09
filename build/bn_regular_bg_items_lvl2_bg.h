#ifndef BN_REGULAR_BG_ITEMS_LVL2_BG_H
#define BN_REGULAR_BG_ITEMS_LVL2_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(lvl2_bg_bn_gfx)

//======================================================================
//
//	lvl2_bg_bn_gfx, 512x512@4, 
//	+ palette 16 entries, not compressed
//	+ 11 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 32 + 352 + 8192 = 8576
//
//	Time-stamp: 2024-08-08, 21:38:48
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LVL2_BG_BN_GFX_H
#define GRIT_LVL2_BG_BN_GFX_H

#define lvl2_bg_bn_gfxTilesLen 352
extern const bn::tile lvl2_bg_bn_gfxTiles[11];

#define lvl2_bg_bn_gfxMapLen 8192
extern const bn::regular_bg_map_cell lvl2_bg_bn_gfxMap[4096];

#define lvl2_bg_bn_gfxPalLen 32
extern const bn::color lvl2_bg_bn_gfxPal[16];

#endif // GRIT_LVL2_BG_BN_GFX_H

//}}BLOCK(lvl2_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item lvl2_bg(
            regular_bg_tiles_item(span<const tile>(lvl2_bg_bn_gfxTiles, 11), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(lvl2_bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(lvl2_bg_bn_gfxMap[0], size(64, 64), compression_type::NONE, 1, false));
}

#endif

