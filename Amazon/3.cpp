// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
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

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends