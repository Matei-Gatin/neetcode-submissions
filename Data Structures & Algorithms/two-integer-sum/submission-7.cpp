class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // [4, 5, 6] -> T = 10
        // O(n) TIME, O(n) SPACE

        std::unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (seen.count(complement)) {
                return {seen[complement], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};
