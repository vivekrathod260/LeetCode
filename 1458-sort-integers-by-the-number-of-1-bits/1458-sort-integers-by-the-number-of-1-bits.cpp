class Solution {
public:
    bool comp(int a, int b)
    {
        int tmp = 1;
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i<sizeof(int)*8; i++)
        {
            if((a & tmp) != 0) cnt1++;

            if((b & tmp) != 0) cnt2++;

            tmp = (tmp<<1);
        }

        if(cnt1<cnt2) return true;
        else if(cnt2 < cnt1) return false;
        else    return a<=b;
    }

    void merge(int i, int j, vector<int> &v)
    {
        vector<int> temp(j-i+1);
        int s1=i, s2= ((i+j)/2)+1;
        int e1 = ((i+j)/2), e2 = j;
        int filler = 0;

        while(s1<=e1 and s2<=e2)
        {
            if(comp(v[s1], v[s2]))
            {
                temp[filler] = v[s1];
                filler++;
                s1++;
            }
            else
            {
                temp[filler] = v[s2];
                filler++;
                s2++;
            }
            
        }

        while(s1<=e1)
        {
            temp[filler] = v[s1];
            filler++;
            s1++;
        }

        while(s2<=e2)
        {
            temp[filler] = v[s2];
            filler++;
            s2++;
        }

        for(s1=i; s1<=j; s1++)
        {
            v[s1] = temp[s1-i];
        }
    }
    void mergesort(int i, int j, vector<int> &v)
    {
        if(i>=j) return;

        int mid = (i+j)/2;
        mergesort(i, mid, v);
        mergesort(mid+1, j, v);

        merge(i, j, v);
    }
    vector<int> sortByBits(vector<int> &nums) {
        vector<int> v(nums);
        mergesort(0, v.size()-1, v);
        return v;
    }
};