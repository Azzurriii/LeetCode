class Solution {
public:
    int mod=1e9+7;
    int power(int a,int n,int mod)
    {
        long long res=1;
        while(n>0)
        {
            if(n%2!=0)
                res=((long long)res*a)%mod;
            n=n>>1;
            a=((long long)a*a)%mod;
        }
        return res;
    }
    int numberOfGoodPartitions(vector<int>& v) {
        int n=v.size();
        map<int,int>m;
        for(int i=0;i<n;i++)
            m[v[i]]=i;
        int p1=0,p2=0;
        int c=0;
        while(p1<n)
        {
            p2=max(p2,m[v[p1]]);
            if(p1==p2)
            {
                c++;
            }
            p1++;
        }
        return power(2,c-1,mod);
    }
};