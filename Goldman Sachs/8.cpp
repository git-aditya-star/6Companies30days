// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string s){
		   
		if(s.length() == 0 || s[0] == '0') return 0;
        if(s.length() == 1)  return 1;
        long long int mod = 1e9 + 7;
        int prev =1, prevSecond =1;
        for(int i= 1; i<s.length();++i){
            
            int single = s[i] - '0';
            int two = (s[i-1] - '0')*10 + single;
            
            int currentCount = 0;
            if(single > 0) currentCount+= prev;
            if(two >= 10 && two <= 26) currentCount += prevSecond;
            
            prevSecond = prev;
            prev = currentCount;
            prev %= mod;
            
            
        }
        
        return prev;
		    
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends