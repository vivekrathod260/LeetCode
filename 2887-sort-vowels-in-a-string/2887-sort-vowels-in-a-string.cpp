class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        unordered_set<char> set = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        map<char, int> mp;
        for(char ch : s)
        {
            if(set.find(ch) != set.end())   mp[ch]++;
        }

        auto it = mp.begin();
        int i = 0;

        while(i<n)
        {
            if(set.find(s[i]) != set.end())
            {
                while(it != mp.end() and it->second ==0) it++;
                if(it == mp.end()) break;

                s[i++] = it->first;
                it->second --;
            }
            else i++;
        }

        return s;
    }
};