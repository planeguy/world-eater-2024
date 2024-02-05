#include "world.h"
#include <gb/gb.h>
struct Camera camera;

void setBkgToCamera(){
    move_bkg(camera.x>>SUBPIXEL_SCALE_SHIFT, camera.y>>SUBPIXEL_SCALE_SHIFT);
}
void setCameraToWorldXY(int_fast16_t x, int_fast16_t y){
    int_fast16_t xUBound = (WORLDHEIGHT-(SCREENWIDTH<<SUBPIXEL_SCALE_SHIFT));
    int_fast16_t yUBound = (WORLDHEIGHT-(SCREENHEIGHT<<SUBPIXEL_SCALE_SHIFT));
    camera.x=(x>0)?((x<xUBound)?x:xUBound):0; 
    camera.y=(y>0)?((y<yUBound)?y:yUBound):0; 
}
uint_fast8_t viewXfomWorldX(int_fast16_t x){
    return (x-camera.x)>>SUBPIXEL_SCALE_SHIFT;
}
uint_fast8_t viewYfromWorldY(int_fast16_t y){
    return ((y-camera.y)>>SUBPIXEL_SCALE_SHIFT)+16;
}