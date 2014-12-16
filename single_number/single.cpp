#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &A) {
        int ret = 0;
        for (size_t i=0; i!=A.size(); ++i)
            ret ^= A[i];
        return ret;
    }
};

int main(int argc, char *argv[])
{
    int arr[] = { 1, 3, 4, 5, 6, 90, 90, 1, 3, 5, 6, 4, 20 };
    vector<int> v;
    int arr_num = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<arr_num; ++i)
        v.push_back(arr[i]);

    Solution s;
    int single = s.singleNumber(v);
    cout << single << endl;
    return 0;
}
