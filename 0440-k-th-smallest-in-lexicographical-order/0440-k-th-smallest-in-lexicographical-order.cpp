class Solution {
public:
    int min(int x,int y){
        if(x<y) return x;
        return y;
    }
    int skip_ele(long long int a, long long int b,int n){
        int diff=0;
        while(a<=n){
            diff+=min(b,n+1)-a;
            a*=10;
            b*=10;
        }
        
        return diff;
    }
    

    int findKthNumber(int n, int k) {
        long long int res=1;
        for(int i=1; i<k;){
            if(skip_ele(res,res+1,n)+i<=k){
                i+=skip_ele(res,res+1,n);
                res++;
            }
            else{
                res*=10;
                i++;
            }
        }
        return res;
    }

};