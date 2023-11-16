// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// private:
//     ListNode* mergeList(ListNode* l1, ListNode* l2){
//         ListNode* dummy = new ListNode(0);
//         ListNode* current = dummy;
//         while(l1&&l2){
//             if(l1->val < l2->val){
//                 current->next = l1;
//                 l1 = l1->next;
//             }
//             else{
//                 current->next = l2;
//                 l2 = l2->next;
//             }
//             current = current->next;
//         }

//         current->next = (l1)?(l1):(l2);
//         return dummy -> next;
//     }
// public:
//     ListNode* sortList(ListNode* head) {
//         if(!head||!head->next)
//             return head;

//         ListNode* temp = nullptr;
//         ListNode* fast = head;
//         ListNode* slow = head;

//         while(fast&&fast->next){
//             temp = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         temp->next = nullptr;

//         ListNode* l1 = sortList(head);
//         ListNode* l2 = sortList(slow);

//         return mergeList(l1, l2);
//     }
// };
							// \U0001f609\U0001f609\U0001f609\U0001f609Please upvote if it helps \U0001f609\U0001f609\U0001f609\U0001f609
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //If List Contain a Single or 0 Node
        if(head == NULL || head ->next == NULL)
            return head;
        
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2
            
        }   
        temp -> next = NULL;            //end of first left half
        
        ListNode* l1 = sortList(head);    //left half recursive call
        ListNode* l2 = sortList(slow);    //right half recursive call
        
        return mergelist(l1, l2);         //mergelist Function call
            
    }
    
    //MergeSort Function O(n*logn)
    ListNode* mergelist(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
        
        curr = curr ->next;
        
        }
        
        //for unqual length linked list
        
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
    }
};