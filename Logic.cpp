#include "Logic.h"
extern int board[GRID_SIZE][GRID_SIZE];

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

vector<int> compressAndMerge(vector<int> line, bool &moved)
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
            i++;
            moved = true;
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

        vector<int> newRow = compressAndMerge(currentRow, moved);
        for (int col = 0; col < GRID_SIZE; col++)
        {
            board[row][col] = newRow[col];
        }
    }
    if (moved) spawnRandomNumber();
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

        vector<int> newRow = compressAndMerge(currentRow, moved);
        for (int col = 0; col < GRID_SIZE; col++)
        {
            board[row][GRID_SIZE - 1 - col] = newRow[col];
        }
    }
    if (moved) spawnRandomNumber();
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

        vector<int> newCol = compressAndMerge(currentCol, moved);
        for (int row = 0; row < GRID_SIZE; row++)
        {
            board[row][col] = newCol[row];
        }
    }
    if (moved) spawnRandomNumber();
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

        vector<int> newCol = compressAndMerge(currentCol, moved);
        for (int row = 0; row < GRID_SIZE; row++)
        {
            board[GRID_SIZE - 1 - row][col] = newCol[row];
        }
    }
    if (moved) spawnRandomNumber();
}
