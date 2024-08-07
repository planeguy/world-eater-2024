#include "world.h"
#include <gb/gb.h>
#include "../res/base_map.h"
#include "../res/map_tiles.h"
#include <stdlib.h>
camera_t camera;
uint_fast8_t *collisionMap;
uint_fast16_t collisionMapHeight;
uint_fast16_t collisionMapWidth;

void setBkgToCamera(){
    move_bkg(camera.x>>SUBPIXEL_SCALE_SHIFT, camera.y>>SUBPIXEL_SCALE_SHIFT);
}
void setCameraToWorldXY(int_fast16_t x, int_fast16_t y){
    int_fast16_t xUBound = (WORLDHEIGHT-(SCREENWIDTH<<SUBPIXEL_SCALE_SHIFT));
    int_fast16_t yUBound = (WORLDHEIGHT-(SCREENHEIGHT<<SUBPIXEL_SCALE_SHIFT));
    camera.x=(x>0)?((x<xUBound)?x:xUBound):0; 
    camera.y=(y>0)?((y<yUBound)?y:yUBound):0; 
}
uint_fast8_t viewXfromWorldX(int_fast16_t x){
    return ((x-camera.x)>>SUBPIXEL_SCALE_SHIFT)+GB_MARGIN_X;
}
uint_fast8_t viewYfromWorldY(int_fast16_t y){
    return ((y-camera.y)>>SUBPIXEL_SCALE_SHIFT)+GB_MARGIN_Y;
}

void populateCollisionMap(uint_fast8_t originalMap[], uint_fast16_t originalWidth, uint_fast16_t originalHeight){
    const uint_fast16_t maplength = originalHeight*originalWidth;
    const uint_fast16_t memsize=maplength*sizeof(uint_fast8_t);
    collisionMapHeight=originalHeight;
    collisionMapWidth=originalWidth;
    collisionMap=malloc(memsize);
    if(collisionMap==NULL){
    } else {
        for(uint_fast16_t i=0;i<maplength;i++){
            collisionMap[i]=originalMap[i];
            // if(originalMap[i]>0)
            //     { collisionMap[i]=3; }
            // else 
            //     { collisionMap[i]=0; }
        }
    }
}
void destroyCollisionMap(){
    for (uint_fast8_t i = 0; i < collisionMapHeight*collisionMapWidth; i++)
    {
        free(&collisionMap[i]);
    }
    free(collisionMap);
}

uint_fast8_t whatTileTypeAtXY(int_fast16_t x, int_fast16_t y){
    uint_fast16_t column = (x>>SUBPIXEL_SCALE_SHIFT>>TILE_SIZE_SHIFT);
    uint_fast16_t row = y>>SUBPIXEL_SCALE_SHIFT>>TILE_SIZE_SHIFT;

    uint_fast16_t mapidx = column+(row*collisionMapWidth);

    return collisionMap[mapidx];
}

uint_fast8_t isWorldSolidAtXY(int_fast16_t x, int_fast16_t y){
    return whatTileTypeAtXY(x,y)>0;
}

void putShieldAtXY(int_fast16_t x, int_fast16_t y){
    uint_fast16_t column = x>>SUBPIXEL_SCALE_SHIFT>>TILE_SIZE_SHIFT;
    uint_fast16_t row = y>>SUBPIXEL_SCALE_SHIFT>>TILE_SIZE_SHIFT;

    uint_fast16_t mapidx = column+(row*collisionMapWidth);

    collisionMap[mapidx] = 3;
    set_bkg_tiles(column,row,1,1,&map_tiles[1]);
}
void putShieldAtRowCol(uint_fast16_t row, uint_fast16_t col){
    uint_fast16_t mapidx = col+(row*collisionMapWidth);

    collisionMap[mapidx] = 3;
    set_bkg_tiles(col,row,1,1,&map_tiles[1]);
}