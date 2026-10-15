class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderMap(26);

        for(int i = 0 ; i < 26 ; i++){
            orderMap[order[i] - 'a'] = i; 
        }

        for(int i = 1 ; i < words.size() ; i++){
            string word1 = words[i-1];
            string word2 = words[i];
            int len1 = word1.length();
            int len2 = word2.length();
            int len = min(len1 , len2);
            bool diffChar = false;
            for(int j = 0; j < len ; j++){
                if(word1[j] == word2[j]){
                    continue;
                }
                else{
                    diffChar = true;
                    if(orderMap[word1[j]-'a'] > orderMap[word2[j]-'a']) return false;    
                    break;
                }
            }
            if(len1 > len2 && diffChar == false)    return false;
        }
        return true;
    }
};