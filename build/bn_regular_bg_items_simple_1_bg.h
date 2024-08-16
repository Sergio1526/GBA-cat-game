#ifndef BN_REGULAR_BG_ITEMS_SIMPLE_1_BG_H
#define BN_REGULAR_BG_ITEMS_SIMPLE_1_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(simple_1_bg_bn_gfx)

//======================================================================
//
//	simple_1_bg_bn_gfx, 512x512@4, 
//	+ palette 16 entries, not compressed
//	+ 120 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 32 + 3840 + 8192 = 12064
//
//	Time-stamp: 2024-08-16, 13:22:18
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SIMPLE_1_BG_BN_GFX_H
#define GRIT_SIMPLE_1_BG_BN_GFX_H

#define simple_1_bg_bn_gfxTilesLen 3840
extern const bn::tile simple_1_bg_bn_gfxTiles[120];

#define simple_1_bg_bn_gfxMapLen 8192
extern const bn::regular_bg_map_cell simple_1_bg_bn_gfxMap[4096];

#define simple_1_bg_bn_gfxPalLen 32
extern const bn::color simple_1_bg_bn_gfxPal[16];

#endif // GRIT_SIMPLE_1_BG_BN_GFX_H

//}}BLOCK(simple_1_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item simple_1_bg(
            regular_bg_tiles_item(span<const tile>(simple_1_bg_bn_gfxTiles, 120), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(simple_1_bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(simple_1_bg_bn_gfxMap[0], size(64, 64), compression_type::NONE, 1, false));
}

#endif

