#include "dataFunc.h"

#ifndef data_ImplementFunc_h
#define data_ImplementFunc_h

void keysPressed()
{
	switch(joypad())
		{
			case J_RIGHT:
				set_sprite_tile(0, 1);
				dir = 'R';
					px += getBehavior();
				break;

			case J_LEFT:
				set_sprite_tile(0, 0);
				dir = 'L';
					px -= getBehavior();
				break;

			case J_UP:
				dir = 'U';
					py -= getBehavior();
				break;

			case J_DOWN:
				dir = 'D';
					py += getBehavior();
				break;

			// Debug Info
			
			case J_A:
				printf("\npx: %u \npy: %u \n", px + (TILE_W * OFFSET_MAP), py + (TILE_W * OFFSET_MAP));
				printf("pCellX: %u \npCellY: %u \n", pCellX, pCellY);
				printf("mapIndex: %u \n", mapIndex);
				printf("map[mapIndex]:%u \n", map[lvl][mapIndex]);
				printf("dir: %c \n", dir);
				printf("CheckCooll: %u \n", checkColl(px, py));
				printf("CorChest:%u-%u-%u-%u-%u-%u \n", 
				correctArrayChestsLVL[0], 
				correctArrayChestsLVL[1], 
				correctArrayChestsLVL[2],
				correctArrayChestsLVL[3],
				correctArrayChestsLVL[4],
				correctArrayChestsLVL[5]

				);
				printf("ArrChest:%u-%u-%u-%u-%u-%u\n", 
				currArrayChest[0], 
				currArrayChest[1], 
				currArrayChest[2],
				currArrayChest[3],
				currArrayChest[4],
				currArrayChest[5]

				);
				printf("ChestIndex: %u \n", chestIndex);
				printf("isExitLVL %u \n", isExitLVL);
				printf("\n\n\n");
				break;
		}
}

#endif