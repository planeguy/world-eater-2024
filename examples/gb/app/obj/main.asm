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
	.globl _updatePlayers
	.globl _set_sprite_data
	.globl _set_bkg_tiles
	.globl _set_bkg_data
	.globl _vsync
	.globl _joypad
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
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:10: void init_gfx(void) {
;	---------------------------------
; Function init_gfx
; ---------------------------------
_init_gfx::
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:12: set_bkg_data(0, 5, map_tiles);
	ld	de, #_map_tiles
	push	de
	ld	hl, #0x500
	push	hl
	call	_set_bkg_data
	add	sp, #4
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:13: set_bkg_tiles(0, 0, TEST_MAPWidth, TEST_MAPHeight, TEST_MAP);
	ld	de, #_TEST_MAP
	push	de
	ld	hl, #0x2014
	push	hl
	xor	a, a
	rrca
	push	af
	call	_set_bkg_tiles
	add	sp, #6
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:16: SHOW_BKG;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x01
	ldh	(_LCDC_REG + 0), a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:18: set_sprite_data(0,4,player_tiles);
	ld	de, #_player_tiles
	push	de
	ld	hl, #0x400
	push	hl
	call	_set_sprite_data
	add	sp, #4
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:19: playerPawns[0].sprite=0;
	ld	hl, #(_playerPawns + 1)
	ld	(hl), #0x00
;c:\dev\projects\world-eater-2024\include\gb\gb.h:1804: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), #0x00
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:21: playerPawns[0].facing=PF_UP;
	ld	hl, #_playerPawns
	ld	(hl), #0x00
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:22: playerPawns[0].x=0<<SUBPIXEL_SCALE_SHIFT; playerPawns[0].y=0<<SUBPIXEL_SCALE_SHIFT;
	ld	hl, #(_playerPawns + 2)
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
	ld	hl, #(_playerPawns + 4)
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:23: SHOW_SPRITES;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x02
	ldh	(_LCDC_REG + 0), a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:24: }
	ret
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:27: void main(void)
;	---------------------------------
; Function main
; ---------------------------------
_main::
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:29: init_gfx();
	call	_init_gfx
;c:\dev\projects\world-eater-2024\include\gb\gb.h:1378: SCX_REG=x, SCY_REG=y;
	xor	a, a
	ldh	(_SCX_REG + 0), a
	xor	a, a
	ldh	(_SCY_REG + 0), a
;c:\dev\projects\world-eater-2024\include\gb\gb.h:1392: SCX_REG+=x, SCY_REG+=y;
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:35: while(1) {
00102$:
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:40: players[0].input=joypad();
	ld	bc, #_players+0
	call	_joypad
	ld	(bc), a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:41: updatePlayers(0);
	xor	a, a
	call	_updatePlayers
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:44: vsync();
	call	_vsync
;C:\dev\projects\world-eater-2024\examples\gb\app\src\main.c:46: }
	jr	00102$
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
