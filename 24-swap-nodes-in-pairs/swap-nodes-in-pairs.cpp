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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy;
        
        while(current->next && current->next->next)
        {
            ListNode *first = current->next;
            ListNode *second = current->next->next;

            first->next = second->next;
            second->next = first;
            current->next = second;

            current = current->next->next;
        }

        return dummy->next;
    }
};