#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int> &array, int target) {
        vector<int>::const_iterator cit = \
            lower_bound(array.begin(), array.end(), target);
        if (cit == array.end())
            return -1;
        if (*cit > target)
            return -1;
        return cit - array.begin();
    }
};

int main(int argc, char* argv[]) {
    vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(9);
    v.push_back(9);
    v.push_back(12);
    v.push_back(13);

    Solution s;
    int target = 10;
    int pos = s.binarySearch(v, target);
    cout << "pos:" << pos << endl;

    return 0;
}
