;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module player
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _updatePlayerPosition
	.globl _setPlayerSpriteTile
	.globl _processInput
	.globl _getMapTileCollisionAt
	.globl _playerPawns
	.globl _players
	.globl _updatePlayers
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_players::
	.ds 16
_playerPawns::
	.ds 40
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
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:10: void processInput(uint_fast8_t p){
;	---------------------------------
; Function processInput
; ---------------------------------
_processInput::
	add	sp, #-5
	ldhl	sp,	#4
	ld	(hl), a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:12: playerPawns[p].dx=0;
	ld	bc, #_playerPawns+0
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	hl, #0x0006
	add	hl, bc
	inc	sp
	inc	sp
	push	hl
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:13: playerPawns[p].dy=0;
	ld	hl, #0x0008
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl-), a
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:16: if(players[p].input&J_UP){
	ldhl	sp,	#4
	ld	l, (hl)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	ld	de, #_players
	add	hl, de
	ld	a, (hl)
	bit	2, a
	jr	Z, 00110$
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:17: playerPawns[p].dy=-PLAYER_SPEED;
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, #0xfe
	ld	(hl+), a
	ld	(hl), #0xff
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:18: playerPawns[p].facing=PF_UP;
	xor	a, a
	ld	(bc), a
	jr	00112$
00110$:
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:19: } else if(players[p].input&J_RIGHT){
	bit	0, a
	jr	Z, 00107$
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:20: playerPawns[p].dx=PLAYER_SPEED;
	pop	hl
	push	hl
	ld	a, #0x02
	ld	(hl+), a
	ld	(hl), #0x00
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:21: playerPawns[p].facing=PF_RT;
	ld	a, #0x01
	ld	(bc), a
	jr	00112$
00107$:
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:22: } else if(players[p].input&J_LEFT){
	bit	1, a
	jr	Z, 00104$
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:23: playerPawns[p].dx=-PLAYER_SPEED;
	pop	hl
	push	hl
	ld	a, #0xfe
	ld	(hl+), a
	ld	(hl), #0xff
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:24: playerPawns[p].facing=PF_LT;
	ld	a, #0x03
	ld	(bc), a
	jr	00112$
00104$:
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:25: } else if(players[p].input&J_DOWN){
	bit	3, a
	jr	Z, 00112$
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:26: playerPawns[p].dy=PLAYER_SPEED;
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, #0x02
	ld	(hl+), a
	ld	(hl), #0x00
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:27: playerPawns[p].facing=PF_DN;
	ld	a, #0x02
	ld	(bc), a
00112$:
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:29: }
	add	sp, #5
	ret
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:31: void setPlayerSpriteTile(uint_fast8_t p){
;	---------------------------------
; Function setPlayerSpriteTile
; ---------------------------------
_setPlayerSpriteTile::
	ld	c, a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:32: set_sprite_tile(playerPawns[p].sprite,playerPawns[p].facing);
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	ld	de, #_playerPawns
	add	hl, de
	ld	a, (hl+)
	ld	c, a
;c:\dev\projects\world-eater-2024\include\gb\gb.h:1804: shadow_OAM[nb].tile=tile;
	ld	l, (hl)
	ld	de, #_shadow_OAM+0
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	inc	hl
	inc	hl
	ld	(hl), c
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:32: set_sprite_tile(playerPawns[p].sprite,playerPawns[p].facing);
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:33: }
	ret
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:35: void updatePlayerPosition(uint_fast8_t p){
;	---------------------------------
; Function updatePlayerPosition
; ---------------------------------
_updatePlayerPosition::
	add	sp, #-6
	ld	c, a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:37: intox=playerPawns[p].x+playerPawns[p].dx;
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	ld	bc,#_playerPawns
	add	hl,bc
	ld	c, l
	ld	b, h
	ld	hl, #0x0002
	add	hl, bc
	inc	sp
	inc	sp
	ld	e, l
	ld	d, h
	push	de
	ld	a, (de)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, c
	add	a, #0x06
	ld	e, a
	ld	a, b
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	add	a, l
	ldhl	sp,	#2
	ld	(hl), a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:38: intoy=playerPawns[p].y+playerPawns[p].dy;
	ld	hl, #0x0004
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#5
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#4
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, c
	add	a, #0x08
	ld	c, a
	jr	NC, 00112$
	inc	b
00112$:
	ld	a, (bc)
	add	a, l
	ldhl	sp,	#5
	ld	(hl), a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:41: if(getMapTileCollisionAt(intox>>SUBPIXEL_SCALE_SHIFT,intoy>>SUBPIXEL_SCALE_SHIFT)>=0){
	ld	e, (hl)
	sra	e
	sra	e
	sra	e
	sra	e
	ldhl	sp,	#2
	ld	c, (hl)
	sra	c
	sra	c
	sra	c
	sra	c
	ld	a, c
	call	_getMapTileCollisionAt
	bit	7,a
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:43: return;
	jr	Z, 00103$
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:47: playerPawns[p].x=intox;
	ldhl	sp,	#2
	ld	a, (hl)
	ld	c, a
	rlca
	sbc	a, a
	ld	b, a
	pop	hl
	push	hl
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:48: playerPawns[p].y=intoy;
	ldhl	sp,	#5
	ld	a, (hl-)
	dec	hl
	ld	c, a
	rlca
	sbc	a, a
	ld	b, a
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), c
	inc	hl
	ld	(hl), b
00103$:
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:49: }
	add	sp, #6
	ret
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:51: void updatePlayers(uint_fast8_t tick){
;	---------------------------------
; Function updatePlayers
; ---------------------------------
_updatePlayers::
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:52: for(uint_fast8_t p=0;p<1;p++){
	xor	a, a
00104$:
	sub	a, #0x01
	ret	NC
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:53: processInput(p);
	xor	a, a
	call	_processInput
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:54: setPlayerSpriteTile(p);
	xor	a, a
	call	_setPlayerSpriteTile
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:55: updatePlayerPosition(p);
	xor	a, a
	call	_updatePlayerPosition
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:59: (playerPawns[p].y>>SUBPIXEL_SCALE_SHIFT)
	ld	hl, #_playerPawns + 4
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:58: (playerPawns[p].x>>SUBPIXEL_SCALE_SHIFT),
	ld	hl, #_playerPawns + 2
	ld	a,	(hl+)
	ld	h, (hl)
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	sra	h
	rr	l
	sra	h
	rr	l
	sra	h
	rr	l
	sra	h
	rr	l
	ld	b, l
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:57: playerPawns[p].sprite,
	ld	hl, #_playerPawns + 1
;c:\dev\projects\world-eater-2024\include\gb\gb.h:1877: OAM_item_t * itm = &shadow_OAM[nb];
	ld	l, (hl)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	ld	de, #_shadow_OAM
	add	hl, de
;c:\dev\projects\world-eater-2024\include\gb\gb.h:1878: itm->y=y, itm->x=x;
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:52: for(uint_fast8_t p=0;p<1;p++){
	ld	a, #0x01
;C:\dev\projects\world-eater-2024\examples\gb\app\src\player.c:62: }
	jr	00104$
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
