#include <gb/gb.h>
#include <gb/metasprites.h>
#include <stdint.h>
#include "player.h"
#include "world.h"
#include "field.h"
#include "../res/map_tiles.h"
#include "../res/player_tiles.h"
#include "../res/sprite_tiles.h"
#include "../res/test_map.h"


void init_gfx(void) {
    // Load Background tiles and then map
    set_bkg_data(0, 5, map_tiles);
    set_bkg_tiles(0, 0, TEST_MAPWidth, TEST_MAPHeight, TEST_MAP);

	// Turn the background map on to make it visible
    SHOW_BKG;

    SPRITES_8x8;

    
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

        players[0].input=joypad();
        updatePlayers(0);

        setCameraToWorldXY(0,playerPawns[0].y-(SCREENHEIGHT_MIDDLE_WORLD));

        setBkgToCamera();
        
        

        // move_sprite(
        //     playerPawns[0].sprite,
        //     (playerPawns[0].x>>SUBPIXEL_SCALE_SHIFT),
        //     (viewYfromWorldY(playerPawns[0].y))
        // );

		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}
