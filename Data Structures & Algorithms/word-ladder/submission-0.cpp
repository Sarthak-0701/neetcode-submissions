class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin() , wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord , 1});

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            string word = front.first;
            int steps = front.second;
            st.erase(word);

            if(word == endWord) return steps;

            for(int i = 0 ; i < word.length() ; i++){
                char original = word[i];
                for(char j = 'a' ; j <= 'z' ; j++){
                    word[i] = j;
                    if(st.find(word) != st.end()){
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};
