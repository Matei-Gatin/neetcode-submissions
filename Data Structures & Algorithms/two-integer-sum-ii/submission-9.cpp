using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
             0 1 2  3 
            [2,7,11,15]

            T = 9
        */

        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r];

            if (sum > target) {
                r--;
            } else if (sum < target) {
                l++;
            } else {
                return vector<int>{l + 1, r + 1}; 
            }
        }

        return vector<int>{};
    }
};