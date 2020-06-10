/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null) {
            return true;
        }
        int n = 0;
        ListNode node = head;
        while(node != null) {
            n++;
            node = node.next;
        }
        if (n == 1) {
            return true;
        }
        node = head;
        for (int i = 0 ; i < n/2 ; i++) {
            node = node.next;
        }
        if ((n & 1) > 0) {
            node = node.next;
        }
        ListNode pre = null;
        ListNode next = node.next;
        while (node != null) {
            next = node.next;
            node.next = pre;
            pre = node;
            node = next;
        }
        node = head;
        while (pre != null) {
            if (pre.val != node.val) {
                return false;
            }
            pre = pre.next;
            node = node.next;
        }
        return true;
    }
}