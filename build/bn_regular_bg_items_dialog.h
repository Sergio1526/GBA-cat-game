#ifndef BN_REGULAR_BG_ITEMS_DIALOG_H
#define BN_REGULAR_BG_ITEMS_DIALOG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(dialog_bn_gfx)

//======================================================================
//
//	dialog_bn_gfx, 256x256@8, 
//	+ palette 64 entries, not compressed
//	+ 13 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 128 + 832 + 2048 = 3008
//
//	Time-stamp: 2024-08-14, 09:04:42
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_DIALOG_BN_GFX_H
#define GRIT_DIALOG_BN_GFX_H

#define dialog_bn_gfxTilesLen 832
extern const bn::tile dialog_bn_gfxTiles[26];

#define dialog_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell dialog_bn_gfxMap[1024];

#define dialog_bn_gfxPalLen 128
extern const bn::color dialog_bn_gfxPal[64];

#endif // GRIT_DIALOG_BN_GFX_H

//}}BLOCK(dialog_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item dialog(
            regular_bg_tiles_item(span<const tile>(dialog_bn_gfxTiles, 26), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(dialog_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(dialog_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

