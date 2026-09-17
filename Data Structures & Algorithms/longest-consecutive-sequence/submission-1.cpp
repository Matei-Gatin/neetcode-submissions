using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());

        int longest_streak = 0;

        for (int num : num_set) {
            if (!(num_set.contains(num - 1))) {
                int current_num = num;
                int current_streak = 0;

                while (num_set.contains(current_num++)) {
                    current_streak++;
                }

                longest_streak = max(current_streak, longest_streak);
            }
        }

        return longest_streak;
    }
};
