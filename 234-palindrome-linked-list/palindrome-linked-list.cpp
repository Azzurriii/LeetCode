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
    bool isPalindrome(ListNode* head) {
        // Method 1 -> TC = O(N) , SC = O(1)
        if(head == NULL){
            return true;
        }

        if(head->next == NULL){
            return true;
        }
        
        // STEP 1 -  first find middle node
        // 1 -> 2 -> 3 -> 2 -> 1
        ListNode *s = head;
        ListNode *f = head->next; // in case of even, 1st middle node

        while(f!= NULL){
            f = f->next;
            if(f!= NULL){
                f = f->next;
                s = s->next;
            }
        }

        // STEP 2 - reverse LL after middle node
        // 1 -> 2 -> 3 -> 1 -> 2
        ListNode *p = NULL, *q = NULL, *r = s->next;

        while(r!= NULL){
            p = q;
            q = r;
            r = r->next;
            q->next = p;
        }

        s->next = q;

        // cout<<"after reversing"<<endl;
        // ListNode *temp = head;
        // while(temp != NULL ){
        //     cout<<temp->val<<" ";
        //     temp = temp->next;
        // }


        // STEP 3 - Traverse before middle and after middle and check whether thet are same or not
        // 1 -> 2 -> 3 -> 1 -> 2
        // |              |
        // first          second
        ListNode * second = s->next;
        ListNode * first = head;
        while(second != NULL){
            if(first->val != second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        
        return true;
    }
};