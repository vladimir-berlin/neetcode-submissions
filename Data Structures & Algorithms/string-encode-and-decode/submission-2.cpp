#include <sstream>

class Solution {
public:

    string encode(vector<string>& strs) {
        // TODO: check ranges.
        if (strs.size() >= 100){
            cout << "error: array is to big." << endl;
            return string();
        }

        string result;
        for (auto s : strs)
        {
            if (s.length() > 200) {
                cout << "error: excceed string length" << s.length() << endl;
                continue;
            }
                
            string tmp;
            tmp += static_cast<unsigned char>(s.length());
            tmp += s;

            auto decoded = decode(tmp)[0];

            if (s != decoded){
                cout << "error: not equal" << endl;
                cout << "encode: " << s << endl;
                cout << "decode: " << decoded << endl;
            
            }
        

            result += static_cast<unsigned char>(s.length());
            cout << "encode: " << s.length() << endl;
            
            result += s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        for (auto i = 0; i < s.length();){
            auto len = static_cast<unsigned char>((s[i]));
            cout << "decode: " << static_cast<size_t>(len) << endl;
            result.emplace_back(s.substr(++i, len));
            i += len;    
        }
        return result;

    }
};
