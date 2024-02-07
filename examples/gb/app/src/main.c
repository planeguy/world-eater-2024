#include <gb/gb.h>
#include <gb/metasprites.h>
#include <stdint.h>
#include "player.h"
#include "world.h"
#include "../res/map_tiles.h"
#include "../res/player_tiles.h"
#include "../res/sprite_tiles.h"
#include "../res/base_map.h"


void init_gfx(void) {
    // Load Background tiles and then map
    set_bkg_data(0, 5, map_tiles);
    set_bkg_tiles(0, 0, base_mapWidth, base_map, base_map);

	// Turn the background map on to make it visible
    SHOW_BKG;

    SPRITES_8x16;

    
    set_sprite_data(0,8,sprite_tiles);
    SHOW_SPRITES;
}


void main(void)
{
	init_gfx();
    
    uint_fast8_t startingSprite=0;

    playerPawns[0].sprite=0;
    playerPawns[0].facing=PF_UP;
    playerPawns[0].x=8<<SUBPIXEL_SCALE_SHIFT; playerPawns[0].y=16<<SUBPIXEL_SCALE_SHIFT;

    // Loop forever
    while(1) {


		// Game main loop processing goes here

        for(uint_fast8_t p=0;p<1;p++){
            players[p].input=joypad();
            updatePlayer(p);
        }
        setCameraToWorldXY(0,playerPawns[0].y-(SCREENHEIGHT_MIDDLE_WORLD));

        setBkgToCamera();
        
		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}
