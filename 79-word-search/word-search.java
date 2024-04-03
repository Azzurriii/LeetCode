class Solution {
    public boolean exist(char[][] board, String word) {
        if (board == null || board.length == 0)
            return false;
        int m = board.length, n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                boolean found = backtrack(board, visited, i, j, word, 0);
                if (found)
                    return true;
            }
        }
        return false;
    }

    private boolean backtrack(char[][] board, boolean[][] visited, int i, int j, String word, int index) {
        if (index == word.length())
            return true;
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length)
            return false;
        if (visited[i][j] || board[i][j] != word.charAt(index))
            return false;
        visited[i][j] = true;
        if (backtrack(board, visited, i + 1, j, word, index + 1) ||
                backtrack(board, visited, i - 1, j, word, index + 1) ||
                backtrack(board, visited, i, j + 1, word, index + 1) ||
                backtrack(board, visited, i, j - 1, word, index + 1)) {
            return true;
        }
        visited[i][j] = false;
        return false;
    }
}