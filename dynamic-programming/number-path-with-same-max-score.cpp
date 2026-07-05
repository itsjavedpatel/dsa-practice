#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

/*
    Problem: Number of Paths with Max Score

    Given an n x n board:
    - 'S' is the starting cell at bottom-right.
    - 'E' is the ending cell at top-left.
    - Digits '1' to '9' represent score values.
    - 'X' represents an obstacle.

    From S, we can move only:
    - Up
    - Left
    - Diagonal up-left

    We need to return:
    - Maximum score that can be collected from S to E.
    - Number of paths that give that maximum score.

    S and E do not contribute to the score.

    If there is no valid path, return {0, 0}.

    Approach:
    - Use DFS + Memoization.
    - solve(row, col) returns:
        {maximum score from board[row][col] to E,
         number of paths giving that maximum score}

    DP state:
    - dp[row][col].first  = max score
    - dp[row][col].second = number of ways

    Special values:
    - {-2, 0} means not calculated yet.
    - {-1, 0} means calculated, but no valid path exists.
*/

class Solution
{
    int n;
    vector<string> board;

    vector<vector<pair<int, int>>> dp;

    pair<int, int> solve(int row, int col)
    {
        // Out of bounds
        if (row < 0 || col < 0)
        {
            return {-1, 0};
        }

        // Blocked cell
        if (board[row][col] == 'X')
        {
            return {-1, 0};
        }

        // Reached destination E
        if (row == 0 && col == 0)
        {
            return {0, 1};
        }

        // Already calculated
        if (dp[row][col].first != -2)
        {
            return dp[row][col];
        }

        // Possible moves: left, up, diagonal up-left
        int dx[] = {0, -1, -1};
        int dy[] = {-1, 0, -1};

        int bestScore = -1;
        int ways = 0;

        for (int i = 0; i < 3; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            auto next = solve(newRow, newCol);

            int nextScore = next.first;
            int nextWays = next.second;

            // Ignore invalid paths
            if (nextWays == 0)
                continue;

            // Found better score
            if (nextScore > bestScore)
            {
                bestScore = nextScore;
                ways = nextWays;
            }

            // Found another path with same best score
            else if (nextScore == bestScore)
            {
                ways = (ways + nextWays) % MOD;
            }
        }

        // No valid path from this cell to E
        if (ways == 0)
        {
            return dp[row][col] = {-1, 0};
        }

        int cellValue = 0;

        // Only digit cells add score
        if (board[row][col] >= '1' && board[row][col] <= '9')
        {
            cellValue = board[row][col] - '0';
        }

        return dp[row][col] = {bestScore + cellValue, ways};
    }

public:
    vector<int> pathsWithMaxScore(vector<string> &inputBoard)
    {
        board = inputBoard;
        n = board.size();

        dp.assign(n, vector<pair<int, int>>(n, {-2, 0}));

        // Start from S at bottom-right
        auto ans = solve(n - 1, n - 1);

        if (ans.second == 0)
        {
            return {0, 0};
        }

        return {ans.first, ans.second};
    }
};

int main()
{
    Solution sol;

    vector<string> board = {
        "E23",
        "2X2",
        "12S"};

    vector<int> ans = sol.pathsWithMaxScore(board);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}