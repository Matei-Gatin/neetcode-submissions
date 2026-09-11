using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // O(n) TIME | O(n) SPACE

        vector<int> res;
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> count;
        
        for (const int& n : nums) {
            count[n]++;
        }

        for (const auto& [num, freq] : count) {
            buckets[freq].push_back(num);
        }
        
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                res.push_back(num);

                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};
