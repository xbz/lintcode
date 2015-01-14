#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        bool f[s.size()+1];
        f[0] = true;

        for (size_t i=1; i<=s.size(); ++i) {
            f[i] = false;
            for (size_t j=0; j<i; ++j) {
                string sub = s.substr(j, i-j);
                if (f[j] && dict.find(sub)!=dict.end() && !f[i])
                    f[i] = true;
            }
        }
        return f[s.size()];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str = "lintcodecodelintsum";
    unordered_set<string> dict;
    dict.insert("lint");
    dict.insert("code");
    dict.insert("sum");

    bool bSeg = s.wordSegmentation(str, dict);
    cout << "can word segment:" << bSeg << endl;

    return 0;
}
