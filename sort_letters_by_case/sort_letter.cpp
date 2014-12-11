#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void sortLetters(string &letters) {
        int i = 0;
        int j = letters.size() - 1;
        int cur = 0;
        while (cur <= j) {
            if (islower(letters[cur])) {
                swap(letters, cur, i);
                ++i;
                ++cur;
            } else {
                swap(letters, cur, j);
                --j;
            }
        }
    }

private:
    void swap(string &s, int i, int j) {
        char ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    string str = "abAcD";
    cout << str << endl;
    s.sortLetters(str);
    cout << str << endl;

    return 0;
}
