#ifndef BN_REGULAR_BG_ITEMS_MINIGAME1_H
#define BN_REGULAR_BG_ITEMS_MINIGAME1_H

#include "bn_regular_bg_item.h"

//{{BLOCK(minigame1_bn_gfx)

//======================================================================
//
//	minigame1_bn_gfx, 256x256@8, 
//	+ palette 64 entries, not compressed
//	+ 333 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 128 + 21312 + 2048 = 23488
//
//	Time-stamp: 2024-08-21, 16:53:18
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MINIGAME1_BN_GFX_H
#define GRIT_MINIGAME1_BN_GFX_H

#define minigame1_bn_gfxTilesLen 21312
extern const bn::tile minigame1_bn_gfxTiles[666];

#define minigame1_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell minigame1_bn_gfxMap[1024];

#define minigame1_bn_gfxPalLen 128
extern const bn::color minigame1_bn_gfxPal[64];

#endif // GRIT_MINIGAME1_BN_GFX_H

//}}BLOCK(minigame1_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item minigame1(
            regular_bg_tiles_item(span<const tile>(minigame1_bn_gfxTiles, 666), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(minigame1_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(minigame1_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

