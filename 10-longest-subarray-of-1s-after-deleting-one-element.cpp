// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

// BRUTE FORCE

class Solution {
public:
    int n ;
    
    int find_mx(vector<int> &nums , int skip_ind)
    {
        int curr_len = 0 ;
        int mx_len = 0 ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(i == skip_ind)
            {
                continue ;
            }

            if(nums[i] == 1)
            {
                curr_len++ ;
                mx_len = max(mx_len , curr_len) ;
            }
            else
            {
                curr_len = 0 ;
            }
        }
        return mx_len ;
    }
    int longestSubarray(vector<int>& nums) {
        n = nums.size() ;

        int res = INT_MIN ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(nums[i] == 0)
            {
                res = max(res , find_mx(nums , i)) ;
            }
        }

        if(res == INT_MIN)
        return n-1 ;

        return res ;
    }
};

// SLIDING WINDOW

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size() ;

        int i = 0 ;
        int count_zero = 0 ;
        int mx = INT_MIN ;
       
        for(int j = 0 ; j < n ; ++j)
        {
            if(nums[j] == 0)
            {
                count_zero++ ;
            }

            while(count_zero > 1)
            {
                if(nums[i] == 0)
                {
                    count_zero-- ;
                }
                i++ ;
            }
            mx = max(mx , j-i) ;
        }
        return mx ;
    }
};
