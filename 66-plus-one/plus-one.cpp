class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int count=0;
       for(int i=n-1;i>=0;i--){
           if(digits[i]<9){
               digits[i]++;
               return digits;
           }
           digits[i]=0;
            count++;
       }
       if(count==n){
           digits.insert(digits.begin(),1);
          
       }
        return digits;
       }


    
};