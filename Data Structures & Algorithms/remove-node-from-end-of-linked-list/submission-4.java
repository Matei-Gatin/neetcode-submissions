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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // get length of list
        // calculate deletion index
        // delete at that index

        ListNode dummy = new ListNode(0, head);
        ListNode tail = dummy;

        int l = 0;
        while (head != null) {
            head = head.next;
            l++;
        }

        int indexToDelete = l - n; // 0 based
        for (int i = 0; i < indexToDelete; i++) {
            tail = tail.next;
        }

        tail.next = tail.next.next;

        return dummy.next;
    }
}
