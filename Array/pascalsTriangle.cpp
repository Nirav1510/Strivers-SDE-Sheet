class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        ll mod = 1e9+7;
        ll dp[n][n];
        dp[0][0] = 1;
        vector<ll> ans;
        if(n==1){
            ans.push_back(1);
            return ans;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    dp[i][j] = 1;
                    // if(i==n-1){
                    //     ans.push_back(1);
                    // }
                }
                else{
                    dp[i][j] = ((dp[i-1][j-1])%mod + (dp[i-1][j])%mod)%mod;
                    // if(i==n-1){
                    //     ans.push_back(dp[i][j]);
                    // }
                }
            }
        }
        for(int i=0;i<n;i++){
            ans.push_back(dp[n-1][i]);
        }
        
        return ans;
    }
};
