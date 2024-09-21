// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

class Solution {
public:
    #define ll long long 
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll min_pos = -1 ;
        ll mx_pos = -1 ;

        ll cull_prt = -1 ;

        ll n = nums.size() ;

        ll mn ;

        ll ans = 0 ; 

        // har ek i pe khatam hone wala valid subarray nikalna hai
        for(ll i = 0 ; i < n ; ++i)
        {
            if(nums[i] < minK || nums[i] > maxK)
            {
                cull_prt = i ;
            }
            if(nums[i] == minK)
            {
                min_pos = i ;
            }

            if(nums[i] == maxK)
            {
                mx_pos = i ;
            }

            // finding smaller index
            mn = min(min_pos , mx_pos) ;

            ll temp = mn - cull_prt ;

            if(temp > 0)
            ans += temp ;
        }
        return ans ;
    }
};
