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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = head;
        ListNode* curr = nullptr;
        ListNode* nxt = nullptr;
        if (pre->next) {
            curr = pre->next;
            if (curr->next) {
                nxt = curr->next;
            } else {
                head->next = nullptr;
                curr->next = head;
                return curr;
            }
        } else {
            return head;
        }
        while (true) {
            if (!nxt) {
                curr->next = pre;
                head = curr;
                return head;
            } else if (pre == head) {
                pre->next = nullptr;
                curr->next = pre;
                pre = curr;
                curr = nxt;
                nxt = nxt->next;
            } else {
                curr->next = pre;
                pre = curr;
                curr = nxt;
                nxt = nxt->next;
            }
        }
        return nullptr;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* sPtr = head;
        ListNode* fPtr = head;
        ListNode* curr = head;
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }
        if (count == 1) return true;
        else if (count == 2) {
            if (head->val == head->next->val) return true;
            else return false;
        }
        curr = head;
        if (count % 2 == 0) {
            int c = 0;
            while (true) {
                c++;
                if (c == count/2) {
                    fPtr = curr->next;
                    curr->next = nullptr;
                    break;
                }
                curr = curr->next;
            }
            fPtr = reverseList(fPtr);
            while (sPtr && fPtr) {
                if (sPtr->val != fPtr->val) return false;
                else {
                    sPtr = sPtr->next;
                    fPtr = fPtr->next;
                }
            }
        } else {
            int c = 0;
            while (true) {
                c++;
                if (c == (count-1)/2) {
                    fPtr = curr->next->next;
                    curr->next->next = nullptr;
                    curr->next = nullptr;
                    break;
                }
                curr = curr->next;
            }
            fPtr = reverseList(fPtr);
            while (sPtr && fPtr) {
                if (sPtr->val != fPtr->val) return false;
                else {
                    sPtr = sPtr->next;
                    fPtr = fPtr->next;
                }
            }
        }
        return true;
    }
};