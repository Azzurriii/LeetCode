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
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while(l1&&l2){
            if(l1->val < l2->val){
                current->next = l1;
                l1 = l1->next;
            }
            else{
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        current->next = (l1)?(l1):(l2);
        return dummy -> next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
            return head;

        ListNode* temp = nullptr;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast&&fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return mergeList(l1, l2);
    }
};