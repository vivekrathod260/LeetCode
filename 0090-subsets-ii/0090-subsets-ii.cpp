class Solution {
public:
    void f(int i, vector<int> ds, int N, vector<int> &v, vector<vector<int>> &ans)
    {
        if(i == N)
        {
            ans.push_back(ds);
            return;
        }

        ans.push_back(ds);
        for(int itr = i; itr<N; itr++)
        {
            if(itr != i && v[itr] == v[itr-1]) continue;

            ds.push_back(v[itr]);
            f(itr+1, ds, N, v, ans);
            ds.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int> &v) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(v.begin(), v.end());
        f(0, ds, v.size(), v, ans);
        return ans;
    }
};