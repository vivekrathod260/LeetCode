class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &r, int s, int t) {
        if(s==t)    return 0; // special case

        int n = r.size();

        // stop to bus mapping
        map<int, vector<int>> mp;
        for(int i = 0; i<n; i++)
        {
            int CurRouteSize = r[i].size();
            for(int j = 0; j<CurRouteSize; j++)
            {
                mp[r[i][j]].push_back(i);
            }
        }

        // for finding next bus from cur bus
        vector<unordered_set<int>> busToBus(n);
        for(int i = 0; i<n; i++)
        {
            for(int nextStop : r[i])
            {
                for(int nextBus : mp[nextStop])
                {
                    busToBus[i].insert(nextBus);
                }
            }
        }
        
        ////// TargetBusSet for finding end bus
        unordered_set<int> tarBusSet;
        for(int tarBus : mp[t]) tarBusSet.insert(tarBus);

        /////   BFS
        vector<bool> vis(n, false);
        queue<pair<int,int>> q;
        for(int bus : mp[s])    q.push({bus, 1});

        while(q.size()!=0)
        {
            pair<int,int> busPair = q.front(); q.pop();
            int bus = busPair.first;
            int cost = busPair.second;

            if(tarBusSet.find(bus) != tarBusSet.end())  return cost;

            vis[bus] = true;

            for(int nextBus : busToBus[bus])
            {
                if(vis[nextBus]==false)
                {
                    q.push({nextBus, cost+1});
                }
            }
        }

        return -1;
    }
};