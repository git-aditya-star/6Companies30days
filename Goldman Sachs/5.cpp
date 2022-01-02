// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    
	   ull two =0, three =0, five=0;
	   vector<ull> dp(n+1);
	   dp[0] = 1;
	   for(ull i=1;i<=n;i++){
	       
	       dp[i] = min( 2*dp[two] , min( 3* dp[three] , 5 * dp[five]));
	       if(dp[i] ==  2*dp[two])
	        two++;
	      if(dp[i] ==  3* dp[three])
	        three++;
	       if(dp[i] ==  5*dp[five])
	        five++;
	       
	       
	       
	   }
	   
	   return dp[n-1];
	   
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends