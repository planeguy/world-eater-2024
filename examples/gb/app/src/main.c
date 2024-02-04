#include <gb/gb.h>
#include <stdint.h>
#include "player.h"
#include "world.h"
#include "../res/map_tiles.h"
#include "../res/player_tiles.h"
#include "../res/test_map.h"


void init_gfx(void) {
    // Load Background tiles and then map
    set_bkg_data(0, 5, map_tiles);
    set_bkg_tiles(0, 0, TEST_MAPWidth, TEST_MAPHeight, TEST_MAP);

	// Turn the background map on to make it visible
    SHOW_BKG;

    set_sprite_data(0,4,player_tiles);
    playerPawns[0].sprite=0;
    set_sprite_tile(playerPawns[0].sprite,0);
    playerPawns[0].facing=PF_UP;
    playerPawns[0].x=0<<SUBPIXEL_SCALE_SHIFT; playerPawns[0].y=0<<SUBPIXEL_SCALE_SHIFT;
    SHOW_SPRITES;
}


void main(void)
{
	init_gfx();

    move_bkg(0,0);
    scroll_bkg(0,0);

    // Loop forever
    while(1) {


		// Game main loop processing goes here

        players[0].input=joypad();
        updatePlayers(0);

		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}
