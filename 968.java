/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int minCameraCover(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (dfs(root) == NO_CAMERA) {
            sum++;
        }
        return sum;
    }

    private int dfs(TreeNode node) {
        if (node == null) {
            return NO_DEEDED;
        }
        int l = dfs(node.left);
        int r = dfs(node.right);
        if (l == NO_CAMERA || r == NO_CAMERA) {
            sum++;
            return HAS_CAMERA;
        }
        if (l == HAS_CAMERA || r == HAS_CAMERA) {
            return NO_DEEDED;
        }
        return NO_CAMERA;
    }

    private int sum = 0;

    private final int NO_CAMERA = 0;
    private final int HAS_CAMERA = 1;
    private final int NO_DEEDED = 2;
}