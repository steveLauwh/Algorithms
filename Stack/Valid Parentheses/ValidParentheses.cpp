class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.size() == 0) {
                    return false;
                }
                
                char c = st.top();
                st.pop();
                
                char match;
                
                if (s[i] == ')') {
                    match = '(';
                } else if (s[i] == '}') {
                    match = '{';
                } else {
                    assert(s[i] == ']');
                    match = '[';
                }
                
                if (c != match) {
                    return false;
                }
            }
        }
        
        if (st.size() != 0) {
            return false;
        }
        
        return true;
    }
};
