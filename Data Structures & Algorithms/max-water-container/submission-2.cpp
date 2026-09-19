using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        /*
            height = [1,7,2,5,4,7,3,6]
            
            area = width * height
            area = 7 - 0 = 7
            height = 1
        */

        int res = 0;
        int l = 0, r = heights.size() - 1;

        while (l < r) {
            int width = r - l;
            int height = min<int>(heights[l], heights[r]);

            int current_area = width * height;

            res = max(res, current_area);

            if (heights[l] < heights[r]) {
                l++;
            } else if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }

        return res;
    }
};
