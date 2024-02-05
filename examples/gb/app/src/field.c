#include "field.h"
#include "world.h"

int_fast8_t getMapTileCollisionAt(int_fast8_t x, int_fast8_t y){ 
    return -1;
}

void followCameraTo(int_fast16_t y){
    int_fast16_t cameraTopRequested = y-(SCREENHEIGHT<<SUBPIXEL_SCALE_SHIFT);
    int_fast16_t cameraBottomRequested = y+(SCREENHEIGHT<<SUBPIXEL_SCALE_SHIFT);

    //if((cameraTopRequested>>SUBPIXEL_SCALE_SHIFT<=0)||(cameraBottomRequested>>SUBPIXEL_SCALE_SHIFT>=FIELD_HEIGHT)) return;

    //move_bkg(0,cameraTopRequested>>SUBPIXEL_SCALE_SHIFT);

    move_bkg(0,y>>SUBPIXEL_SCALE_SHIFT);
}