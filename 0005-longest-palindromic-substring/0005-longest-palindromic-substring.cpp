class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int l,r;
        int lmax = INT_MIN;
        string ans;

        for(int i=0; i<n; i++)
        {
            l = i;
            r = i;

            while((l>=0 and r<n) and (s[l] == s[r]))
            {
                l--;
                r++;
            }

            if( r-l-1 > lmax )
            {
                lmax = r-l-1;
                ans = s.substr(l+1, r-l-1);
            }
        }

        for(int i = 0; i<=n-2; i++)
        {
            l = i;
            r = i+1;

            while((l>=0 and r<n) and (s[l] == s[r]))
            {
                l--;
                r++;
            }

            if( r-l-1 > lmax )
            {
                lmax = r-l-1;
                ans = s.substr(l+1, r-l-1);
            }
        }

        return ans;
    }
};