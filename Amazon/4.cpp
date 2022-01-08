// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string result;
    
    void print(int i, int j, int n, int * brack, char &res){
        if(i == j){
            result+= res;
            res++;
            return ;
        }
        result += '(';
    	print(i, *((brack+i*n)+j), n,brack, res);
    	print(*((brack+i*n)+j) + 1, j,n, brack, res);
    	result += ')';
    }
    
    
    string matrixChainOrder(int p[], int n){
        // code here
        
        int mat[n][n];
        int brack[n][n];
        
        for(int i=1;i<n;++i){
            mat[i][i]=0;
        }
        
        for(int l= 2;l<n;l++){
            
            for(int i=1;i<n-l+1;i++){
                int j = i+l-1;
                mat[i][j] = INT_MAX;
                for(int k= i;k<=j-1;k++){
                    int temp = mat[i][k]+mat[k+1][j]+p[i-1]*p[k]*p[j];
                    if(temp < mat[i][j]){
                        mat[i][j] =temp;
                        brack[i][j]=k;
                    }
                }
            }
        }
        
        char res ='A';
        print(1, n-1, n,(int *)brack, res);
        return result;
        
        
        
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends