class Solution {
public:
    bool isReachableAtTime(int x1, int y1, int x2, int y2, int t) {
        if(x1==x2 and y1==y2 and t==1)  return false; // start == final and t>=2  will return true always
        
        return (t>=max(abs(x1-x2), abs(y1-y2)));
    }
};