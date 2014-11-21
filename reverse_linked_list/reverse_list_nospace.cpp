#include <iostream>
#include <stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(const ListNode *head)
{
    while (head) {
        cout << head->val << " ";
        head =  head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *reverse(ListNode *head) {
        if (!head || !head->next)
            return head;
		ListNode *first = head;
        ListNode *second = head->next;
        head->next = NULL;
        while (second) {
            ListNode *third = second->next;
            second->next = first;
            first = second;
            second = third;
        }
        return first;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    ListNode *head = new ListNode(10);
    ListNode *p = head;
    p->next = new ListNode(50);
    p = p->next;
    p->next = new ListNode(70);
    p = p->next;
    p->next = new ListNode(3);
    print(head);

    ListNode *rhead = s.reverse(head);
    print(rhead);

    return 0;
}
