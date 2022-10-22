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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        if (!curr) return nullptr;
        if (!curr->next) {
            if (curr->val == val) return nullptr;
            else return head;
        }
        while (curr) {
            if (curr->val == val) {
                if (curr == head) {
                    head = head->next;
                    delete(curr);
                    curr = head;
                } else {
                    pre->next = curr->next;
                    delete(curr);
                    curr = pre->next;
                }
            } else {
                pre = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};