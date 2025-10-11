class Solution {
public:
    int n;
    int t[101][101];

    int solve(vector<vector<int>>& matrix, int row, int col) {
        if (row == n - 1)
            return matrix[row][col];

        if (t[row][col] != 1000000)
            return t[row][col];

        int sum = matrix[row][col];
        int minSum = INT_MAX;

        if (row + 1 < n && col - 1 >= 0)
            minSum = min(minSum, sum + solve(matrix, row + 1, col - 1));

        if (row + 1 < n && col + 1 < n)
            minSum = min(minSum, sum + solve(matrix, row + 1, col + 1));

        if (row + 1 < n)
            minSum = min(minSum, sum + solve(matrix, row + 1, col));

        return t[row][col] = minSum;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        int result = INT_MAX;

        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                t[i][j] = 1000000;
            }
        }

        for (int col = 0; col < n; col++) {
            result = min(result, solve(matrix, 0, col));
        }

        return result;
    }
};
