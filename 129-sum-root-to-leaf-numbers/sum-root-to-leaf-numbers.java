class Solution {
    private int dfs(TreeNode root, String pathSum){
        if(root == null)
            return 0;

        pathSum += String.valueOf(root.val);

        if(root.left == null && root.right == null)
            return Integer.parseInt(pathSum);
            
        return dfs(root.left, pathSum) + dfs(root.right, pathSum);
    }
    
    public int sumNumbers(TreeNode root) {
        return dfs(root, "");
    }
}
