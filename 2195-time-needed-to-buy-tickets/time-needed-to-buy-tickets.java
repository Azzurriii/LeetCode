class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        int time = 0;
        for(int i = 0; i < n; i++){
            if(i <= k)
                time += Math.min(tickets[i], tickets[k]);
            else
                time += Math.min(tickets[i], tickets[k] - 1);
        }
        return time;
    }
}