#include "world.h"
#include <gb/gb.h>
#include "../res/test_map.h"
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

uint_fast8_t tileTypeAtXY(int_fast16_t x, int_fast16_t y){
    int_fast16_t column = x>>SUBPIXEL_SCALE_SHIFT>>GRID_NODE_SHIFT;
    int_fast16_t row = y>>SUBPIXEL_SCALE_SHIFT>>GRID_NODE_SHIFT;

    uint_fast16_t mapidx = column+(row*TEST_MAPWidth);

    uint_fast8_t* tile;
    get_bkg_tiles(x>>SUBPIXEL_SCALE_SHIFT, y>>SUBPIXEL_SCALE_SHIFT,1,1,tile);

    uint_fast8_t tileFromVRAM = *(uint_fast8_t*)(MAP_TILE_LOCATION+mapidx);
    //find the map tile in vram and return the value
    return tileFromVRAM;
}