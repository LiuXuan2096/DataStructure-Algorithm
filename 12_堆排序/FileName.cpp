#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    return function();
}

int function()
{
    int row;
    int column;
    cin >> row >> column;
    cout << "row: " << row << " column: " << column << endl;
    vector<vector<int>> matrix(row, vector<int>(column));
    vector<vector<int>> ans(row, vector<int>(column));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
            ans[i][j] = temp;
            // cout << "temp: " << temp << endl;
        }
    }
    // 先按行遍历
    for (int i = 0; i < row; i++)
    {
        int last = matrix[i][0];
        int last_column = 0;
        int same_color = 0;
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j] == last)
            {
                same_color++;
                if (j == column - 1 and same_color >= 3)
                {
                    fill(ans[i].begin() + last_column, ans[i].begin() + last_column + same_color, 0);
                }
            }
            else
            {
                if (same_color >= 3)
                {
                    fill(ans[i].begin() + last_column, ans[i].begin() + same_color, 0);
                }
                last = matrix[i][j];
                last_column = j;
                same_color = 1;
            }
        }
    }
    // 再按列遍历
    for (int j = 0; j < column; j++)
    {
        int last = matrix[0][j];
        int last_row = 0;
        int same_color = 0;
        for (int i = 0; i < row; i++)
        {
            if (matrix[i][j] == last)
            {
                same_color++;
                if (i == row - 1 and same_color >= 3)
                {
                    for (int i = last_row; i < last_row + same_color; i++)
                    {
                        ans[i][j] = 0;
                    }
                }
            }
            else
            {
                if (same_color >= 3)
                {
                    for (int i = last_row; i < last_row + same_color; i++)
                    {
                        ans[i][j] = 0;
                    }
                }
                last = matrix[i][j];
                last_row = i;
                same_color = 1;
            }
        }
    }

    for (auto i : ans)
    {
        // cout << "91 xuan:";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}