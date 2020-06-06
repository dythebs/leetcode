/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if (root == null) return null;
        Node levelRight = null;
        Node next = root.next;
        while (next != null && next.next != null) {
            if (next.left != null || next.right != null) {
                break;
            }
            next = next.next;
        }
        if (next != null) {
            if (next.left != null) {
                levelRight = next.left;
            } else {
                levelRight = next.right;
            }
        }
        if (root.left != null) {
            if (root.right != null) {
                root.left.next = root.right;
            } else {
                root.left.next = levelRight;
            }
        }
        if (root.right != null) {
            root.right.next = levelRight;
        }
        connect(root.right);
        connect(root.left);
        return root;
    }
}