class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int best=nums[0];
        int worst=nums[0];
        int ans=nums[0];
        int minans=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            int a=nums[i];
            int b=nums[i]+best;
            best=max(a,b);
            int c=nums[i];
            int d=nums[i]+worst;
            worst=min(c,d);
            ans=max(best,ans);
            minans = min(minans, worst);
            sum += nums[i];
            
        }
         if(ans < 0)
            return ans;
        return max(ans, sum - minans);
    }
};