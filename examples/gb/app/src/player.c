#include <stdint.h>
#include "player.h"
#include "field.h"
#include <gb/gb.h>
#include "world.h"

struct Player players[MAX_PLAYERS];
struct PlayerPawn playerPawns[MAX_PLAYERS];

void processInput(uint_fast8_t p){
    //reset player movement
    playerPawns[p].dx=0;
    playerPawns[p].dy=0;

    //set player intended direction for processing against the map, etc.
    if(players[p].input&J_UP){
        playerPawns[p].dy=-PLAYER_SPEED;
        playerPawns[p].facing=PF_UP;
    } else if(players[p].input&J_RIGHT){
        playerPawns[p].dx=PLAYER_SPEED;
        playerPawns[p].facing=PF_RT;
    } else if(players[p].input&J_LEFT){
        playerPawns[p].dx=-PLAYER_SPEED;
        playerPawns[p].facing=PF_LT;
    } else if(players[p].input&J_DOWN){
        playerPawns[p].dy=PLAYER_SPEED;
        playerPawns[p].facing=PF_DN;
    }
}

void setPlayerSpriteTile(uint_fast8_t p){
    set_sprite_tile(playerPawns[p].sprite,playerPawns[p].facing);
}

void updatePlayerPosition(uint_fast8_t p){
    int_fast8_t intox, intoy;
    intox=playerPawns[p].x+playerPawns[p].dx;
    intoy=playerPawns[p].y+playerPawns[p].dy;

    //check collision against the map
    if(getMapTileCollisionAt(intox>>SUBPIXEL_SCALE_SHIFT,intoy>>SUBPIXEL_SCALE_SHIFT)>=0){
        //do not move into solid tiles
        return;
    }
    //check collision against other sprites
    //update x and y
    playerPawns[p].x=intox;
    playerPawns[p].y=intoy;
}

void updatePlayers(uint_fast8_t tick){
    for(uint_fast8_t p=0;p<1;p++){
        processInput(p);
        setPlayerSpriteTile(p);
        updatePlayerPosition(p);
        move_sprite(
            playerPawns[p].sprite,
            (playerPawns[p].x>>SUBPIXEL_SCALE_SHIFT),
            (playerPawns[p].y>>SUBPIXEL_SCALE_SHIFT)
        );
    }
}