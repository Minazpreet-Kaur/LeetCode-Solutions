class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,1);
        
        int pre=1;
        for(int i=0;i<n;i++){
            result[i]=pre;
            pre=pre*nums[i];

        }
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            result[i]*=suffix;
            suffix=suffix*nums[i];
        }
        return result;
    
    }
  
};