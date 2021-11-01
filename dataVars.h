#ifndef dataVars_h
#define dataVars_h

enum B {
	BLANK,
	BLOCK,   		
	BRANCH,  		
	C_CHEST, 		
	O_CHEST, 		
	STONE,  		
	EXIT_STONE,  	
	EXIT_BUSH 
};

enum 
{
	LEN_ARR = 6
};

UINT8 SPEED = 70;
UINT16 DELAY_LOAD = 200;
UINT8 OFFSET_MAP = 5;

UINT8 TILE_W  = 8;
UINT8 MAP_W   = 11;
UINT8 MAP_H   = 11;

UINT16 px     = 18;
UINT16 py     = 24;

UINT8 chestIndex = 0;
UINT8 lvl = 0;
UBYTE isExitLVL = 0;

UINT8 pCellX;
UINT8 pCellY;

UINT8 mapIndex;

char dir = 'R';

#endif