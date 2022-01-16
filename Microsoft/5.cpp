// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>> s; 
       s.push({price[0],1}); 
       vector<int>ans;
       ans.push_back(1);
       for(int i=1;i<n;i++){
           
           int x=1; 
           while(!s.empty() && s.top().first<=price[i]){
               
               auto z=s.top();
               s.pop();
               x+=z.second; 
           }
           s.push({price[i],x});
           ans.push_back(x);
       }
       return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends