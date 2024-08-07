#pragma once
#include <stdint.h>
#include <gb/metasprites.h>

extern const metasprite_t playerMetaspriteUp[];
extern const metasprite_t playerMetaspriteRt[];
extern const metasprite_t playerMetaspriteUpRt[];
extern const metasprite_t playerShot[];

enum playerFacing{PF_UP,PF_UPRT,PF_RT,PF_DNRT, PF_DN, PF_DNLT, PF_LT, PF_UPLT};
extern const uint_fast16_t playerStartingXY[][2];

struct PlayerPawn{
    enum playerFacing facing;
    uint_fast16_t x, y;
    int_fast16_t dx, dy;
};

struct PlayerShot{
    uint_fast16_t x, y;
};

struct PlayerTorpedo{
    uint_fast8_t power;
    uint_fast16_t x, y;
};

//player controller; for input and replication in vs play
struct Player{
    uint_fast8_t input;
    uint_fast8_t score;
};

#define MAX_PLAYERS 4
extern struct Player players[MAX_PLAYERS];
extern struct PlayerPawn playerPawns[MAX_PLAYERS];
extern struct PlayerShot playerShots[MAX_PLAYERS];

#define PLAYER_SPEED_ORTHOGONAL 23
#define PLAYER_SPEED_DIAGONAL 16

#define SHIFTED_SHIP_GIRTH (6<<SUBPIXEL_SCALE_SHIFT)

void initPlayer(uint_fast8_t p);
void processInput(uint_fast8_t p, uint_fast8_t input);
void movePlayer(uint_fast8_t p);
uint_fast8_t drawPlayerSprites(uint_fast8_t p, uint_fast8_t hw_sprite);