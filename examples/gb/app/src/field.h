#pragma once 
#include <stdint.h>
#include <gb/gb.h>

#define FIELD_WIDTH SCREENWIDTH
#define FIELD_HEIGHT 2*SCREENHEIGHT

#define FIELD_TILE_WIDTH FIELD_WIDTH/8
#define FIELD_TILE_HEIGHT FIELD_HEIGHT/8

int_fast8_t getMapTileCollisionAt(int_fast8_t x, int_fast8_t y);

void followCameraTo(int_fast16_t y);