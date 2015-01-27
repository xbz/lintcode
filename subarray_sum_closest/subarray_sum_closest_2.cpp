#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> subarraySumClosest(vector<int> nums){
        map<int, int> m;
        int cur_sum = 0;
        vector<int> v;
        vector<int> ret;
        m[cur_sum] = -1;
        for (size_t i=0; i<nums.size(); ++i) {
            cur_sum += nums[i];
            if (cur_sum == 0) {
                ret.push_back(0);
                ret.push_back(i);
                return ret;
            }
            m[cur_sum] = i;
            v.push_back(cur_sum);
        }

        sort(v.begin(), v.end());
        int min_diff = abs(v[0]);
        int idx1 = m[v[0]];
        int idx2 = m[v[0]];
        for (size_t i=1; i<v.size(); ++i) {
            if (abs(v[i]-v[i-1]) < min_diff) {
                min_diff = abs(v[i]-v[i-1]);
                idx1 = min(m[v[i]], m[v[i-1]]) + 1;
                idx2 = max(m[v[i]], m[v[i-1]]);
            }
        }
        ret.push_back(idx1);
        ret.push_back(idx2);
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { -20, 10, -30, 54, -18, 299, 11, -55, 99 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+n);

    vector<int> ret = s.subarraySumClosest(v);
    cout << "index:" << ret[0] << " " << ret[1] << endl;

    return 0;
}
