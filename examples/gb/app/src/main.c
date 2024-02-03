#include <gb/gb.h>
#include <stdint.h>
#include "../res/dungeon_map.h"
#include "../res/dungeon_tiles.h"
#include "../res/game_tiles.h"
#include "../res/test_map.h"


void init_gfx(void) {
    // Load Background tiles and then map
    set_bkg_data(0, 5, GAME_TILES);
    set_bkg_tiles(0, 0, 20, 54, TEST_MAP);

	// Turn the background map on to make it visible
    SHOW_BKG;
}


void main(void)
{
	init_gfx();

    // Loop forever
    while(1) {


		// Game main loop processing goes here


		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}
