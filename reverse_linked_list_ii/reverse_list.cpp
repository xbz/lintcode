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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n)
            return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *preSub = dummy;
        for (int move=m-1; move>0; move--)
            preSub = preSub->next;

        ListNode *tailSub = preSub->next;
        ListNode *headSub = tailSub;
        ListNode *postSub = tailSub->next;
        int nstep = n - m;
        while (nstep > 0) {
            ListNode *third = postSub->next;
            postSub->next = tailSub;
            tailSub = postSub;
            postSub = third;
            --nstep;
        }
        headSub->next = postSub;
        preSub->next = tailSub;
        return dummy->next;
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
    p = p->next;
    p->next = new ListNode(200);
    print(head);

    int m = 2;
    int n = 4;
    ListNode *rhead = s.reverseBetween(head, m, n);
    print(rhead);

    return 0;
}
