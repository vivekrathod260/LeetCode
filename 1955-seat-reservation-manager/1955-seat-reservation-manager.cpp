class SeatManager {
    vector<int> v;
    int n;
    int cur;
    set<int> s;
public:
    SeatManager(int n) {
        vector<int> vec(n,0);
        v = vec;
        this->n = n;
        cur = 0;
    }
    
    int reserve() {
        v[cur] = 1;
        int ans = cur+1;

        if(s.size()!=0)
        {
            cur = *s.begin(); s.erase(s.begin());
        }
        else
        {
            cur++;
        }

        return ans;
    }
    
    void unreserve(int seatNumber) {
        v[seatNumber-1] = 0;

        // consider reserved till 9 unreserve 4, unreserve 6
        s.insert(cur);
        s.insert(seatNumber-1);
        cur = *s.begin(); s.erase(s.begin());
    }

};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */