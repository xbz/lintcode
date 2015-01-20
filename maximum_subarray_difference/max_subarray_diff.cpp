#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDiffSubArrays(vector<int> nums) {
        int n = nums.size();

        int f_max[n];
        f_max[0] = nums[0];
        int f_max_inc = nums[0];
        int f_min[n];
        f_min[0] = nums[0];
        int f_min_inc = nums[0];
        for (int i=1; i<n; ++i) {
            f_max_inc = max(f_max_inc+nums[i], nums[i]);
            f_max[i] = max(f_max_inc, f_max[i-1]);

            f_min_inc = min(f_min_inc+nums[i], nums[i]);
            f_min[i] = min(f_min_inc, f_min[i-1]);
        }

        int r_max[n];
        r_max[0] = nums[n-1];
        int r_max_inc = nums[n-1];
        int r_min[n];
        r_min[0] = nums[n-1];
        int r_min_inc = nums[n-1];
        for (int i=1; i<n; ++i) {
            r_max_inc = max(r_max_inc+nums[n-1-i], nums[n-1-i]);
            r_max[i] = max(r_max_inc, r_max[i-1]);

            r_min_inc = min(r_min_inc+nums[n-1-i], nums[n-1-i]);
            r_min[i] = min(r_min_inc, r_min[i-1]);
        }

        int max_diff = INT_MIN;
        for (int i=0; i<n-1; ++i) {
            int diff = abs(f_max[i] - r_min[n-2-i]);
            max_diff = max(max_diff, diff);

            diff = abs(r_max[n-2-i] - f_min[i]);
            max_diff = max(max_diff, diff);
        }
        return max_diff;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int arr[] = { 1,3,-1,2,-1,2, -100, 3, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+n);

    int max_sum = s.maxDiffSubArrays(v);
    cout << "max_sum:" << max_sum << endl;

    return 0;
}
