#include <sstream>

class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.size() >= 100){
            throw runtime_error("error: array is to big: " + to_string(strs.size()));
        }

        string result;
        for (auto s : strs)
        {
            if (s.length() > 200) {
                throw length_error("error: string is too long: " + s);
            }
                
            result += static_cast<unsigned char>(s.length());
            result += s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        for (auto i = 0, len = 0; i < s.length(); i += len){
            len = static_cast<unsigned char>(s[i]);
            result.emplace_back(s, ++i, len);
        }
        return result;

    }
};
