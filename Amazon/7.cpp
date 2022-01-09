// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string res="";
		    vector<int> visited(26,-1);
            vector<char> list;
            
            int n= A.length();
            for(int i= 0;i<n;i++){
                if(visited[A[i] -'a'] == -1){
                    list.push_back(A[i]);
                }
                
                visited[A[i]-'a']++;
                int l1 = 0;
                int l2 = list.size();
                for(int j=0;j<l2;j++){
                    if(visited[list[j] - 'a'] == 0){
                        res+= list[j];
                        l1= 1;
                        break;
                    }
                }
                
                if(l1 == 0)
                    res+=('#');
            }
            		    
		    
		    return res;
		    
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends