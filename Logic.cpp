#include "Logic.h"
#include <fstream>
#include <iostream>
using namespace std;

int score = 0;
int best = 0;

void spawnRandomNumber()
{
    vector<pair<int,int>> emptyCells;
    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            if (board[row][col] == 0) emptyCells.push_back({row,col});
        }
    }

    if (!emptyCells.empty())
    {
        int randomIndex = rand() % emptyCells.size();
        int randomValue = (rand() % 10 == 0) ? 4 : 2;

        int row = emptyCells[randomIndex].first;
        int col = emptyCells[randomIndex].second;
        board[row][col] = randomValue;
    }
}

vector<int> compressAndMerge(vector<int> line)
{
    vector<int> result;
    for (int i : line)
    {
        if (i != 0) result.push_back(i);
    }

    vector<int> merged;
    for (size_t i = 0; i < result.size(); i++)
    {
        if (i + 1 < GRID_SIZE && result[i] == result[i + 1])
        {
            merged.push_back(result[i] * 2);
            score += result[i] * 2;
            i++;
        }
        else merged.push_back(result[i]);
    }
    while (merged.size() < GRID_SIZE) merged.push_back(0);
    return merged;
}

void moveLeft()
{
    bool moved = false;
    for (int row = 0; row < GRID_SIZE; row++)
    {
        vector<int> currentRow;
        for (int col = 0; col < GRID_SIZE; col++)
        {
            if (board[row][col] != 0) currentRow.push_back(board[row][col]);
        }

        vector<int> newRow = compressAndMerge(currentRow);
        for (int col = 0; col < GRID_SIZE; col++)
        {
            if (board[row][col] != newRow[col])
            {
                moved = true;
                board[row][col] = newRow[col];
            }
        }
    }
    if (moved)
    {
        spawnRandomNumber();
    }
}

void moveRight()
{
    bool moved = false;
    for (int row = 0; row < GRID_SIZE; row++)
    {
        vector<int> currentRow;
        for (int col = GRID_SIZE - 1; col >= 0; col--)
        {
            if (board[row][col] != 0) currentRow.push_back(board[row][col]);
        }

        vector<int> newRow = compressAndMerge(currentRow);
        for (int col = 0; col < GRID_SIZE; col++)
        {
            if (board[row][GRID_SIZE - 1 - col] != newRow[col])
            {
                moved = true;
                board[row][GRID_SIZE - 1 - col] = newRow[col];
            }
        }
    }
    if (moved)
    {
        spawnRandomNumber();
    }
}

void moveUp()
{
    bool moved = false;
    for (int col = 0; col < GRID_SIZE; col++)
    {
        vector<int> currentCol;
        for (int row = 0; row < GRID_SIZE; row++)
        {
            if (board[row][col] != 0) currentCol.push_back(board[row][col]);
        }

        vector<int> newCol = compressAndMerge(currentCol);
        for (int row = 0; row < GRID_SIZE; row++)
        {
            if (board[row][col] != newCol[row])
            {
                moved = true;
                board[row][col] = newCol[row];
            }
        }
    }
    if (moved)
    {
        spawnRandomNumber();
    }
}

void moveDown()
{
    bool moved = false;
    for (int col = 0; col < GRID_SIZE; col++)
    {
        vector<int> currentCol;
        for (int row = GRID_SIZE - 1; row >= 0; row --)
        {
            if (board[row][col] != 0) currentCol.push_back(board[row][col]);
        }

        vector<int> newCol = compressAndMerge(currentCol);
        for (int row = 0; row < GRID_SIZE; row++)
        {
            if (board[GRID_SIZE - 1 - row][col] != newCol[row])
            {
                moved = true;
                board[GRID_SIZE - 1 - row][col] = newCol[row];
            }
        }
    }
    if (moved)
    {
        spawnRandomNumber();
    }
}

bool canMove()
{
    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            if (board[row][col] == 0) return true;
            if (col + 1 < GRID_SIZE && board[row][col] == board[row][col + 1]) return true;
            if (row + 1 < GRID_SIZE && board[row][col] == board[row + 1][col]) return true;
        }
    }
    return false;
}

bool checkWin()
{
    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            if (board[row][col] == 2048) return true;
        }
    }
    return false;
}

void resetGame()
{
    memset(board, 0, sizeof(board));
    score = 0;
    spawnRandomNumber();
    spawnRandomNumber();
}

void handleKey(const SDL_Event event, bool& gameOver, bool& win)
{
    if (!gameOver && !win)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_LEFT:
                moveLeft();
                break;
            case SDLK_RIGHT:
                moveRight();
                break;
            case SDLK_UP:
                moveUp();
                break;
            case SDLK_DOWN:
                moveDown();
                break;
        }
        if (checkWin()) win = true;
        if (!canMove()) gameOver = true;
    }
}

bool mouseClickInside(const SDL_Event& event, const SDL_Rect& rect)
{
    int mouseX = event.button.x;
    int mouseY = event.button.y;
    return (mouseX >= rect.x && mouseX <= rect.x + rect.w &&
                mouseY >= rect.y && mouseY <= rect.y + rect.h);
}

int loadBestScore(const string& filename)
{
    ifstream fin(filename);
    if (fin.is_open())
    {
        fin >> best;
        fin.close();
    } else
    {
        cerr << "Can't open file: " << filename << endl;
    }
    return best;
}

void saveBestScore(const string& filename, int bestScore)
{
    ofstream fout(filename);
    if (fout.is_open())
    {
        fout << bestScore;
        fout.close();
    } else
    {
        cerr << "Can't write file: " << filename << endl;
    }
}
