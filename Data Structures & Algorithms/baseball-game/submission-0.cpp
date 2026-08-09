class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans = 0;
        for(int i = 0 ; i < operations.size() ; i++){
            if(operations[i] == "+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1+num2);
                ans += num1+num2;
            }
            else if(operations[i] == "D"){
                int num1 = st.top();
                st.push(num1*2);
                ans += (num1*2);
            }
            else if(operations[i] == "C"){
                int num = st.top()
                ans -= num;
                st.pop();
            }
            else{
                int val = stoi(operations[i]);
                st.push(val);
                ans += val;
            }
        }

        return ans;
    }
};