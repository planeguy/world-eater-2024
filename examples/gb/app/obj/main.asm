;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module main
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _init_gfx
	.globl _set_bkg_tiles
	.globl _set_bkg_data
	.globl _vsync
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
;src\main.c:9: void init_gfx(void) {
;	---------------------------------
; Function init_gfx
; ---------------------------------
_init_gfx::
;src\main.c:11: set_bkg_data(0, 5, GAME_TILES);
	ld	de, #_GAME_TILES
	push	de
	ld	hl, #0x500
	push	hl
	call	_set_bkg_data
	add	sp, #4
;src\main.c:12: set_bkg_tiles(0, 0, 20, 54, TEST_MAP);
	ld	de, #_TEST_MAP
	push	de
	ld	hl, #0x3614
	push	hl
	xor	a, a
	rrca
	push	af
	call	_set_bkg_tiles
	add	sp, #6
;src\main.c:15: SHOW_BKG;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x01
	ldh	(_LCDC_REG + 0), a
;src\main.c:16: }
	ret
;src\main.c:19: void main(void)
;	---------------------------------
; Function main
; ---------------------------------
_main::
;src\main.c:21: init_gfx();
	call	_init_gfx
;src\main.c:24: while(1) {
00102$:
;src\main.c:31: vsync();
	call	_vsync
;src\main.c:33: }
	jr	00102$
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
