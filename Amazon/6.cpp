// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
      
        
        map<int, int> hashmap;
        for(int i =0;i<k;i++){
            hashmap[arr[i]]++;
        }
        vector<int> res;
        map<int,int> :: iterator itr;
        itr= hashmap.end();
        itr--;
        res.push_back(itr->first);
        
        for(int i=k;i<n;i++){
            
            int temp = arr[i-k];
            itr = hashmap.find(temp);
            if(itr->second == 1){
                hashmap.erase(temp);
            }
            else{
                itr->second--;
            }
            hashmap[arr[i]]++;
            itr= hashmap.end();
            itr--;
            res.push_back(itr->first);
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends