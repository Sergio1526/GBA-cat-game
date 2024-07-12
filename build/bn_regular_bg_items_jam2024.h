#ifndef BN_REGULAR_BG_ITEMS_JAM2024_H
#define BN_REGULAR_BG_ITEMS_JAM2024_H

#include "bn_regular_bg_item.h"

//{{BLOCK(jam2024_bn_gfx)

//======================================================================
//
//	jam2024_bn_gfx, 256x256@8, 
//	+ palette 64 entries, not compressed
//	+ 345 tiles (t|f reduced) lz77 compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 128 + 6552 + 2048 = 8728
//
//	Time-stamp: 2024-07-12, 10:19:24
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_JAM2024_BN_GFX_H
#define GRIT_JAM2024_BN_GFX_H

#define jam2024_bn_gfxTilesLen 6552
extern const bn::tile jam2024_bn_gfxTiles[690];

#define jam2024_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell jam2024_bn_gfxMap[1024];

#define jam2024_bn_gfxPalLen 128
extern const bn::color jam2024_bn_gfxPal[64];

#endif // GRIT_JAM2024_BN_GFX_H

//}}BLOCK(jam2024_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item jam2024(
            regular_bg_tiles_item(span<const tile>(jam2024_bn_gfxTiles, 690), bpp_mode::BPP_8, compression_type::LZ77), 
            bg_palette_item(span<const color>(jam2024_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(jam2024_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

