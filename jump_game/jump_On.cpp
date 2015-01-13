#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> A) {
        size_t last = 0;
        for (size_t i=0; i<A.size(); ++i) {
            if (last < i)
                return false;

            if (i+A[i] > last)
                last = i + A[i];
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { 3, 2, 1, 1, 4 };
    int arrlen = sizeof(arr) / sizeof(arr[0]);
    cout << arrlen << endl;
    vector<int> v(arr, arr+arrlen);

    bool bJump = s.canJump(v);
    cout << "can jump:" << bJump << endl;

    return 0;
}

