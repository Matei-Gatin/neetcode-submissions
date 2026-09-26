using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> t_count(128, 0);

        for (int i = 0; i < t.size(); i++) {
            t_count[t[i]]++;
        }

        vector<int> window_count(128, 0);
        int best_start = 0;
        int need = t.size();
        int have = 0;
        int min_len = INT_MAX; 
        int l = 0;
        
        for (int r = 0; r < s.size(); r++) {
            int current_char = s[r];

            window_count[current_char]++;

            if (window_count[current_char] <= t_count[current_char]) {
                have++;
            }

            while (have == need) {
                int current_len = r - l + 1;

                if (current_len < min_len) {
                    min_len = current_len;
                    best_start = l;
                }

                int left_char = s[l];
                window_count[left_char]--;
                
                if (window_count[left_char] < t_count[left_char]) {
                    have--;
                }

                l++;
            }
        }

        if (min_len == INT_MAX) {
            return "";
        }

        return s.substr(best_start, min_len);
    }
};
