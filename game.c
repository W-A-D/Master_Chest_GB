#include <gb/gb.h>
#include <stdio.h>
#include "res/tiles/player.c"

#include "res/map/map2.c"
#include "res/map/maptiles.c"

//data
#include "dataVars.h"
#include "dataArrs.h"

#include "data_ImplementFunc.c"





/*

0x00 - blank block
0x01 - block
0x02 - brach
0x03 - close chest
0x04 - open chest
0x05 - potion

*/

void main()
{
	showLVL();
	set_bkg_data(0, 8, maptiles);
	set_bkg_tiles(OFFSET_MAP, OFFSET_MAP, MAP_W, MAP_H, map[lvl]);

	SPRITES_8x8;
	set_sprite_data(0, 2, player);
	set_sprite_tile(0, 0);
	
	SHOW_SPRITES;
	SHOW_BKG;
	DISPLAY_ON;

	while(1)
	{
		keysPressed();
		move_sprite(0, px + (TILE_W * OFFSET_MAP), py + (TILE_W * OFFSET_MAP));
		delay(SPEED);
	}
}

void loadLevel()
{
	showLVL();
	px -= 8;
	move_sprite(0, px, py);

	set_bkg_data(0, 8, maptiles);
	set_bkg_tiles(OFFSET_MAP, OFFSET_MAP, MAP_W, MAP_H, map[lvl]);
	resetVars();
}

void resetVars()
{
	isExitLVL = 0;
	clearArrChests();
}

void clearArrChests()
{
	for(int i = 0; i < LEN_ARR; i++)
		currArrayChest[i] = 0;

	//advanced
	//int len = sizeof currArrayChest / sizeof *currArrayChest;
	//sizeof (currArrayChest + len) - *currArrayChest;
}

UBYTE getBehavior()
{
	if(checkCollBlock() && map[lvl][mapIndex] == C_CHEST)
	{
		
		map[lvl][mapIndex] = O_CHEST;
		set_bkg_tiles(pCellX + OFFSET_MAP, pCellY + OFFSET_MAP , 1, 1, mapElements + O_CHEST);

		if(chestIndex < amountChestsLVL[0])
		{
			currArrayChest[chestIndex] = addNumChest();	
			chestIndex ++;
		}
		if(chestIndex == amountChestsLVL[lvl])
		{
			isExitLVL = cmpChests();
		}
		
	}
	if((checkCollBlock() && map[lvl][mapIndex] == EXIT_STONE) && isExitLVL)
	{
		map[lvl][mapIndex] = BLANK; //78
		//map[mapIndex + 1] = EXIT_CARPET;
		//set_bkg_tiles(pCellX, pCellY + 1, 1, 1, mapElements + EXIT_CARPET);
		set_bkg_tiles(pCellX + OFFSET_MAP, pCellY + OFFSET_MAP, 1, 1, mapElements + BLANK);
	}
	if(checkCollBlock() && map[lvl][mapIndex] == EXIT_BUSH)
	{
		map[lvl][mapIndex] = BLOCK;	
		//printf("\n\n\n\n\n\nLevel 2");

		lvl ++;
		loadLevel();
	}
		
	else if(!checkCollBlock()) 
		return 1;

	return 0;
}

void showLVL()
{
	delay(DELAY_LOAD);
	printf(" \n \n \n \n \n \n \n \n       level %u \n \n \n \n \n \n \n \n \n", lvl + 1);
	delay(DELAY_LOAD * 5);
}


UBYTE cmpChests()
{
	for(unsigned int i = 0; i < amountChestsLVL[lvl]; ++i)
	{
		if(currArrayChest[i] == correctArrayChestsLVL[i]) continue;
		else 
			return 0;
	}
	return 1;
}

UINT8 addNumChest()
{
	switch(mapIndex)
	{
		case 18:
			return 1;
			break;

		case 34:
			return 2;
			break;

		case 78:
			return 3;
			break;
	}	
	return 0;
}

UBYTE checkCollBlock()
{
	UBYTE res = 0;
	switch(dir)
	{
		case 'R':
			res = checkColl(px + 7, py + 3) || checkColl(px + 7, py + 7);
		break;

		case 'L':
			res = checkColl(px, py + 3) || checkColl(px, py + 7);
		break;

		case 'U':
			res = checkColl(px + 1, py + 2) || checkColl(px + 6, py + 2);
		break;

		case 'D':
			res = checkColl(px + 1, py + 8) || checkColl(px + 6, py + 8);
		break;
	}
	return res;
}

UBYTE checkColl(UINT16 px, UINT16 py)
{
	pCellX = (px - 8)  / TILE_W;
	pCellY = (py - 16) / TILE_W;

	mapIndex = (MAP_W  * pCellY) + pCellX;

	return map[lvl][mapIndex] != 0;
}

    