class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> subsets;
        vector<int> set={1,2,3,4,5,6,7,8,9};
        for(int i=1; i<=512; i++){
                vector<int> sub;
                int sum=0;
                for(int j=0; j<9; j++){
                    if(1<<j & i)
                    {
                        sub.push_back(set[j]);
                        sum+=set[j];
                        
                    }
                    
                }
                if(sum==n && sub.size()==k){
                    subsets.push_back(sub);
                }
            
            
        }
        return subsets;
    }
};