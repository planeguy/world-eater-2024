#include "world.h"
#include <gb/gb.h>
struct Camera camera;

void setBkgToCamera(){
    move_bkg(camera.x>>SUBPIXEL_SCALE_SHIFT, camera.y>>SUBPIXEL_SCALE_SHIFT);
}
void setCameraToWorldXY(int_fast16_t x, int_fast16_t y){
    camera.x=x; camera.y=y;
}
uint_fast8_t viewXfomWorldX(int_fast16_t x){
    return (x-camera.x)>>SUBPIXEL_SCALE_SHIFT;
}
uint_fast8_t viewYfromWorldY(int_fast16_t y){
    return ((y-camera.y)>>SUBPIXEL_SCALE_SHIFT)+16;
}