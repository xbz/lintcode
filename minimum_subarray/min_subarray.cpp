#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArray(vector<int> nums) {
        int n = nums.size();

        int f[n];
        f[0] = nums[0];
        int g[n];
        g[0] = nums[0];
        for (int i=1; i<n; ++i) {
            g[i] = min(g[i-1]+nums[i], nums[i]);
            f[i] = min(f[i-1], g[i]);
        }

        return f[n-1];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int arr[] = { 1, -1, -2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+n);

    int min_sum = s.minSubArray(v);
    cout << "min_sum:" << min_sum << endl;

    return 0;
}
