// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    unordered_map<int,int> map;
    
    long long countWays(int m)
    {
        // your code here
        if(m == 0)
            return 1;
        if(m < 0)
            return 0;
        if(map.find(m) != map.end())
            return map[m];
        
        
        long long sum = 0;
        sum += 1+ countWays(m-2);
        map[m] = sum;
        
        
        return sum;
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends