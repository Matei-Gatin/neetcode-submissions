/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        /*
            random pointer can be null or random
            create a deep copy of the list

            Node:
            - val
            - next
            - random
        */
        
        if (head == null) return null;

        Node tail = head;
        Map<Node, Node> nodeCopies = new HashMap<>();
        
        while (head != null) {
            nodeCopies.put(head, new Node(head.val));
            head = head.next;
        }

        Node curr = tail;
        while (curr != null) {
            Node twin = nodeCopies.get(curr);
            twin.next = nodeCopies.get(curr.next);
            twin.random = nodeCopies.get(curr.random);
            
            curr = curr.next;
        }

        return nodeCopies.get(tail);
   }
}