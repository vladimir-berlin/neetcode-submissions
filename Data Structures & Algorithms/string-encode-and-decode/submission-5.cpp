#include <sstream>

class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.size() >= 100){
            cout << "error: array is to big." << endl;
            return string();
        }

        string result;
        for (auto s : strs)
        {
            if (s.length() > 200) {
                cout << "error: excceed string length" << s.length() << endl;
                // TODO: exception?
                // throw logic
                continue;
            }
                
            result += static_cast<unsigned char>(s.length());
            result += s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        for (auto i = 0; i < s.length();){
            auto len = static_cast<unsigned char>((s[i]));
            
            result.emplace_back(s, ++i, len);
            i += len;    
        }
        return result;

    }
};
