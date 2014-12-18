#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& v)
{
    vector<int>::size_type i;
    for (i=0; i<v.size()-1; i++)
        cout << v[i] << ' ';
    cout << v[i] << endl;
}

class Solution {
public:
    vector<int> singleNumberIII(vector<int> &A) {
        int n = 0;
        for (size_t i=0; i!=A.size(); ++i)
            n ^= A[i];

        int mask = n & (n ^ (n-1));
        int a = 0;
        int b = 0;
        for (size_t i=0; i!=A.size(); ++i) {
            if ((A[i]&mask) == 0)
                a ^= A[i];
            else
                b ^= A[i];
        }
        vector<int> ret;
        ret.push_back(a);
        ret.push_back(b);
        return ret;
    }
};

int main(int argc, char *argv[])
{
    // int arr[] = { 1, 1, 4, 5, 7, 6, 3, 90, 90, 3, 5, 6, 4, 20 };
    // int arr[] = { 7, 20 };
    int arr[] = { -1, 2147483647 };
    vector<int> v;
    int arr_num = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<arr_num; ++i)
        v.push_back(arr[i]);

    Solution s;
    vector<int> ret = s.singleNumberIII(v);
    print(ret);

    return 0;
}
