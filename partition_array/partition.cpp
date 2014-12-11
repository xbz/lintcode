#include <iostream>
#include <vector>
#include <climits>

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
    int partitionArray(vector<int> &nums, int k) {
        if (nums.size() <= 1)
            return 0;

        int i = 0;
        int j = nums.size() - 1;
        int cur = 0;
        while (cur <= j) {
            if (nums[cur] < k) {
                swap(nums, cur, i);
                ++cur;
                ++i;
            } else if (nums[cur] > k) {
                swap(nums, cur, j);
                --j;
            } else {
                ++cur;
            }
        }
        return i;
    }

private:
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums;
    nums.push_back(14);
    nums.push_back(10);
    nums.push_back(7);
    nums.push_back(3);
    nums.push_back(1);
    int k = 5;
    print(nums);
    int part_idx = s.partitionArray(nums, k);
    print(nums);
    cout << "partition index:" << part_idx << endl;

    return 0;
}
