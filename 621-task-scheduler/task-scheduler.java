class Solution {
    public int leastInterval(char[] tasks, int n){
        int[] map = new int[26];
        for (char c : tasks)
            map[c - 'A']++;
        Arrays.sort(map);
        int maxVal = map[25] - 1;
        int idleSllots = maxVal * n;
        for (int i = 24; i >= 0 && map[i] > 0; i--) {
            idleSllots -= Math.min(map[i], maxVal);
        }
        return idleSllots > 0 ? idleSllots + tasks.length : tasks.length;
    }
}