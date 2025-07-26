#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution
{
public:
    // Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
    void setRow(vector<vector<int>> &matrix, int n, int m, int i)
    {
        int j;
        for (j = 0; j < m; ++j)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][j] = -1212;
            }
        }
    }
    void setCol(vector<vector<int>> &matrix, int n, int m, int j)
    {
        int i;
        for (i = 0; i < n; ++i)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][j] = -1212;
            }
        }
    }

    void setZeroes(vector<vector<int>> &matrix)
    {
        int i, j;
        int n = matrix.size();
        int m = matrix[0].size();
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    setRow(matrix, n, m, i);
                    setCol(matrix, n, m, j);
                }
            }
        }
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                if (matrix[i][j] == -1212)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix;
    Solution myobj;
    myobj.setZeroes(matrix);
    return 0;

}