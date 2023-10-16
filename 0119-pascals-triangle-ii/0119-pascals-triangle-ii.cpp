class Solution {
public:
    vector<int> getRow(int indx) {
        vector<int> temp;
        vector<int> temp2;

        if(indx==0)
        {
            temp.push_back(1);
            return temp;
        }
        if(indx==1)
        {
            temp.push_back(1);
            temp.push_back(1);
            return temp;
        }

        temp.push_back(1);
        temp.push_back(1);

        for(int i=2; i<=indx; i++)
        {
            temp2.push_back(1);
            for(int j = 0; j<i-1; j++)
            {
                temp2.push_back(temp[j] + temp[j+1]);
            }
            temp2.push_back(1);

            temp = temp2;
            temp2.clear();
        }

        return temp;
    }
};