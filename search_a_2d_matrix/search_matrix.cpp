#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int lower = 0;
        int upper = matrix.size() - 1;
        int ret = -1;
        while (lower <= upper) {
            int mid = lower + (upper-lower)/2;
            vector<int> vmid = matrix[mid];
            if (target < vmid[0]) {
                upper = mid - 1;
            } else if (target > vmid[vmid.size()-1]) {
                lower = mid + 1;
            } else {
                ret = mid;
                break;
            }
        }
        if (ret == -1)
            return false;

        vector<int> v = matrix[ret];
        return binarySearch(&v[0], v.size(), target);
    }

private:
    bool binarySearch(int A[], int n, int target) {
        int lower = 0;
        int upper = n - 1;
        while (lower <= upper) {
            int mid = lower + (upper-lower)/2;
            if (A[mid] > target)
                upper = mid - 1;
            else if (A[mid] < target)
                lower = mid + 1;
            else
                return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int> > matrix;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(30);
    v2.push_back(50);
    vector<int> v3;
    v3.push_back(100);
    v3.push_back(300);
    v3.push_back(500);

    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);

    Solution s;
    int target = atoi(argv[1]);
    bool isfound = s.searchMatrix(matrix, target);
    cout << "found:" << isfound << endl;

    return 0;
}
