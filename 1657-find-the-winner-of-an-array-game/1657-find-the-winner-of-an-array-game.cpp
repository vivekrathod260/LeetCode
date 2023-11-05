class Solution {
public:
    int getWinner(vector<int> &v, int k) {
        int n = v.size();
        int cnt = 0;

        if(k>=n-1)  return *max_element(v.begin(), v.end());

        int i = 0;
        while(1)
        {
            if(v[i]>v[(i+1)%n])
            {
                swap(v[i%n],v[(i+1)%n]);    //swap(v[i], v[i+1])
                i = (i+1)%n;  //i++;
                cnt++;
                if(cnt==k)  return v[i];
            }
            else
            {
                i = (i+1)%n;  //i++;
                cnt = 1;
                if(cnt==k)  return v[i];
            }
        }

        return -1; // ignoring returnning something
    }
};