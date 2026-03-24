class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_set<char>> rows(9), col(9), boxes(9);

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char num = board[i][j];
                if (num == '.')
                {
                    continue;
                }
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (rows[i].count(num) || col[j].count(num) || boxes[boxIndex].count(num))
                {
                    return false;
                }
                rows[i].insert(num);
                col[j].insert(num);
                boxes[boxIndex].insert(num);
            }
        }
        return true;
    }
};