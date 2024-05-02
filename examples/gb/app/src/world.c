#include "world.h"
#include <gb/gb.h>
#include "../res/base_map.h"
struct Camera camera;

MapChange_t pendingMapChanges[MAX_MAP_CHANGES];

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

    uint_fast16_t mapidx = column+(row*base_mapWidth);

    return base_map[mapidx];
}

void requestUpdateMapTiles(uint_fast8_t x, uint_fast8_t y, uint_fast8_t w, uint_fast8_t h, uint_fast8_t* tiles){
    //add request tot the queue
    uint_fast8_t next=0;
    while(pendingMapChanges[next].pending>0||next<MAX_MAP_CHANGES){
        next++;
    }
    if(next>=MAX_MAP_CHANGES) return;
    pendingMapChanges[next].pending=1;
    pendingMapChanges[next].x=x; pendingMapChanges[next].y=y;
    pendingMapChanges[next].w=w; pendingMapChanges[next].h=h;
    pendingMapChanges[next].tiles=tiles;
    //update the local version
}
void updateMapTiles(uint_fast8_t x, uint_fast8_t y, uint_fast8_t w, uint_fast8_t h, uint_fast8_t* tiles, uint_fast8_t* target){
    //update ram block
    
}