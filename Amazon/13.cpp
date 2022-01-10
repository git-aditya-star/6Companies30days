class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        long long int time =0;
        
        queue<pair<int,int>> q;
        int fresh =0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j] == 1 ){
                    fresh++;
                }
            }
        }
        
        if(fresh == 0)
            return 0;
        
        int counter =0;
        
        while(!q.empty()){
            
            
            int len = q.size();
            while(len--){
            
            pair<int,int> current = q.front();
            
            
            
            
            q.pop();
            pair<int,int> top ;
            pair<int,int> left ;
            pair<int,int> right ;
            pair<int,int> bottom ;
            if(current.first >= 1 ){
                top.first = current.first-1;
                top.second = current.second; 
                if(grid[top.first][top.second] == 1){
                    grid[top.first][top.second]= 2;
                    counter++;
                    q.push(top);
                }
                
            }
            if(current.first < grid.size()-1){
                bottom.first = current.first+1;
                bottom.second = current.second;   
                if(grid[bottom.first][bottom.second] == 1){
                    grid[bottom.first][bottom.second]= 2;
                    counter++;
                    q.push(bottom);
                }
            }
            if(current.second >= 1){
                left.first = current.first;
                left.second = current.second-1; 
                 if(grid[left.first][left.second] == 1){
                    grid[left.first][left.second]= 2;
                     counter++;
                    q.push(left);
                }
            }
            if(current.second < grid[0].size()-1){
                right.first = current.first;
                right.second = current.second+1;   
                 if(grid[right.first][right.second] == 1){
                    grid[right.first][right.second]= 2;
                    q.push(right);
                     counter++;
                }
            }
                
                
            }
            
            time++;
            if(fresh == counter){
                return time;
            }
            
            
               
        }
        if(counter != fresh)
            return -1;
        
        return time;
    }
};