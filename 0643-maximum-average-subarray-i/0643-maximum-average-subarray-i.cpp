class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        for (int i =0;i<k;i++){
            sum+=nums[i];
        }
        double avg=sum/k;
        double maxavg=avg;
        for (int i = k;i<nums.size();i++){
            sum+= nums[i];
            sum-=nums[i-k];
            avg=sum/k;
            maxavg=max(maxavg,avg);
        }
        return maxavg;
        
    }
};