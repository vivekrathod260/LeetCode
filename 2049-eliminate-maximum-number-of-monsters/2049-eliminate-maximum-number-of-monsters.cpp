class Solution {
public:
    int eliminateMaximum(vector<int> &d, vector<int> &s) {
        int n = d.size();
        int ans = 1;

        vector<float> t(n,0);
        for(int i = 0; i<n; i++)    t[i] = d[i]/(float)s[i];
        sort(t.begin(), t.end());

        int i = 1;
        int tspend = 1;
        while(i<n and t[i]-tspend>0) //t[i]-tspend>0 ith moster will take some time to arrive
        {
            ans++;
            tspend++;
            i++;
        }

        return ans;
    }
};