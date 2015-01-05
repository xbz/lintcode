#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int digitCounts(int k, int n) {
        int d = digit_num(n);
        int ret = 0;
        for (int i=1; i<d; ++i)
            ret += digit_count(k, i);

    }

private:
    int digit_num(int n) {
        if (n == 0)
            return 1;

        int digit = 0;
        while (n > 0) {
            digit++;
            n /= 10;
        }
        return digit;
    }

    int digit_count(int k, int digit) {
        if (digit == 1)
            return 1;

        int ret = 9*pow(10,digit-2)*(digit-1);
        if (k > 0)
            ret += pow(10,digit-1);
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int k = 1;
    int n = 12;
    int count = s.digitCounts(k, n);
    cout << "count:" << count << endl;

    return 0;
}

