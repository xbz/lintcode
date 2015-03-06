#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int> &array, int target) {
        if (array.size() == 0)
            return -1;

        size_t low = 0;
        size_t high = array.size() - 1;
        int index = -1;
        while (low <= high) {
            size_t mid = low + (high-low)/2;
            if (array[mid] == target)
                index = mid;

            if (mid==0 || mid==array.size()-1)
                break;

            if (array[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return index;
    }

    int binarySearch_stl(vector<int> &array, int target) {
        vector<int>::const_iterator cit = \
            lower_bound(array.begin(), array.end(), target);
        if (cit == array.end())
            return -1;
        if (*cit > target)
            return -1;
        return cit - array.begin();
    }

    int binarySearch_orig(vector<int> &array, int target) {
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
