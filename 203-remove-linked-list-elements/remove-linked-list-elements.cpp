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
        if (!head) {
            return nullptr;
        }

        // Handle the case where the head contains the value to be removed
        if (head->val == val) {
            ListNode* newHead = head->next;
            delete head;
            return removeElements(newHead, val);
        }

        // Handle the rest of the list
        head->next = removeElements(head->next, val);
        return head;
    }
};
