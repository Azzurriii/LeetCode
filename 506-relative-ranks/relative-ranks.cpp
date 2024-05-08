class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        priority_queue<pair<int, int>> heap;
        for(int i = 0; i < n; i++){
            heap.push({score[i], i});
        }

        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        vector<string> result(n);
        int ranking = 1;
        while(!heap.empty()){
            int index = heap.top().second;
            heap.pop();
            if(ranking < 4){
                result[index] = medals[ranking - 1];
            }
            else{
                result[index] = to_string(ranking);
            }
            ranking++;
        }

        return result;
    }
};