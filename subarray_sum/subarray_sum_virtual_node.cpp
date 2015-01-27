#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> subarraySum(vector<int> nums){
        unordered_map<int, int> m;
        vector<int> ret;
        int cur_sum = 0;
        // virtual node
        m.insert(make_pair(cur_sum, -1));
        for (size_t i=0; i<nums.size(); ++i) {
            cur_sum += nums[i];
            unordered_map<int, int>::iterator it = m.find(cur_sum);
            if (it != m.end()) {
                ret.push_back(it->second+1);
                ret.push_back(i);
                break;
            }

            m.insert(make_pair(cur_sum, i));
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { 10, -2, 10, -3, 4, -1, 2, 1, -5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+n);

    vector<int> ret = s.subarraySum(v);
    cout << "index:" << ret[0] << " " << ret[1] << endl;

    return 0;
}
