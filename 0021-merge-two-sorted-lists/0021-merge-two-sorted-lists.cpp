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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode;
        ListNode* curr = list3;
        if ( !(list1 || list2) ) list3 = nullptr;
        while (list1 || list2) {
            if (list1 && list2) {
                if (list1->val <= list2->val) {
                    curr->val = list1->val;
                    curr->next = new ListNode;
                    curr = curr->next; list1 = list1->next;
                } else {
                    curr->val = list2->val;
                    curr->next = new ListNode;
                    curr = curr->next; list2 = list2->next;
                }
            } else if (list1 && !list2) {
                    curr->val = list1->val;
                    if (list1->next) curr->next = new ListNode; curr = curr->next; list1 = list1->next;
            } else if (!list1 && list2) {
                    curr->val = list2->val;
                    if (list2->next) curr->next = new ListNode; curr = curr->next; list2 = list2->next;
            }
        }
        return list3;
    }
};