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
    int findPeak(vector<int> A) {
        int peak = -1;
        for (size_t i=1; i<A.size()-1; ++i) {
            if (A[i]<=A[i-1])
                continue;
            if (A[i]<=A[i+1])
                continue;

            return i;
        }
        return peak;
    }
};

int main(int argc, char *argv[])
{
    int arr[] = { 3, 4, 2, 9, 1, 20, 15, 6 };
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    int peak = s.findPeak(v);
    print(v);
    cout << "peak:" << peak << endl;

    return 0;
}

