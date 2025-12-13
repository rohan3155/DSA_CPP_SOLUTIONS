class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char val:s){
            if(val == '(' || val == '{' || val == '['){
                st.push(val);
            }else{
                if(st.size() == 0){
                    return false;
                }

                if(
                    st.top() == '(' && val == ')'
                    ||
                    st.top() == '{' && val == '}'
                    ||
                    st.top() == '[' && val == ']'
                    

                ){
                    st.pop();
                }else{
                    return false;
                }
            }
        } 
        return st.size() == 0;      
    }
};