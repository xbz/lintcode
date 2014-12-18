#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumberII(vector<int> &A) {
        int ret = 0;
        for (int i=0; i!=32; ++i) {
            int bit = 0;
            for (size_t j=0; j!=A.size(); ++j) {
                bit += (A[j]>>i) & 1;
                bit %= 3;
            }
            ret += bit << i;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    int arr[] = { 1, 5, 3, 1, 4, 5, 6, 3, 90, 90, 1, 3, 5, 6, 4, 20, 6, 4, 90 };
    vector<int> v;
    int arr_num = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<arr_num; ++i)
        v.push_back(arr[i]);

    Solution s;
    int single = s.singleNumberII(v);
    cout << single << endl;
    return 0;
}
