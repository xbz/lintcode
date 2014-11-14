#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int> &array, int target) {
        int lower = 0;
        int upper = array.size() - 1;
        int ret = -1;
        while (lower <= upper) {
            int mid = lower + (upper-lower)/2;
            if (array[mid] < target) {
                lower = mid + 1;
            } else if (array[mid] > target) {
                upper = mid - 1;
            } else {
                ret = mid;
                upper = mid - 1;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    vector<int> v;
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);

    Solution s;
    int target = 10;
    int pos = s.binarySearch(v, target);
    cout << "pos:" << pos << endl;

    return 0;
}
