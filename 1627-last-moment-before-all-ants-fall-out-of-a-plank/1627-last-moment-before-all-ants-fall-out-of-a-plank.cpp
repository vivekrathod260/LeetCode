class Solution {
public:
    int getLastMoment(int n, vector<int> &l, vector<int> &r) {
        int lmax = INT_MIN, rmin = INT_MAX;
        int lsz = l.size(), rsz = r.size();

        for(int i=0; i<lsz; i++)
        {
           lmax = max(lmax, l[i]);
        }

        for(int i = 0; i<rsz; i++)
        {
            rmin = min(rmin, r[i]);
        }

        if(lsz == 0)
        {
            return (n-rmin);
        }
        if(rsz == 0)
        {
            return(lmax);
        }

        return max(lmax, (n-rmin));
        
    }
};