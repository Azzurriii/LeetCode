/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode aNode = list1;
        for (int i = 0; i < a - 1; i++) {
            aNode = aNode.next;
        }
        ListNode bNode = aNode;
        for (int i = 0; i < b - a + 2; i++) {
            bNode = bNode.next;
        }
        aNode.next = list2;
        ListNode lastNode = list2;
        while (lastNode.next != null) {
            lastNode = lastNode.next;
        }
        lastNode.next = bNode;
        return list1;
    }
}