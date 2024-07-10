#ifndef BN_REGULAR_BG_ITEMS_SIMPLE_BG_H
#define BN_REGULAR_BG_ITEMS_SIMPLE_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(simple_bg_bn_gfx)

//======================================================================
//
//	simple_bg_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 58 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 1856 + 2048 = 3936
//
//	Time-stamp: 2024-07-09, 20:58:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SIMPLE_BG_BN_GFX_H
#define GRIT_SIMPLE_BG_BN_GFX_H

#define simple_bg_bn_gfxTilesLen 1856
extern const bn::tile simple_bg_bn_gfxTiles[58];

#define simple_bg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell simple_bg_bn_gfxMap[1024];

#define simple_bg_bn_gfxPalLen 32
extern const bn::color simple_bg_bn_gfxPal[16];

#endif // GRIT_SIMPLE_BG_BN_GFX_H

//}}BLOCK(simple_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item simple_bg(
            regular_bg_tiles_item(span<const tile>(simple_bg_bn_gfxTiles, 58), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(simple_bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(simple_bg_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

