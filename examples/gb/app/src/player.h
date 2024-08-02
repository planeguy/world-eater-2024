#pragma once
#include <stdint.h>
#include <gb/metasprites.h>

extern const metasprite_t playerMetaspriteUp[];
extern const metasprite_t playerMetaspriteRt[];
extern const metasprite_t playerMetaspriteUpRt[];
extern const metasprite_t playerShot[];

//player controller; for input and replication in vs play
struct Player{
    uint_fast8_t input;
    uint_fast8_t torpedoPower;
    uint_fast8_t score;
    uint_fast8_t shot; //index of shot sprite
};

enum playerFacing{PF_UP,PF_UPRT,PF_RT,PF_DNRT, PF_DN, PF_DNLT, PF_LT, PF_UPLT};
struct PlayerPawn{
    enum playerFacing facing;
    uint_fast8_t sprite;
    uint_fast16_t x, y;
    int_fast16_t dx, dy;
};
#define PLAYER_FIRST_TILE 0

struct PlayerShot{
    uint_fast8_t sprite;
    uint_fast16_t x, y;
};

struct PlayerTorpedo{
    uint_fast8_t sprite;
    uint_fast16_t x, y;
}

#define MAX_PLAYERS 4
extern struct Player players[MAX_PLAYERS];
extern struct PlayerPawn playerPawns[MAX_PLAYERS];
extern struct PlayerShot playerShots[MAX_PLAYERS];

#define PLAYER_SPEED_ORTHOGONAL 23
#define PLAYER_SPEED_DIAGONAL 16

#define SHIFTED_SHIP_GIRTH (6<<SUBPIXEL_SCALE_SHIFT)

void processInput(uint_fast8_t p, uint_fast8_t input);
void playerToXY(uint_fast8_t p, int_fast16_t x, int_fast16_t y);
void movePlayer(uint_fast8_t p);
void drawPlayerSprite(uint_fast8_t p);