#include <iostream>

using namespace std;

class Solution {
public:
    int aplusb(int a, int b) {
        int sum = 0;
        int carry = 0;
        for (int i=0; i<32; ++i) {
            int bita = (a>>i) & 1;
            int bitb = (b>>i) & 1;
            int bitsum = bita ^ bitb ^ carry;

            int count = 0;
            if (bita == 1)
                ++count;
            if (bitb == 1)
                ++count;
            if (carry == 1)
                ++count;
            if (count >= 2)
                carry = 1;
            else
                carry = 0;
            sum += bitsum << i;
        }
        return sum;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int a = -5;
    int b = -3;
    int sum = s.aplusb(a, b);
    cout << "sum:" << sum << endl;

    return 0;
}

