class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 != 0) return false;

        string st = "";

        for(char ch : s){
            if (ch == '(')      st.push_back(')');
            else if (ch == '{') st.push_back('}');
            else if (ch == '[') st.push_back(']');
            else {
                if (st.empty() || st.back() != ch) return false;
                st.pop_back();
            }
        }

        return st.empty();
    }
};
