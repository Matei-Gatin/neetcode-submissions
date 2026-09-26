using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_count(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            s1_count[s1[i] - 'a']++;
        }

        vector<int> window_count(26, 0);

        int window_len = s1.size(); 
        int l = 0;
        
        for (int r = 0; r < s2.size(); r++) {
            window_count[s2[r] - 'a']++;

            if (r - l + 1 == window_len) {
                if (s1_count == window_count) {
                    return true;
                }

                window_count[s2[l] - 'a']--;

                l++;
            }
        }

        return false;
    }
};
