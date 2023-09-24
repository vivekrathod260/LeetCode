class Solution {
public:
    double champagneTower(int p, int r, int c) {
        if(p==0)    return 0.0;
        if(r==0 and c==0 and p>=1) return 1.0;
        
        vector<double> prev;
        prev.push_back((double)(p-1));

        for(int i = 1; i<r; i++)
        {
            int sz = i+1;
            vector<double> cur(sz, 0.0);
            for(int j = 0; j<sz; j++) {
                if(j==0) cur[j] = (prev[j]/2.0);
                else if(j==sz-1) cur[j] = (prev[j-1]/2.0);
                else cur[j] = (prev[j-1]/2.0) + (prev[j]/2.0);

                if(cur[j]>1.0) cur[j] = cur[j]-1.0;
                else cur[j] = 0;
            }
            prev = cur;
        }

        double val;
        if(c==0) val = (prev[c]/2.0);
        else if(c==prev.size()) val = (prev[c-1]/2.0);
        else val = (prev[c-1]/2.0) + (prev[c]/2.0);

        if(val>1.0) return 1.0;

        return val;
    }
};