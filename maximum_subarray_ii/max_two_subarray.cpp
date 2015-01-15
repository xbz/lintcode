#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTwoSubArrays(vector<int> nums) {
        int n = nums.size();

        int f[n];
        f[0] = nums[0];
        int g[n];
        g[0] = nums[0];
        for (int i=1; i<n; ++i) {
            g[i] = max(g[i-1]+nums[i], nums[i]);
            f[i] = max(f[i-1], g[i]);
        }

        int fr[n];
        fr[0] = nums[n-1];
        int gr[n];
        gr[0] = nums[n-1];
        for (int i=1; i<n; ++i) {
            gr[i] = max(gr[i-1]+nums[n-1-i], nums[n-1-i]);
            fr[i] = max(fr[i-1], gr[i]);
        }

        int max_sub = INT_MIN;
        for (int i=0; i<n-1; ++i)
            max_sub = max(max_sub, f[i]+fr[n-2-i]);

        return max_sub;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int arr[] = { 1,3,-1,2,-1,2, -100, 3, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+n);

    int max_sum = s.maxTwoSubArrays(v);
    cout << "max_sum:" << max_sum << endl;

    return 0;
}
