/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> map;
        ListNode* current = head;
        while(current){
            if(map.find(current) != map.end())
                return true;
            map[current] = current->val;
            current = current->next;
        }
        return false;
    }
};
auto speedup = cin.tie(NULL) -> sync_with_stdio(false);