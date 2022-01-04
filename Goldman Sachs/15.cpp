// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        
       unordered_map<int, int> map;
       
       for(int i=0;i<nums.size();i++){
           
           int rem = nums[i] % k;
           map[rem]++;
           
       }
       
       for(int i=0;i<nums.size();i++){
           
           int rem = nums[i] % k;
           unordered_map<int,int> :: iterator itr, itr1;
           
           
           if(rem == 0){
               itr = map.find(rem);
               if(itr == map.end())
                return false;
               if(map.find(rem)->second % 2 != 0){
                   return false;
               }
               
           }
           else if((2 * rem) == k){
               itr = map.find(rem);
               if(itr == map.end())
                 return false;
               if(map.find(rem)->second % 2 != 0){
                   return false;
               }
           }
           else{
               itr = map.find(rem);
               itr1 = map.find(k-rem);
               if(itr == map.end() || itr1 == map.end()){
                   return false;
               }
               else if(itr->second != itr1->second ){
                   return false;
               }
           }
           
       }
       return true;
    }
    
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends