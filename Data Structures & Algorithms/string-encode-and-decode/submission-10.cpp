#include <sstream>

class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.size() >= 100){
            cout << "error: array is to big." << endl;
            throw runtime_error("error: array is to big.");
            return string();
        }

        string result;
        for (auto s : strs)
        {
            if (s.length() > 200) {
                cout << "error: excceed string length" << s.length() << endl;
                throw length_error(s);
                continue;
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
