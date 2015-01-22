#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void print(const vector<string>& v)
{
    vector<string>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
        cout << *it << endl;
}

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i=1; i<=n; ++i) {
            if (i%15 == 0)
                ret.push_back("fizz buzz");
            else if (i%3 == 0)
                ret.push_back("fizz");
            else if (i%5 == 0)
                ret.push_back("buzz");
            else {
                ostringstream oss;
                oss << i;
                ret.push_back(oss.str());
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    Solution s;
    vector<string> r = s.fizzBuzz(n);
    print(r);

    return 0;
}

