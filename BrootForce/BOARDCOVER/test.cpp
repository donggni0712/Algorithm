#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int tileType[4][2][2] = {{{1, 0}, {1, 1}}, {{0, 1}, {1, 0}}, {{1, -1}, {1, 0}}, {{0, 1}, {1, 1}}};
int H, W;

int cover(int row, int column, vector<char *> board)
{
    if (row == H - 1 && column == W - 1)
    {
        return 1;
    }
    int sum = 0;

    if (column == W)
    {
        // printf("row=%d\n", row + 1);
        return cover(row + 1, 0, board);
    }

    if (board[row][column] == '#')
    {
        // printf("column=%d\n", column);
        return cover(row, column + 1, board);
    }

    for (int i = 0; i < 4; i++)
    {
        int tile1[2] = {row + tileType[i][0][0], column + tileType[i][0][1]};
        int tile2[2] = {row + tileType[i][1][0], column + tileType[i][1][1]};
        if (tile1[0] >= H || tile1[1] >= W || tile2[0] >= H || tile2[1] >= W)
        {
            continue;
        }
        if (board[tile1[0]][tile1[1]] == '.' && board[tile2[0]][tile2[1]] == '.')
        {
            // printf("row = %d column =%d tile1={%d,%d} tile2={%d,%d}\n", row, column, tile1[0], tile1[1], tile2[0], tile2[1]);
            board[tile1[0]][tile1[1]] = '#';
            board[tile2[0]][tile2[1]] = '#';
            sum += cover(row, column + 1, board);
            // printf("back\n");
            board[tile1[0]][tile1[1]] = '.';
            board[tile2[0]][tile2[1]] = '.';
        }
    }
    return sum;
}

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        cin >> H >> W;
        vector<char *> board;
        for (int i = 0; i < H; i++)
        {
            char *row = (char *)malloc(sizeof(char) * (W + 1));
            cin >> row;
            board.push_back(row);
        }
        int res = cover(0, 0, board);
        cout << res << '\n';
    }

    return 0;
}