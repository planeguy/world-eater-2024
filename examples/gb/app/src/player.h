#pragma once
#include <stdint.h>

//player controller; for input and replication in vs play
struct Player{
    uint_fast8_t input;
    uint_fast8_t torpedoPower;
    uint_fast8_t score;
    uint_fast8_t shot; //index of shot sprite
};

enum playerFacing{PF_UP,PF_RT,PF_DN,PF_LT};
struct PlayerPawn{
    enum playerFacing facing;
    uint_fast8_t sprite;
    int_fast16_t x, y;
    int_fast16_t dx, dy;
};
#define PLAYER_FIRST_TILE 0

#define MAX_PLAYERS 4
extern struct Player players[MAX_PLAYERS];
extern struct PlayerPawn playerPawns[MAX_PLAYERS];

#define PLAYER_SPEED 17;
void updatePlayers(uint_fast8_t tick);