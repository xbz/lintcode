#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
        s_.push(x);
        if (min_s_.empty()) {
            min_s_.push(x);
        } else {
            int cur_min = min();
            int new_min = x>cur_min ? cur_min : x;
            min_s_.push(new_min);
        }
    }

    int pop() {
        int n = s_.top();
        s_.pop();
        min_s_.pop();
        return n;
    }

    int min() {
        return min_s_.top();
    }

private:
    stack<int> s_;
    stack<int> min_s_;
};

int main(int argc, char *argv[])
{
    MinStack s;
    s.push(5);
    s.push(3);
    s.push(4);
    s.push(3);
    s.push(10);

    cout << "min:" << s.min() << endl;
    s.pop();
    cout << "min:" << s.min() << endl;
    s.pop();
    cout << "min:" << s.min() << endl;
    s.pop();
    cout << "min:" << s.min() << endl;
    s.pop();
    cout << "min:" << s.min() << endl;

    return 0;
}
