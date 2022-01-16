// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    
    int max=-1;
    int count;
    void DFS(vector<vector<int>>& grid, int i , int j, int row , int col){
        
        if(count > max){
            max= count;
        }
       
        if(i < 0 || j< 0 || i>(row-1)|| j>(col-1) || grid[i][j] == 0){
            return;
        }
        
        
        if(grid[i][j] == 1){
            count++;
           
            grid[i][j] =0;
            DFS(grid, i, j+1, row, col);
            DFS(grid, i, j-1, row, col);
            DFS(grid, i+1, j, row, col);
            DFS(grid, i-1, j, row, col);
            DFS(grid, i+1, j+1, row, col);
            DFS(grid, i+1, j-1, row, col);
            DFS(grid, i-1, j+1, row, col);
            DFS(grid, i-1, j-1, row, col);
        }
       
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        
        int row, col;
        
        for( int i =0 ;i< grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                row = grid.size();
                col= grid[i].size();
                if(grid[i][j] == 1){
                    count =0 ;
                    DFS(grid, i , j, row, col);
                }
            }
        }
        return max;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends