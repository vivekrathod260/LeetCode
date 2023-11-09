class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, ans = 0;
        for(char ch : s)
        {
            if(cnt<0 and ch=='(')
            {
                ans += abs(cnt);
                cnt = 0;
            }

            if(ch=='(') cnt++;
            else cnt--;
        }
        ans += abs(cnt);
        
        return ans;
    }
};