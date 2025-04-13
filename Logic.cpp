#include "Logic.h"

void moveLeft()
{
    for (int row = 0; row < GRID_SIZE; row++)
    {
        vector<int> currentRow;
        for (int col = 0; col < GRID_SIZE; col++)
        {
            if (board[row][col] != 0) currentRow.push_back(board[row][col]);
        }

        for (int i = 0; i < currentRow.size() - 1; i++)
        {
            if (currentRow[i] == currentRow[i + 1])
            {
                currentRow[i] *= 2;
                currentRow[i + 1] = 0;
                i++;
            }
        }

        vector<int> newRow;
        for (int val : currentRow)
        {
            if (val != 0) newRow.push_back(val);
        }
        while (newRow.size() < GRID_SIZE) newRow.push_back(0);

        for (int col = 0; col < GRID_SIZE; col++)
        {
            board[row][col] = newRow[col];
        }
    }
}

void moveRight()
{
    for (int row = 0; row < GRID_SIZE; row++)
    {
        vector<int> currentRow;
        for (int col = GRID_SIZE - 1; col >= 0; col--)
        {
            if (board[row][col] != 0) currentRow.push_back(board[row][col]);
        }

        for (int i = 0; i < currentRow.size() - 1; i++)
        {
            if (currentRow[i] == currentRow[i + 1])
            {
                currentRow[i] *= 2;
                currentRow[i + 1] = 0;
                i++;
            }
        }

        vector<int> newRow;
        for (int val : currentRow)
        {
            if (val != 0) newRow.push_back(val);
        }
        while (newRow.size() < GRID_SIZE) newRow.push_back(0);

        for (int col = 0; col < GRID_SIZE; col++)
        {
            board[row][GRID_SIZE - 1 - col] = newRow[col];
        }
    }
}

void moveUp()
{
    for (int col = 0; col < GRID_SIZE; col++)
    {
        vector<int> currentCol;
        for (int row = 0; row < GRID_SIZE; row++)
        {
            if (board[row][col] != 0) currentCol.push_back(board[row][col]);
        }

        for (int i = 0; i < currentCol.size() - 1; i++)
        {
            if (currentCol[i] == currentCol[i + 1])
            {
                currentCol[i] *= 2;
                currentCol[i + 1] = 0;
                i++;
            }
        }

        vector<int> newCol;
        for (int val : currentCol)
        {
            if (val != 0) newCol.push_back(val);
        }
        while (newCol.size() < GRID_SIZE) newCol.push_back(0);

        for (int row = 0; row < GRID_SIZE; row++)
        {
            board[row][col] = newCol[row];
        }
    }
}

void moveDown()
{
    for (int col = 0; col < GRID_SIZE; col++)
    {
        vector<int> currentCol;
        for (int row = GRID_SIZE - 1; row >= 0; row --)
        {
            if (board[row][col] != 0) currentCol.push_back(board[row][col]);
        }

        for (int i = 0; i < currentCol.size() - 1; i++)
        {
            if (currentCol[i] == currentCol[i + 1])
            {
                currentCol[i] *= 2;
                currentCol[i + 1] = 0;
                i++;
            }
        }

        vector<int> newCol;
        for (int val : currentCol)
        {
            if (val != 0) newCol.push_back(val);
        }
        while (newCol.size() < GRID_SIZE) newCol.push_back(0);

        for (int row = 0; row < GRID_SIZE; row++)
        {
            board[GRID_SIZE - 1 - row][col] = newCol[row];
        }
    }
}
