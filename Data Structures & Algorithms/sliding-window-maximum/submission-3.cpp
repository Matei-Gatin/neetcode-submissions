using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> window;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            while (!window.empty() && nums[window.back()] < nums[r]) {
                window.pop_back();
            }

            window.push_back(r);

            if (r - l + 1 == k) {
                res.push_back(nums[window.front()]);

                if (window.front() == l) {
                    window.pop_front();
                }

                l++;
            }
        }

        return res;
    }
};
