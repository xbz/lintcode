#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> nums) {
        int n = nums.size();
        int f[n];
        f[0] = nums[0];
        int g[n];
        g[0] = nums[0];

        for (int i=1; i<n; ++i) {
            g[i] = nums[i];
            if (g[i-1] > 0)
                g[i] += g[i-1];
            f[i] = max(f[i-1], g[i]);
        }
        return f[n-1];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+n);

    int max_sum = s.maxSubArray(v);
    cout << "max_sum:" << max_sum << endl;

    return 0;
}
