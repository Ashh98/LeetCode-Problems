/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseListOP(ListNode* head, ListNode* pre, ListNode* curr) {
        ListNode* nxt;
        if (curr == head) {
            nxt = curr->next;
            curr->next = nullptr;
            pre = curr;
            curr = nxt;
        }
        if (curr->next == nullptr)  {
            curr->next = pre;
            head = curr;
        }
        else {
            //cout << curr->val << endl;
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
            head = reverseListOP(head, pre, curr);
        }
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        else if (!head->next) return head;
        else return reverseListOP(head, nullptr, head);
    }
};