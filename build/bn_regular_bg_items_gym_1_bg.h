#ifndef BN_REGULAR_BG_ITEMS_GYM_1_BG_H
#define BN_REGULAR_BG_ITEMS_GYM_1_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(gym_1_bg_bn_gfx)

//======================================================================
//
//	gym_1_bg_bn_gfx, 512x512@4, 
//	+ palette 16 entries, not compressed
//	+ 22 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 32 + 704 + 8192 = 8928
//
//	Time-stamp: 2024-08-21, 10:51:16
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GYM_1_BG_BN_GFX_H
#define GRIT_GYM_1_BG_BN_GFX_H

#define gym_1_bg_bn_gfxTilesLen 704
extern const bn::tile gym_1_bg_bn_gfxTiles[22];

#define gym_1_bg_bn_gfxMapLen 8192
extern const bn::regular_bg_map_cell gym_1_bg_bn_gfxMap[4096];

#define gym_1_bg_bn_gfxPalLen 32
extern const bn::color gym_1_bg_bn_gfxPal[16];

#endif // GRIT_GYM_1_BG_BN_GFX_H

//}}BLOCK(gym_1_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item gym_1_bg(
            regular_bg_tiles_item(span<const tile>(gym_1_bg_bn_gfxTiles, 22), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(gym_1_bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(gym_1_bg_bn_gfxMap[0], size(64, 64), compression_type::NONE, 1, false));
}

#endif

