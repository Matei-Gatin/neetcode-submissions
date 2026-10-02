using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int res = 0;        
        int l = 0;
        int r = height.size() - 1;
        int max_height_l = height[l];
        int max_height_r = height[r];

        while (l < r) {
            if (height[l] < height[r]) {
                l++;
                max_height_l = max(max_height_l, height[l]);
                res += max_height_l - height[l];
            } else {
                r--;
                max_height_r = max(max_height_r, height[r]);
                res += max_height_r - height[r];
            }
        }

        return res;
    }
};
