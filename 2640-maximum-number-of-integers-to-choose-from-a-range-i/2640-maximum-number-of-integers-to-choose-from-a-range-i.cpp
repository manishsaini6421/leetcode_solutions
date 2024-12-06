class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0,count=0;
        for(int i=1; i<=n; i++){
            if(find(banned.begin(),banned.end(),i)==banned.end() ){
                if(ans+i<=maxSum){
                    ans+=i; 
                    count++;
                }
                else break;
            }
        }
        return count;
    }
};