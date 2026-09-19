using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
            width = r - l;
            height = max(height[l], height[r]);

            area = width * height;            
        */

        int res = 0, l = 0, r = height.size() - 1;

        while (l < r) {
            int w = r - l;
            int h = min(height[l], height[r]);
            int current_area = w * h;

            res = max(res, current_area);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
};