#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>

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
	// on lintcode, sometimes accept, sometimes TLE
	int longestIncreasingSubsequence(vector<int> nums) {
		if (nums.size() == 0)
			return 0;

		int ret = 1;
		for (size_t i=0; i<nums.size(); ++i)
			ret = max(ret, lis(nums, i));
		return ret;
	}


private:
	int lis(const vector<int>& v, size_t pos) {
		if (pos == 0)
			return 1;

		int ret = 1;
		for (size_t i=0; i<pos; ++i) {
			if (v[i] <= v[pos])
				ret = max(ret, lis(v, i)+1);
		}
		return ret;
	}
};

class Solution_dfs {
public:
	int longestIncreasingSubsequence(vector<int> nums) {
		if (nums.size() == 0)
			return 0;

		vector<pair<int, int> > path;
		size_t lis = 1;
		// for (int i=nums.size(); i>=2; i--) {
		for (size_t i=2; i<=nums.size(); i++) {
			find_lis(path, nums, 0, i, lis);
			// if (lis > 1)
			// 	return lis;
		}
		return lis;
    }

private:
	void find_lis(vector<pair<int, int> >& path, const vector<int>& v, size_t pos,
				  size_t len, size_t& lis) {
		if (path.size() == len)
			lis = max(lis, len);

		for (size_t i=pos; i<v.size(); ++i) {
			if (lis == len)
				return;
			if (path.size()>0 && v[i]<path.back().first)
				continue;

			path.push_back(make_pair(v[i], i));
			find_lis(path, v, i+1, len, lis);
			path.pop_back();
		}
	}
};

class Solution_HashSet {
public:
	int longestIncreasingSubsequence(vector<int> nums) {
		if (nums.size() == 0)
			return 0;

		vector<pair<int, int> > path;
		size_t lis = 1;
		unordered_set<int> s;
		// for (int i=nums.size(); i>=2; i--) {
		for (size_t i=2; i<=nums.size(); i++) {
			find_lis(path, nums, s, 0, i, lis);
			// if (lis > 1)
			// 	return lis;
		}
		return lis;
    }

private:
	void find_lis(vector<pair<int, int> >& path, const vector<int>& v,
				  unordered_set<int>& s, size_t pos,
				  size_t len, size_t& lis) {
		if (path.size() == len) {
			lis = max(lis, len);
			for (size_t i=0; i<path.size(); ++i)
				s.insert(path[i].second);
		}

		for (size_t i=pos; i<v.size(); ++i) {
			if (i==pos && path.size()==0 && s.count(i)>0)
				continue;
			if (path.size()>0 && v[i]<path.back().first)
				continue;

			path.push_back(make_pair(v[i], i));
			find_lis(path, v, s, i+1, len, lis);
			path.pop_back();
		}
	}
};

int main(int argc, char *argv[])
{
    Solution s;
    // int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int arr[] = { 99,55,7,29,80,33,19,23,6,35,40,27,44,74,5,17,52,36,67,32,37,42,18,77,66,62,97,79,60,94,30,2,85,22,26,91,3,16,8,0,48,93,39,31,63,13,71,58,69,50,21,70,61,43,12,88,47,45,72,76 };
    // int arr[] = { 4, 2, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+n);

    int lis = s.longestIncreasingSubsequence(v);
    cout << "long increasing subseq:" << lis << endl;

    return 0;
}
