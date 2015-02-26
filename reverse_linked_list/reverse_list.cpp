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
        if (head==NULL || head->next==NULL)
            return head;

		ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode *reverse_orig(ListNode *head) {
        stack<ListNode *> s;
        while (head) {
            s.push(head);
            head = head->next;
        }

        ListNode *p = new ListNode(-1);
        ListNode *rhead = p;
        while (!s.empty()) {
            ListNode *cur = s.top();
            s.pop();
            p->next = new ListNode(cur->val);
            p = p->next;
        }
        return rhead->next;
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
