// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;  
        int mn = INT_MAX;  
        
        int i = 0;  
        
        for (int j = 0; j < n; ++j) 
        {  
            sum += nums[j];
            
            // Shrink the window as small as possible while the sum is greater than or equal to the target
            while (sum >= target) 
            {
                mn = min(mn, j - i + 1);  // Update the minimum length
                sum -= nums[i];  // Subtract the leftmost element from the sum
                i++;  // Move the left pointer to shrink the window
            }
        }
        
        if(mn == INT_MAX)
        return 0 ;

        return mn ;
    }
};
