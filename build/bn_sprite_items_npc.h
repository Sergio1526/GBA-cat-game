#ifndef BN_SPRITE_ITEMS_NPC_H
#define BN_SPRITE_ITEMS_NPC_H

#include "bn_sprite_item.h"

//{{BLOCK(npc_bn_gfx)

//======================================================================
//
//	npc_bn_gfx, 16x256@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2024-08-21, 10:51:17
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_NPC_BN_GFX_H
#define GRIT_NPC_BN_GFX_H

#define npc_bn_gfxTilesLen 2048
extern const bn::tile npc_bn_gfxTiles[64];

#define npc_bn_gfxPalLen 32
extern const bn::color npc_bn_gfxPal[16];

#endif // GRIT_NPC_BN_GFX_H

//}}BLOCK(npc_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item npc(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(npc_bn_gfxTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 16), 
            sprite_palette_item(span<const color>(npc_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

