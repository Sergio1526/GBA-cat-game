#ifndef BN_REGULAR_BG_ITEMS_CLOUDS_H
#define BN_REGULAR_BG_ITEMS_CLOUDS_H

#include "bn_regular_bg_item.h"

//{{BLOCK(clouds_bn_gfx)

//======================================================================
//
//	clouds_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 95 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 3040 + 2048 = 5120
//
//	Time-stamp: 2024-08-21, 22:15:08
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CLOUDS_BN_GFX_H
#define GRIT_CLOUDS_BN_GFX_H

#define clouds_bn_gfxTilesLen 3040
extern const bn::tile clouds_bn_gfxTiles[95];

#define clouds_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell clouds_bn_gfxMap[1024];

#define clouds_bn_gfxPalLen 32
extern const bn::color clouds_bn_gfxPal[16];

#endif // GRIT_CLOUDS_BN_GFX_H

//}}BLOCK(clouds_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item clouds(
            regular_bg_tiles_item(span<const tile>(clouds_bn_gfxTiles, 95), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(clouds_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(clouds_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

