class Solution {
public:
    int poorPigs(int buckets, int d, int t) {
      int n= t/d +1;
        //n decides what base system to use
        // ans = log(buckets) with base n 
      int ans= (int)ceil(log2(buckets)/log2(n));
      return ans;  
    }
};