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
    ListNode* merge(ListNode *l1, ListNode* l2)
    {
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

        current->next = (l1!=nullptr)?(l1):(l2);
        return dummy -> next;
    }
    ListNode* mergeHelper(vector<ListNode*>& lists, int start, int end)
    {
        if(start == end) 
            return lists[start];
        if(start == end - 1) 
            return merge(lists[start], lists[end]);

        int mid = start + (end - start)/2;

        ListNode* left = mergeHelper(lists, start, mid);
        ListNode* right = mergeHelper(lists, mid + 1, end);

        return merge(left, right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        
        return mergeHelper(lists, 0, lists.size() - 1);
    }
};