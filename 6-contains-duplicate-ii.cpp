// https://leetcode.com/problems/contains-duplicate-ii/description/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> st ;

        int i = 0 ; int j = 0 ;

        while(j < n)
        {
            if(abs(i-j) > k)
            {
                st.erase(nums[i]) ;
                i++ ;
            }

            if(st.find(nums[j]) != st.end())
            {
                return true ;
            }
            st.insert(nums[j]) ;
            j++ ;
        }
        return false ;
    }
};
