#include <stdint.h>
#include "player.h"
#include "field.h"
#include <gb/gb.h>
#include "world.h"

struct Player players[MAX_PLAYERS];
struct PlayerPawn playerPawns[MAX_PLAYERS];

const metasprite_t playerMetaspriteUp[] = {
    {.dx=-8,.dy=-8,.dtile=0,.props=S_PALETTE},
    {.dx=8,.dy=0,.dtile=2,.props=S_PALETTE},
    {.dx=-8,.dy=8,.dtile=1,.props=S_PALETTE},
    {.dx=8,.dy=0,.dtile=3,.props=S_PALETTE},
    METASPR_TERM
};

const metasprite_t playerMetaspriteRt[] = {
    {.dx=-8,.dy=-8,.dtile=4,.props=S_PALETTE},
    {.dx=8,.dy=0,.dtile=6,.props=S_PALETTE},
    {.dx=-8,.dy=8,.dtile=5,.props=S_PALETTE},
    {.dx=8,.dy=0,.dtile=7,.props=S_PALETTE},
    METASPR_TERM
};

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

void updatePlayerPosition(uint_fast8_t p){
    int_fast16_t intox, intoy;
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

void drawPlayerSprite(uint_fast8_t p){
    switch(playerPawns[p].facing){
        case PF_UP:
            move_metasprite_ex(playerMetaspriteUp, 0, 0, 0,playerPawns[p].x>>SUBPIXEL_SCALE_SHIFT, viewYfromWorldY(playerPawns[p].y));
        break;
        case PF_RT:
            move_metasprite_ex(playerMetaspriteRt, 0, 0, 0,playerPawns[p].x>>SUBPIXEL_SCALE_SHIFT, viewYfromWorldY(playerPawns[p].y));
        break;
        case PF_DN:
            move_metasprite_flipy(playerMetaspriteUp, 0, 0, 0,playerPawns[p].x>>SUBPIXEL_SCALE_SHIFT, viewYfromWorldY(playerPawns[p].y));
        break;
        case PF_LT:
            move_metasprite_flipx(playerMetaspriteRt, 0, 0, 0,playerPawns[p].x>>SUBPIXEL_SCALE_SHIFT, viewYfromWorldY(playerPawns[p].y));
        break;
    }
}

void updatePlayers(uint_fast8_t tick){
    for(uint_fast8_t p=0;p<1;p++){
        processInput(p);
        updatePlayerPosition(p);
        drawPlayerSprite(p);
    }
}