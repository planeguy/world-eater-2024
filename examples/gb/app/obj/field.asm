;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module field
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _getMapTileCollisionAt
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;C:\dev\projects\world-eater-2024\examples\gb\app\src\field.c:3: int_fast8_t getMapTileCollisionAt(int_fast8_t x, int_fast8_t y){ 
;	---------------------------------
; Function getMapTileCollisionAt
; ---------------------------------
_getMapTileCollisionAt::
;C:\dev\projects\world-eater-2024\examples\gb\app\src\field.c:4: return -1;
	ld	a, #0xff
;C:\dev\projects\world-eater-2024\examples\gb\app\src\field.c:5: }
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
