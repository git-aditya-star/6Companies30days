// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string res ="";
        stack<int> st;
        int max = 1;
        for(int i= 0;i<S.length();i++){
            
            if(S[i] == 'D'){
                st.push(max);
                max++;
            }
            else{
                st.push(max);
                max++;
                int n = st.size();
                for(int j =0;j<n;j++){
                    res+= to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(max);
        int n = st.size();
        for(int j =0;j<n;j++){
            res+=to_string(st.top());
            st.pop();
        }
        return res;
        
        
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends