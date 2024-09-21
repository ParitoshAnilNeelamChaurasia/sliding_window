// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

class Solution {
public:

    bool is_vowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true ;
        }
        return false ;
    }
    int maxVowels(string s, int k) {
        int n = s.size() ;

        int mx =INT_MIN ;

        int ans = 0 ;

        int i = 0 ;
        int j = 0 ;

        while(j < n)
        {
            if(is_vowel(s[j]) == true)
            {
                ans++ ;
            }

            // shrink the window
            if(j - i + 1 > k)
            {
                if(is_vowel(s[i]) == true)
                {
                    ans-- ;
                }
                i++ ;
            }

            // size == k -> update mx
            if(j - i + 1 == k)
            {
                mx = max(mx , ans) ;
            }
            j++ ;
        }
        return mx ;
    }
};
