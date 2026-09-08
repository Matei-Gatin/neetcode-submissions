class Solution {
public:
    bool isAnagram(string s, string t) {
        // TIME: O(n) | SPACE: O(1)

        // compare the strings
        if (s.length() != t.length()) {
            return false;
        }

        // create an array of 26 characters
        int counts[26] = {0};

        // loop threw the first string and increment counts
        for (int i = 0; i < s.length(); i++) {
            counts[s[i] - 'a']++;
        }

        // loop threw the second string and decrement counts
        for (int i = 0; i < t.length(); i++) {
            counts[t[i] - 'a']--;
            
            if (counts[t[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
