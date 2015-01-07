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
        int left = 0;
        int right = A.size() - 1;
        while (left < right) {
            int mid = (left+right) / 2;
            if (A[mid]>A[mid-1] && A[mid]>A[mid+1])
                return mid;
            if (A[mid] <= A[mid+1])
                left = mid;
            else
                right = mid;
        }
        return -1;
    }
};

int main(int argc, char *argv[])
{
    int arr[] = { 3, 4, 5, 6, 7, 20, 15, 6 };
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    int peak = s.findPeak(v);
    print(v);
    cout << "peak:" << peak << endl;

    return 0;
}

