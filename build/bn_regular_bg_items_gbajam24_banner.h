#ifndef BN_REGULAR_BG_ITEMS_GBAJAM24_BANNER_H
#define BN_REGULAR_BG_ITEMS_GBAJAM24_BANNER_H

#include "bn_regular_bg_item.h"

//{{BLOCK(gbajam24_banner_bn_gfx)

//======================================================================
//
//	gbajam24_banner_bn_gfx, 1024x256@4, 
//	+ palette 16 entries, not compressed
//	+ 783 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 128x32 
//	Total size: 32 + 25056 + 8192 = 33280
//
//	Time-stamp: 2024-07-24, 10:38:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GBAJAM24_BANNER_BN_GFX_H
#define GRIT_GBAJAM24_BANNER_BN_GFX_H

#define gbajam24_banner_bn_gfxTilesLen 25056
extern const bn::tile gbajam24_banner_bn_gfxTiles[783];

#define gbajam24_banner_bn_gfxMapLen 8192
extern const bn::regular_bg_map_cell gbajam24_banner_bn_gfxMap[4096];

#define gbajam24_banner_bn_gfxPalLen 32
extern const bn::color gbajam24_banner_bn_gfxPal[16];

#endif // GRIT_GBAJAM24_BANNER_BN_GFX_H

//}}BLOCK(gbajam24_banner_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item gbajam24_banner(
            regular_bg_tiles_item(span<const tile>(gbajam24_banner_bn_gfxTiles, 783), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(gbajam24_banner_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(gbajam24_banner_bn_gfxMap[0], size(128, 32), compression_type::NONE, 1, true));
}

#endif

