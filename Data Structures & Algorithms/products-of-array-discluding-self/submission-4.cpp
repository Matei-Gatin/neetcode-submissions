using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /* nums = [1,2,4,6]
           [48,24,12,8]
           

           output_arr = [1, 1, 2, 8]
           int running_left = 1
        */

        vector<int> output_arr(nums.size(), 1);
        int running_left = 1;

        for (int i = 0; i < nums.size(); i++) {
            output_arr[i] = running_left;
            running_left *= nums[i];
        }

        int running_right = 1;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            output_arr[i] *= running_right;
            running_right *= nums[i];
        } 

        return output_arr;
    }
};
