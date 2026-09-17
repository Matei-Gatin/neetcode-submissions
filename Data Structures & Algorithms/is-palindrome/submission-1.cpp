using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // alphanumeric -> letters + numbers

        int l = 0, r = s.length() - 1;

        while (l < r) {
            char lower_l = tolower(s[l]);
            char lower_r = tolower(s[r]);

            if ((isdigit(lower_l) || isalpha(lower_l)) && (isdigit(lower_r) || isalpha(lower_r)) && lower_l != lower_r) {
                return false;   
            } 

            if (!(isdigit(lower_l) || isalpha(lower_l))) {
                l++;
                continue;
            }

            if (!(isdigit(lower_r) || isalpha(lower_r))) {
                r--;
                continue;
            }

            l++;
            r--;
        }

        return true;
    }   
};