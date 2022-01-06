// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        
        if(K == 0)
            return 0;
            
        if(2*K > N){
            int res =0;
            for(int i=1;i<N;i++){
                if(A[i] > A[i-1]){
                    res+= (A[i]-A[i-1]);
                }
            }
            
            return res;
        }
        
        int dp[2*K+1];
        dp[0] = -A[0];
        
        
        for(int i=1;i<2*K;i++){
            if(i%2 == 0){
                dp[i] = INT_MIN;
            }
            else{
                dp[i] =0;
            }
        }
        
        for(int i =0;i<N;i++){
            for(int j=0;j<=2*K;j++){
                
                if(j == 0){
                    dp[j] = max(dp[j] , -A[i]);
                }
                else if(j % 2 == 0){
                    dp[j] = max(dp[j], dp[j-1] - A[i]);
                }
                else{
                    dp[j]=  max(dp[j], dp[j-1] + A[i]);
                }
            }
        }
        
        return dp[2*K -1];
       
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends