class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        if(arr.size() < 3) 
            return 0;
        
        int len = 0;
        int temp =1;
        int front, back;
        
        for(int i=1;i < arr.size()-1;i++){
            
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
                front = i+1;
                back = i-1;
                temp =3;
                while(back >= 1){
                    if(arr[back-1] < arr[back]){
                        temp++;
                        back--;
                    }
                    else{
                        break;
                    }
                }
                while(front < arr.size()-1){
                    if(arr[front] > arr[front+1]){
                        temp++;
                        front++;
                    }
                    else{
                        break;
                    }
                }
                if(temp > len){
                    len = temp;
                }
            }
            
        }
        
        
        return len;
        
    }
};