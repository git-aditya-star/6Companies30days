// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int ar[2];
    int *findTwoElement(int *arr, int n) {
        // code here
      
        unordered_map< int, int> map;
        long long int n1 = n;
        int rep;
        long long int sum = 0;
        for(int i=0;i<n;i++){
            if(map.find(*arr) == map.end()){
                map[*arr]++;
                sum += *arr;

            }
            else{
                rep = *arr;
   
            }
            arr++;
        }
        
        ar[0] = rep;
        ar[1] = ((n1*(n1+1))/2) - sum;
        return &ar[0];
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends