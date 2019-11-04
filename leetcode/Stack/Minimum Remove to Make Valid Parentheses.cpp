class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        set<int> pos;
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            if(c == '(')
                st.push(i);
            if(c == ')'){
                if(!st.empty())
                    st.pop();
                else
                    pos.insert(i);
            }
        }

        while(!st.empty()){
            pos.insert(st.top());
            st.pop();
        }

        string ret = "";
        for(int i = 0; i < s.size(); ++i){
            if(pos.count(i) == 0)
                ret += s[i];
        }

        return ret;
    }
};