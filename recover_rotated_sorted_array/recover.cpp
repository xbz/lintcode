#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& v)
{
    vector<vector<int> >::size_type i;
    for (i=0; i<v.size()-1; i++)
        cout << v[i] << ' ';

    cout << v[i] << endl;
}

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        vector<int> cp = nums;
        int pivot = searchPivot(&cp[0], cp.size());
        for (size_t i=pivot, j=0; i<cp.size(); ++i, ++j)
            nums[j] = cp[i];
        for (size_t i=0, j=cp.size()-pivot; j<cp.size(); ++i, ++j)
            nums[j] = cp[i];
    }

private:
    int searchPivot(int A[], int n) {
        if (n == 0)
            return -1;
        int target = A[0];
        int lower = 1;
        int upper = n - 1;
        int ret = -1;
        while (lower <= upper) {
            int mid = lower + (upper-lower)/2;
            if (A[mid] >= target) {
                lower = mid + 1;
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
    v.push_back(3);
    v.push_back(5);

    Solution s;
    print(v);
    s.recoverRotatedSortedArray(v);
    print(v);

    return 0;
}
