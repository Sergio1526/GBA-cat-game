#ifndef BN_REGULAR_BG_ITEMS_SIMPLE_BG_H
#define BN_REGULAR_BG_ITEMS_SIMPLE_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(simple_bg_bn_gfx)

//======================================================================
//
//	simple_bg_bn_gfx, 512x512@4, 
//	+ palette 16 entries, not compressed
//	+ 11 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 32 + 352 + 8192 = 8576
//
//	Time-stamp: 2024-07-24, 12:10:59
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SIMPLE_BG_BN_GFX_H
#define GRIT_SIMPLE_BG_BN_GFX_H

#define simple_bg_bn_gfxTilesLen 352
extern const bn::tile simple_bg_bn_gfxTiles[11];

#define simple_bg_bn_gfxMapLen 8192
extern const bn::regular_bg_map_cell simple_bg_bn_gfxMap[4096];

#define simple_bg_bn_gfxPalLen 32
extern const bn::color simple_bg_bn_gfxPal[16];

#endif // GRIT_SIMPLE_BG_BN_GFX_H

//}}BLOCK(simple_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item simple_bg(
            regular_bg_tiles_item(span<const tile>(simple_bg_bn_gfxTiles, 11), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(simple_bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(simple_bg_bn_gfxMap[0], size(64, 64), compression_type::NONE, 1, false));
}

#endif

