#ifndef BN_REGULAR_BG_ITEMS_CAT_BODY_H
#define BN_REGULAR_BG_ITEMS_CAT_BODY_H

#include "bn_regular_bg_item.h"

//{{BLOCK(cat_body_bn_gfx)

//======================================================================
//
//	cat_body_bn_gfx, 256x256@8, 
//	+ palette 64 entries, not compressed
//	+ 241 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 128 + 15424 + 2048 = 17600
//
//	Time-stamp: 2024-08-13, 19:34:21
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CAT_BODY_BN_GFX_H
#define GRIT_CAT_BODY_BN_GFX_H

#define cat_body_bn_gfxTilesLen 15424
extern const bn::tile cat_body_bn_gfxTiles[482];

#define cat_body_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell cat_body_bn_gfxMap[1024];

#define cat_body_bn_gfxPalLen 128
extern const bn::color cat_body_bn_gfxPal[64];

#endif // GRIT_CAT_BODY_BN_GFX_H

//}}BLOCK(cat_body_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item cat_body(
            regular_bg_tiles_item(span<const tile>(cat_body_bn_gfxTiles, 482), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(cat_body_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(cat_body_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

