#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& v)
{
    vector<int>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int i = 0;
        int j = v.size() - 1;
        while (i < j) {
            if (v[i]+v[j] == target)
                break;
            else if (v[i]+v[j] < target)
                i++;
            else if (v[i]+v[j] > target)
                j--;
        }

        vector<int>::iterator it = find(nums.begin(), nums.end(), v[i]);
        int idx1 = it - nums.begin() + 1;
        if (v[i] != v[j])
            it = nums.begin();
        else
            ++it;
        int idx2 = find(it, nums.end(), v[j]) - nums.begin() + 1;
        int min_idx = min(idx1, idx2);
        int max_idx = max(idx1, idx2);
        vector<int> ret;
        ret.push_back(min_idx);
        ret.push_back(max_idx);
        return ret;
    }
};

int main(int argc, char *argv[])
{
    int arr[] = { 5, 75, 25 };
    // int arr[] = { 3, 4, 2, 9, 1, 20, 15, 6 };
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    vector<int> r = s.twoSum(v, 100);
    print(r);

    return 0;
}

