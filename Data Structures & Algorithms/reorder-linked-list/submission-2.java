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
    public void reorderList(ListNode head) {
        // SPLIT the list
        // REVERSE
        // MERGE / ZIP
        // 2, 10, 4, 8, 6 -> 10, 2, 4

        ListNode slow = head;
        ListNode fast = head;

        ListNode firstHalf;
        ListNode secondHalf;
        ListNode secondHalfReversed;
        
        // SPLIT
        while (fast != null && fast.next != null) {
            slow = slow.next; // 4 
            fast = fast.next.next; // 6 
        }

        secondHalf = slow.next;
        slow.next = null;
        firstHalf = head;

        // REVERSE
        secondHalfReversed = reverse(secondHalf);

        // ZIP
        ListNode temp1, temp2;
        while (firstHalf != null && secondHalfReversed != null) {
            temp1 = firstHalf.next;
            temp2 = secondHalfReversed.next;

            firstHalf.next = secondHalfReversed;
            secondHalfReversed.next = temp1;

            firstHalf = temp1;
            secondHalfReversed = temp2;
        }
    }

    private ListNode reverse(ListNode head) {
        ListNode curr = head, prev = null, next;

        while (curr != null) {
            next = curr.next;

            curr.next = prev;
            
            prev = curr; 
            curr = next;
        }

        return prev;
    }
}
