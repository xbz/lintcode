#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> subarraySumClosest(vector<int> nums){
        int cur_sum = 0;
        vector<pair<int, int> > v;
        v.push_back(make_pair(cur_sum, -1));
        for (size_t i=0; i<nums.size(); ++i) {
            cur_sum += nums[i];
            v.push_back(make_pair(cur_sum, i));
        }

        sort(v.begin(), v.end());
        long long min_diff = LONG_LONG_MAX;
        vector<int> ret(2);
        for (size_t i=1; i<v.size(); ++i) {
            long long diff = abs(v[i].first - v[i-1].first);
            if (diff < min_diff) {
                min_diff = diff;
                ret[0] = min(v[i].second, v[i-1].second) + 1;
                ret[1] = max(v[i].second, v[i-1].second);
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { -2147483648 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+n);

    vector<int> ret = s.subarraySumClosest(v);
    cout << "index:" << ret[0] << " " << ret[1] << endl;

    return 0;
}
