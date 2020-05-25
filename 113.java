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
    private ArrayList<Integer> tempList = new ArrayList<>();
    private ArrayList<List<Integer>> ansList = new ArrayList<>();

    private void dfs(TreeNode node, int sumTarget, int sum) {
        if (node == null) return;
        if (node.left == null && node.right == null) {
            if (sum + node.val == sumTarget) {
                tempList.add(node.val);
                ansList.add(new ArrayList<Integer>(tempList));
                tempList.remove(tempList.size()-1);
                return;
            }
        }
        tempList.add(node.val);
        dfs(node.left, sumTarget, sum + node.val);
        dfs(node.right, sumTarget, sum + node.val);
        tempList.remove(tempList.size()-1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        dfs(root, sum, 0);
        return ansList;
    }
}