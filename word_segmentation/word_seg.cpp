#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        bool f[s.size()+1];
        f[0] = true;

        bool chs[256] = {false};
        for (unordered_set<string>::iterator it=dict.begin(); \
             it!=dict.end(); ++it) {
            string word = *it;
            for (size_t i=0; i<word.size(); ++i)
                chs[static_cast<int>(word[i])] = true;
		}
        for (size_t i=0; i<s.size(); ++i) {
            if (!chs[static_cast<int>(s[i])])
                return false;
        }

        for (size_t i=1; i<=s.size(); ++i) {
            f[i] = false;
            for (int j=i-1; j>=0; --j) {
                string sub = s.substr(j, i-j);
                if (f[j] && dict.find(sub)!=dict.end() && !f[i]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.size()];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str = "xlintcodecodelintsum";
    unordered_set<string> dict;
    dict.insert("lint");
    dict.insert("code");
    dict.insert("sum");

    bool bSeg = s.wordSegmentation(str, dict);
    cout << "can word segment:" << bSeg << endl;

    return 0;
}
