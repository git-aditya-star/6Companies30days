// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int row = mat.size();
        int col = mat[0].size();
        if(row != 9 || col != 9)
            return 0;
        unordered_map<string,int> hashmap;
        
        for(int i =0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 0)
                    continue;
                
                int box = (i/3)*3+(j/3);
                string r = "R+"+to_string(i)+"+"+to_string(mat[i][j]);
                string c = "C+"+to_string(j)+"+"+to_string(mat[i][j]);
                string b = "B+"+to_string(box)+"+"+to_string(mat[i][j]);
                if(hashmap.find(r) != hashmap.end() ||hashmap.find(c) != hashmap.end()||hashmap.find(b) != hashmap.end()){
                    return 0;
                }
                else{
                    hashmap[r]++;
                    hashmap[c]++;
                    hashmap[b]++;
                }
                
                
            }
        }
        return 1;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends