#ifndef LOGIC_H
#define LOGIC_H

#include "Grid.h"

extern int score, best;

void moveLeft();
void moveRight();
void moveUp();
void moveDown();
void spawnRandomNumber();
bool canMove();
#endif // LOGIC_H
