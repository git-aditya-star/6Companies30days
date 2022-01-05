class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int min = INT_MAX;
        long long int sum =0;
        int start= 0;
        for(int i=0;i<nums.size();i++){
            
            sum += nums[i];
            if(sum >= target){
                int len = i- start+1;
                if(len < min){
                    min = len;
                }
                while(sum>= target){
                    int len1 = i- start+1;
                    if(len1 < min){
                        min= len1;
                    }
                    sum -= nums[start];
                    start++;
                }
            }
            
            
        }
        if(min == INT_MAX)
            return 0;
        return min;
        
    }
};