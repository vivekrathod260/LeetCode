class Solution {
public:
    char findTheDifference(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        int sum1 = 0,sum2 = 0;
        int i = 0;
        for(i=0; i<n1; i++) {
            sum1 += (s[i]-'a');
            sum2 += (t[i]-'a');
        }
        sum2 += (t[i]-'a');
        return ((char)('a'+sum2-sum1));
    }
};