class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // FIRST THING THAT COMES THREW MIND:
        /*
            create a hashmap that contains a code from act (for example we sort the letters or something)
            the k:v in the map will be code: vector<string> (e.g. a#c#################t#######: act)
            we loop therew the strings and associate them with their codes in the map and then we return the value lists in the map as a vector<vector<string>>
        */

        std::unordered_map<string, vector<string>> anagram_map;

        for (const string& s : strs) {
            string code = s;

            std::sort(code.begin(), code.end());

            anagram_map[code].push_back(s);
        }

        std::vector<vector<string>> result;

        for (const auto& [key, value] : anagram_map) {
            result.push_back(value);
        }

        return result;
    }
};
