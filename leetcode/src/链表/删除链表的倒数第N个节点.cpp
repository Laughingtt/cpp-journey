
#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {

    }
};


int main() {
    Solution s;
    ListNode head;
    ListNode* node = &head;
    cout << &head << endl;
    cout << &node << endl;

    for (int i = 1; i < 6; ++i) {
        node->val = i;
        cout << "node info" << node->val << endl;
        ListNode tmp;
        node->next = &tmp;
        node = node->next;
    }

    cout << "node info" << head.val << endl;
    cout << "node info" << head.next->val << endl;
    cout << "node info" << head.next->next->val << endl;

}