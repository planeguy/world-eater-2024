#pragma once
#include <stdint.h>
#include <gb/gb.h>

#define SUBPIXEL_SCALE_SHIFT 4
#define SCREENHEIGHT_MIDDLE_WORLD ((SCREENHEIGHT/2)<<SUBPIXEL_SCALE_SHIFT)

struct Camera {
    int_fast16_t x, y;
};

extern struct Camera camera;

void setBkgToCamera();
void setCameraToWorldXY(int_fast16_t x, int_fast16_t y);
uint_fast8_t viewXfromWorldX(int_fast16_t x);
uint_fast8_t viewYfromWorldY(int_fast16_t y);