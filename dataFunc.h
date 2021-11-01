#ifndef dataFunc_h
#define dataFunc_h

UINT8 checkCollBlock();
UBYTE checkColl(UINT16 px, UINT16 py);
UBYTE getBehavior(void);
UINT8 addNumChest(void);
UBYTE cmpChests(void);

void keysPressed(void);

void loadLevel(void);
void resetVars(void);
void clearArrChests(void);
void showLVL(void);

#endif