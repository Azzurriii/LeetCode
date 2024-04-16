/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int x) { val = x; }
 *     TreeNode(int x, TreeNode left, TreeNode right) { val = x; this.left = left; this.right = right; }
 * }
 */

class Solution {
    private void dfs(TreeNode root, int level, int depth, int val) {
        if (root == null)
            return;
        if (level == depth - 1) {
            TreeNode left = new TreeNode(val);
            TreeNode right = new TreeNode(val);
            left.left = root.left;
            right.right = root.right;
            root.left = left;
            root.right = right;
            return;
        }
        dfs(root.left, level + 1, depth, val);
        dfs(root.right, level + 1, depth, val);
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }
        dfs(root, 1, depth, val);
        return root;
    }
}

