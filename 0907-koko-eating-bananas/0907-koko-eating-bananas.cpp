class Solution {
public:
    long long fun(int s, vector<int> &v, int n)
    {
        long long time = 0;
        for(int i = 0; i<n; i++)
        {
            time = time + ceil((double)(v[i]/(double)s));
        }
        return time;
    }

    int minEatingSpeed(vector<int> &v, int h) {
        int n = v.size();
        int max = *max_element(v.begin(), v.end());
        int ans = INT_MAX;

        int s = 1, e = max, mid, time;
        while(s<e)
        {
            mid = (s+e)/2;
            time = fun(mid, v, n);
            if(time > h)
            {
                s = mid+1;
            }
            else 
            {
                e = mid;
                ans = min(ans, mid);
                cout<<mid<<" ";
            }
        }

        return s;
    }
};