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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // dummy node
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        int carry = 0;

        while (l1 != null || l2 != null || carry > 0) {
            // check if l1 or l2 are not null and assign val1 and val2
            int val1 = 0, val2 = 0;
            if (l1 != null) val1 = l1.val;
            if (l2 != null) val2 = l2.val;
            
            // calculate the sum of val1 and val2
            int sum = val1 + val2 + carry;

            // strip out firstDigit and lastDigit
            int firstDigit = sum / 10; // carry
            int lastDigit = sum % 10; // adder 
            
            carry = firstDigit;

            // append the result to the LinkedList
            tail.next = new ListNode(lastDigit); 

            // move pointers
            tail = tail.next;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }

        return dummy.next;
    }
}
