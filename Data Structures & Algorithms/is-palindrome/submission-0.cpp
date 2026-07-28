class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0; 
        int j = s.length()-1;
        
        while(i <= j){
            char ch1 = s[i];
            char ch2 = s[j];
            if(!isalnum(ch1) || !isalnum(ch2)){
                if(!isalnum(ch1))   i++;
                else if(!isalnum(ch2))  j--;
                else{
                    i++; 
                    j--;
                }    
            }
            else if(tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};
