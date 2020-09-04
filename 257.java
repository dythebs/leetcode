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
    public List<String> binaryTreePaths(TreeNode root) {
        if (root == null) {
            return ans;
        }
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode node) {
        if (node.left == null && node.right == null) {
            temp.add(String.valueOf(node.val));
            ans.add(String.join("->", temp));
            temp.remove(temp.size()-1);
            
        }
        temp.add(String.valueOf(node.val));
        if (node.left != null) {
            dfs(node.left);
        }
        if (node.right != null) {
            dfs(node.right);
        }
        temp.remove(temp.size()-1);
    }
    List<String> ans = new ArrayList<>();
    List<String> temp = new ArrayList<>();
}