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
bool checkWin();
void handleKey(const SDL_Event event, bool& gameOver, bool& win);
void resetGame();
bool mouseClickInside(const SDL_Event& event, const SDL_Rect& rect);
#endif // LOGIC_H
