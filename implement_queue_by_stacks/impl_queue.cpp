#include <stack>
#include <iostream>

using namespace std;

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
    }

    void push(int element) {
        while (!stack2.empty()) {
            int v = stack2.top();
            stack2.pop();
            stack1.push(v);
        }
        stack1.push(element);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int v = stack1.top();
                stack1.pop();
                stack2.push(v);
            }
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

    int top() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int v = stack1.top();
                stack1.pop();
                stack2.push(v);
            }
        }

        return stack2.top();
    }
};

int main(int argc, char *argv[]) {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.top() << endl;
    q.push(40);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}
