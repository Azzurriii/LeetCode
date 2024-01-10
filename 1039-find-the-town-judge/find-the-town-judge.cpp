class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		vector<int>adj[n];
		for(int i=0; i<trust.size(); i++){
			adj[trust[i][0]-1].push_back(trust[i][1]-1);
		}
		vector<int>v(n, 0);
		for(int i=0; i<n; i++){
			for(auto it: adj[i]){
				v[it]++;
			}
		}
		for(int i=0; i<n; i++){
			if(adj[i].size()==0 && v[i]==n-1){return i+1;}
		}
		return -1;
	}
};