class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n==1) return true;

        int cnt1 = 0, cnt0 = 0;
        int tmp = 1;
        bool found1 = false;

        for(int i = 1; i<=32; i++)
        {
            if((n & tmp) == 0 and found1 == false) cnt0++;

            if((n & tmp) != 0)
            {
                found1 = true;
                cnt1++;
            }

            tmp = tmp<<1;
        }

        if(cnt1 == 1 and cnt0 % 2 == 0) return true;
        
        return false;
    }
};