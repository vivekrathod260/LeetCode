class Solution {
public:
    vector<int> majorityElement(vector<int> &N) {
        int n = N.size();
        int num1 = INT_MIN, num2 = INT_MIN;
        int count1 = 0, count2 = 0;
        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            if(N[i] == num1)
            {
                count1++;
            }
            else if(N[i] == num2)
            {
                count2++;
            }
            else if(count1 == 0)
            {
                num1 = N[i];
                count1 = 1;
            }
            else if(count2 == 0)
            {
                num2 = N[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        if(count(N.begin(), N.end(), num1) > n/3)
            ans.push_back(num1);
        if(count(N.begin(), N.end(), num2) > n/3)
            ans.push_back(num2);
        
        return ans;
    }
};