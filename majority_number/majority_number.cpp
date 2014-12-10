#include <iostream>
#include <vector>
#include <map>

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
    int majorityNumber(vector<int> nums) {
        map<int, int> m;
        int max_count = -1;
        int majo = -1;
        for (size_t i=0; i!=nums.size(); ++i) {
            m[nums[i]] = m[nums[i]] + 1;
            int cur_count = m[nums[i]];
            if (cur_count > max_count) {
                max_count = cur_count;
                majo = nums[i];
            }
        }
        return majo;
    }
};

int main(int argc, char* argv[]) {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);

    Solution s;
    print(v);
    int majo = s.majorityNumber(v);
    cout << "mojority number:" << majo << endl;

    return 0;
}
