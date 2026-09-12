class Solution {
public:

    string encode(vector<string>& strs) {
        // Format of encoding: [len] + [#] + [str]
        // ["Hello", "Word"] -> ["5#Hello4#Word"]

        string encoded = "";

        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        // ["11#Hello4#Word"]

        vector<string> decoded;
        int i = 0;

        while (i < s.size()) {
            int hash_idx = s.find('#', i);
            
            string num_str = s.substr(i, hash_idx - i);
            int len = stoi(num_str);

            string decoded_str = s.substr(hash_idx + 1, len);
            decoded.push_back(decoded_str);

            // update i
            i = hash_idx + len + 1;
        }


        return decoded;
    }
};