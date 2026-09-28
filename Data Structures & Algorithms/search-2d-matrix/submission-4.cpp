using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int r = 0;
        int c = cols - 1;

        while (r < rows && c >= 0) {
            int current_val = matrix[r][c];

            if (current_val == target) {
                return true;
            } else if (target < current_val) {
                c--;
            } else {
                r++;
            }
        }

        return false;
    }
};