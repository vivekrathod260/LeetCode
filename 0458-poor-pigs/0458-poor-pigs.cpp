#include<cmath>
class Solution {
public:
    int poorPigs(int n, int mtod, int mtot) {
        // return ceil of log of n to the base (mtot/mtod)+1)
        float ans = log(n)/log((mtot/mtod)+1);
        return  ceil(ans);
    }
};