using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // create a 2D array of rows (9 rows x 9 digits) (calculate the IDX by '9' - '1')
        // create a 2D array of cols (9 cols x 9 digits) (calculate the IDX by '9' - '1')
        // crate an array for boxes (9 boxes) -> box_index = (r / 3) * 3 + (c / 3)

        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                char current_char = board[r][c];

                if (current_char == '.') {
                    continue;
                }

                int box_idx = (r / 3) * 3 + (c / 3);
                int digit_idx = current_char - '1';

                if (rows[r][digit_idx] || cols[c][digit_idx] || boxes[box_idx][digit_idx]) {
                    return false;
                }

                rows[r][digit_idx] = true;
                cols[c][digit_idx] = true;
                boxes[box_idx][digit_idx] = true;
            }
        }

        return true;
    }
};