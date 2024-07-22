#include <gb/gb.h>
#include <gb/metasprites.h>
#include <stdint.h>
#include <stdio.h>
#include <rand.h>
#include "player.h"
#include "world.h"
#include "../res/map_tiles.h"
#include "../res/sprite_tiles.h"
#include "../res/base_map.h"

void vblankInterruptCallback(){

}

void init_gfx(void) {
    disable_interrupts();
    DISPLAY_OFF;
    add_VBL(vblankInterruptCallback);
    // Load Background tiles and then map
    set_bkg_data(0, 5, map_tiles);
    set_bkg_tiles(0, 0, base_mapWidth, base_mapHeight, base_map);
    
	// Turn the background map on to make it visible
    SHOW_BKG;

    SPRITES_8x16;

    set_sprite_data(0,12,sprite_tiles);
    SHOW_SPRITES;


    DISPLAY_ON;
    enable_interrupts();
    set_interrupts(VBL_IFLAG);
}

void init_rng(){
    // // abuse user input for seed generation
    //     prinf("PRESS START");
         waitpad(J_START);
        uint16_t seed = LY_REG;
        seed |= (uint16_t)DIV_REG << 8;
        initrand(seed);
}

void moveAndResolveSupershots(){
    //for now randomly add a sheild tile


}

void moveAndCollideWithMap(){
    for(uint_fast8_t p=0;p<1;p++){
        processInput(p, joypad());
        movePlayer(p);
    }
    //move bullets
    //move monsters
}

void collideWithEachOther(){

}

void draw(){
    for(uint_fast8_t p=0;p<1;p++){
        drawPlayerSprite(p);
    }
}

void worldEaterBlast(){

}

int_fast16_t random_number(int_fast16_t min_num, int_fast16_t max_num)
{
    int_fast16_t result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

void main(void)
{
	init_gfx();
    init_rng();
    populateCollisionMap(base_map,base_mapWidth,base_mapHeight);
       
    uint_fast8_t startingSprite=0;

    playerPawns[0].sprite=0;
    playerPawns[0].facing=PF_UP;
    playerPawns[0].x=32<<SUBPIXEL_SCALE_SHIFT; playerPawns[0].y=128<<SUBPIXEL_SCALE_SHIFT;

    uint_fast32_t addShieldCounter=0;

    // Loop forever
    while(1) {
        addShieldCounter++;
        // printf("%d\n",addShieldCounter);
        if(addShieldCounter>100){
            putShieldAtRowCol(random_number(2, 30), random_number(2,18));
            addShieldCounter=0;
            // printf("added a thing");
        }

		// Game main loop processing goes here
        moveAndResolveSupershots();
        moveAndCollideWithMap();
        collideWithEachOther();
        draw();
        worldEaterBlast();
        
        setCameraToWorldXY(0,playerPawns[0].y-(SCREENHEIGHT_MIDDLE_WORLD));

        setBkgToCamera();
        
		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}
