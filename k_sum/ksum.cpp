#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <map>

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
    int kSum(vector<int> A, int k, int target) {
        if (k == 1) {
            vector<int>::iterator it = find(A.begin(), A.end(), target);
            if (it == A.end())
                return 0;
            else
                return 1;
        }

        sort(A.begin(), A.end());
        return helper(A.begin(), A.end(), k, target);
    }

private:
    int helper(vector<int>::iterator start,
               vector<int>::iterator end,
               int k, int target) {
        if (end-start < k)
            return 0;

        if (k == 2) {
            cout << "k==2" << endl;
            int n = 0;
            // last element
            --end;
            while (start < end) {
                int sum = *start + *end;
                if (sum == target) {
                    ++n;
                    ++start;
                    --end;
                } else if (sum > target) {
                    --end;
                } else {
                    ++start;
                }
            }
            return n;
        }

        int n = 0;
        while (start < end) {
            n += helper(start+1, end, k-1, target-*start);
            ++start;
        }
        return n;
    }
};

int main(int argc, char *argv[])
{
    //int arr[] = { 0, 4, 3, 0 };
    int arr[] = {1,3,4,5,8,10,11,12,14,17,20,22,24,25,28,30,31,34,35,37,38,40,42,44,45,48,51,54,56,59,60,61,63,66};

    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    int k = 24;
    int target = 842;
    cout << v.size() << endl;
    int n = s.kSum(v, k, target);
    cout << n << " ksum solutions" << endl;

    return 0;
}

