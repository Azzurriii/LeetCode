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
private:
    void reverseHelper(ListNode* &head, ListNode* curr, ListNode* prev)
    {
        if(!curr){
            head = prev;
            return;
        }
        reverseHelper(head, curr->next, curr);
        curr->next = prev;
    }
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        reverseHelper(head, curr, prev);
        return head;
    }
};