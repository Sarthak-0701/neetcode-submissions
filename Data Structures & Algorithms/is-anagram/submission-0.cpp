class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length())    return false;
        vector<int> sChar(26,0);
        vector<int> tChar(26,0);

        for(int i = 0; i < s.length() ; i++){
            sChar[s[i] - 'a']++;
            tChar[t[i] - 'a']++;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(sChar[i] != tChar[i])    return false;
        }
        return true;
    }
};
