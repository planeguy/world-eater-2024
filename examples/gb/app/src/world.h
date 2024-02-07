#pragma once
#include <stdint.h>
#include <gb/gb.h>
#include "../res/test_map.h"

#define SUBPIXEL_SCALE_SHIFT 4
#define GRID_NODE_SHIFT 3

#define SCREENHEIGHT_MIDDLE_WORLD ((SCREENHEIGHT/2)<<SUBPIXEL_SCALE_SHIFT)

#define WORLDWIDTH (TEST_MAPWidth<<GRID_NODE_SHIFT<<SUBPIXEL_SCALE_SHIFT)
#define WORLDHEIGHT (TEST_MAPHeight<<GRID_NODE_SHIFT<<SUBPIXEL_SCALE_SHIFT)

#define MAP_TILE_LOCATION 0x9800

struct Camera {
    int_fast16_t x, y;
};

extern struct Camera camera;

void setBkgToCamera();
void setCameraToWorldXY(int_fast16_t x, int_fast16_t y);
uint_fast8_t viewXfromWorldX(int_fast16_t x);
uint_fast8_t viewYfromWorldY(int_fast16_t y);

uint_fast8_t tileTypeAtXY(int_fast16_t x, int_fast16_t y);