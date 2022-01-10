// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string res="";
        while(n)
        {
            long long int temp = n %26;
            
            char c = 'A'+temp-1;
            if(temp == 0){
                c = 'Z';
                res+=c;
                n/=26;
                n--;
                continue;
            }
            
            res+=c;
            n/=26;
            //cout<<temp<<endl;
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends