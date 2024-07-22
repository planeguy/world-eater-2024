#include <stdint.h>
#include <stdio.h>
#include "player.h"
#include <gb/gb.h>
#include "world.h"

struct Player players[MAX_PLAYERS];
struct PlayerPawn playerPawns[MAX_PLAYERS];

const metasprite_t playerMetaspriteUp[] = {
    {.dx=-8,.dy=-8,.dtile=0,.props=S_PALETTE},
    {.dx=8,.dy=0,.dtile=2,.props=S_PALETTE},
    METASPR_TERM
};

const metasprite_t playerMetaspriteRt[] = {
    {.dx=-8,.dy=-8,.dtile=4,.props=S_PALETTE},
    {.dx=8,.dy=0,.dtile=6,.props=S_PALETTE},
    METASPR_TERM
};

const metasprite_t playerMetaspriteUpRt[]={
    {.dx=-8,.dy=-8,.dtile=8,.props=S_PALETTE},
    {.dx=8,.dy=0,.dtile=10,.props=S_PALETTE},
    METASPR_TERM
};

void processInput(uint_fast8_t p, uint_fast8_t input){
    //reset player movement
    playerPawns[p].dx=0;
    playerPawns[p].dy=0;

    //set player intended direction for processing against the map, etc.
    if (input & J_UP && input & J_RIGHT){
        playerPawns[p].dy=-PLAYER_SPEED_DIAGONAL;
        playerPawns[p].dx=PLAYER_SPEED_DIAGONAL;
        playerPawns[p].facing=PF_UPRT;
    } else if (input & J_UP && input & J_LEFT){
        playerPawns[p].dy=-PLAYER_SPEED_DIAGONAL;
        playerPawns[p].dx=-PLAYER_SPEED_DIAGONAL;
        playerPawns[p].facing=PF_UPLT;
    } else if (input & J_DOWN && input & J_RIGHT){
        playerPawns[p].dy=PLAYER_SPEED_DIAGONAL;
        playerPawns[p].dx=PLAYER_SPEED_DIAGONAL;
        playerPawns[p].facing=PF_DNRT;
    } else if (input & J_DOWN && input & J_LEFT){
        playerPawns[p].dy=PLAYER_SPEED_DIAGONAL;
        playerPawns[p].dx=-PLAYER_SPEED_DIAGONAL;
        playerPawns[p].facing=PF_DNLT;
    } else if(input&J_UP){
        playerPawns[p].dy=-PLAYER_SPEED_ORTHOGONAL;
        playerPawns[p].facing=PF_UP;
    } else if(input&J_RIGHT){
        playerPawns[p].dx=PLAYER_SPEED_ORTHOGONAL;
        playerPawns[p].facing=PF_RT;
    } else if(input&J_LEFT){
        playerPawns[p].dx=-PLAYER_SPEED_ORTHOGONAL;
        playerPawns[p].facing=PF_LT;
    } else if(input&J_DOWN){
        playerPawns[p].dy=PLAYER_SPEED_ORTHOGONAL;
        playerPawns[p].facing=PF_DN;
    }
}

void playerToXY(uint_fast8_t p, int_fast16_t x, int_fast16_t y){
    playerPawns[p].x=x;
    playerPawns[p].y=y;
}

void movePlayer(uint_fast8_t p){
    uint_fast16_t intox, intoy, x, y;
    enum PlayerFacing facing;
    intox=playerPawns[p].x+playerPawns[p].dx;
    intoy=playerPawns[p].y+playerPawns[p].dy;
    x=playerPawns[p].x;
    y=playerPawns[p].y;
    facing=playerPawns[p].facing;

    //printf("%u,%u", intox,intoy);

    //check collision against the map
    // if(isShieldAtXY(intox, y)<1) playerPawns[p].x=intox;
    // if(isShieldAtXY(x,intoy)<1) playerPawns[p].y=intoy;

    if(
        playerPawns[p].dy<0 
        && !isWorldSolidAtXY(intox-SHIFTED_SHIP_GIRTH,intoy-SHIFTED_SHIP_GIRTH) 
        && !isWorldSolidAtXY(intox,intoy-SHIFTED_SHIP_GIRTH)
        && !isWorldSolidAtXY(intox+SHIFTED_SHIP_GIRTH,intoy-SHIFTED_SHIP_GIRTH)
    ) playerPawns[p].y=intoy;

    if(
        playerPawns[p].dy>0
        && !isWorldSolidAtXY(intox-SHIFTED_SHIP_GIRTH,intoy+SHIFTED_SHIP_GIRTH) 
        && !isWorldSolidAtXY(intox,intoy+SHIFTED_SHIP_GIRTH) 
        && !isWorldSolidAtXY(intox+SHIFTED_SHIP_GIRTH,intoy+SHIFTED_SHIP_GIRTH)
    ) playerPawns[p].y=intoy;

    if(
        playerPawns[p].dx<0
        && !isWorldSolidAtXY(intox-SHIFTED_SHIP_GIRTH,intoy-SHIFTED_SHIP_GIRTH) 
        && !isWorldSolidAtXY(intox-SHIFTED_SHIP_GIRTH,intoy) 
        && !isWorldSolidAtXY(intox-SHIFTED_SHIP_GIRTH,intoy+SHIFTED_SHIP_GIRTH)
    ) playerPawns[p].x=intox;

    if(
        playerPawns[p].dx>0
        && !isWorldSolidAtXY(intox+SHIFTED_SHIP_GIRTH,intoy-SHIFTED_SHIP_GIRTH) 
        && !isWorldSolidAtXY(intox+SHIFTED_SHIP_GIRTH,intoy) 
        && !isWorldSolidAtXY(intox+SHIFTED_SHIP_GIRTH,intoy+SHIFTED_SHIP_GIRTH)
    ) playerPawns[p].x=intox;

    playerPawns[p].dx=0; playerPawns[p].dy=0;
}

void drawPlayerSprite(uint_fast8_t p){
    switch(playerPawns[p].facing){
        case PF_UP:
            move_metasprite_ex(playerMetaspriteUp, 0, 0, 0,viewXfromWorldX(playerPawns[p].x), viewYfromWorldY(playerPawns[p].y));
        break;
        case PF_RT:
            move_metasprite_ex(playerMetaspriteRt, 0, 0, 0,viewXfromWorldX(playerPawns[p].x), viewYfromWorldY(playerPawns[p].y));
        break;
        case PF_DN:
            move_metasprite_flipy(playerMetaspriteUp, 0, 0, 0,viewXfromWorldX(playerPawns[p].x), viewYfromWorldY(playerPawns[p].y));
        break;
        case PF_LT:
            move_metasprite_flipx(playerMetaspriteRt, 0, 0, 0,viewXfromWorldX(playerPawns[p].x), viewYfromWorldY(playerPawns[p].y));
        break;
        case PF_UPRT:
            move_metasprite_ex(playerMetaspriteUpRt, 0, 0, 0,viewXfromWorldX(playerPawns[p].x), viewYfromWorldY(playerPawns[p].y));
        break;
        case PF_UPLT:
            move_metasprite_flipx(playerMetaspriteUpRt, 0, 0, 0,viewXfromWorldX(playerPawns[p].x), viewYfromWorldY(playerPawns[p].y));
        break;
        case PF_DNRT:
            move_metasprite_flipy(playerMetaspriteUpRt, 0, 0, 0,viewXfromWorldX(playerPawns[p].x), viewYfromWorldY(playerPawns[p].y));
        break;
        case PF_DNLT:
            move_metasprite_flipxy(playerMetaspriteUpRt, 0, 0, 0,viewXfromWorldX(playerPawns[p].x), viewYfromWorldY(playerPawns[p].y));
        break;
    }
}
