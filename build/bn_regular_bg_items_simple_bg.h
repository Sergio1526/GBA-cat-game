#ifndef BN_REGULAR_BG_ITEMS_SIMPLE_BG_H
#define BN_REGULAR_BG_ITEMS_SIMPLE_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(simple_bg_bn_gfx)

//======================================================================
//
//	simple_bg_bn_gfx, 256x256@8, 
//	+ palette 192 entries, not compressed
//	+ 25 tiles (t|f reduced) rle compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 384 + 172 + 2048 = 2604
//
//	Time-stamp: 2024-06-17, 12:11:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SIMPLE_BG_BN_GFX_H
#define GRIT_SIMPLE_BG_BN_GFX_H

#define simple_bg_bn_gfxTilesLen 172
extern const bn::tile simple_bg_bn_gfxTiles[50];

#define simple_bg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell simple_bg_bn_gfxMap[1024];

#define simple_bg_bn_gfxPalLen 384
extern const bn::color simple_bg_bn_gfxPal[192];

#endif // GRIT_SIMPLE_BG_BN_GFX_H

//}}BLOCK(simple_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item simple_bg(
            regular_bg_tiles_item(span<const tile>(simple_bg_bn_gfxTiles, 50), bpp_mode::BPP_8, compression_type::RUN_LENGTH), 
            bg_palette_item(span<const color>(simple_bg_bn_gfxPal, 192), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(simple_bg_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

