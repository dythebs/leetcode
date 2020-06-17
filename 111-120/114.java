/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private TreeNode flatten0(TreeNode node) {
        if (node == null) return null;
        if (node.left == null && node.right == null) {
            return node;
        }
        if (node.left == null) {
            return flatten0(node.right);
        } else if (node.right == null) {
            node.right = node.left;
            node.left = null;
            return flatten0(node.right);
        }
        TreeNode rightLast = flatten0(node.left);
        TreeNode rightNode = node.right;
        node.right = node.left;
        node.left = null;
        rightLast.right = rightNode;
        return flatten0(node.right);
    }
    public void flatten(TreeNode root) {
        flatten0(root);
    }
}