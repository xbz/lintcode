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
        int ma_number = 0;
        int ma_n = 0;
        for (size_t i=0; i!=nums.size(); ++i) {
            if (ma_n == 0) {
                ma_number = nums[i];
                ma_n++;
            } else {
                if (ma_number == nums[i])
                    ma_n++;
                else
                    ma_n--;
            }
        }
        return ma_number;
    }
};

int main(int argc, char* argv[]) {
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    // v.push_back(2);
    // v.push_back(2);

    Solution s;
    print(v);
    int majo = s.majorityNumber(v);
    cout << "mojority number:" << majo << endl;

    return 0;
}
