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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //initializing tem and temp so that l1 and l2 reamins preserved,
        //though this isn't needed but it a good practice
        ListNode* temp=l1;
        ListNode* tem=l2;
        ListNode *ans;
        ListNode *head;
        int carry=0;
        int valu;
        //initiallize the first node of answer
        int sum=tem->val+temp->val+carry;
        valu=sum%10;
        carry=sum/10;
        ListNode* node =new ListNode(valu);
        ans=node;
        head=ans;
        tem=tem->next;
        temp=temp->next;
        while(tem!=NULL && temp!=NULL)
        {
            sum=tem->val+temp->val+carry;
            valu=sum%10;
            carry=sum/10;
            ListNode* node =new ListNode(valu);
            ans->next=node;
            ans=ans->next;
            temp=temp->next;
            tem=tem->next;
        }
        //if l1 gets over and there are still some elements in l2
        if(tem==NULL && temp!=NULL)
        {
            while(temp!=NULL)
            {
                sum=temp->val+carry;
                valu=sum%10;
                carry=sum/10;
                ListNode* node =new ListNode(valu);
                ans->next=node;
                ans=ans->next;
                temp=temp->next;
            }
        }
        //if l2 gets over and there are still some elements in l1
        if(tem!=NULL && temp==NULL)
        {
            while(tem!=NULL)
            {
                sum=tem->val+carry;
                valu=sum%10;
                carry=sum/10;
                ListNode* node =new ListNode(valu);
                ans->next=node;
                ans=ans->next;
                tem=tem->next;
            }
        }
        //if there is still a carry left
        if(carry!=0)
        {
            ListNode* node =new ListNode(carry);
            ans->next=node;
        }
        return head;
    }
};