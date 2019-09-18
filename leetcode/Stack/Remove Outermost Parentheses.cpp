class Solution {
public:
    string removeOuterParentheses(string S) {
        string ret = "";
        vector<int> bp;
        bp.push_back(-1);
        stack<char> st;
        for(int i = 0; i < S.size(); ++i){
            if(S[i] == '(')
                st.push(S[i]);
            else{
                st.pop();
                if(st.empty())
                    bp.push_back(i);
            }
        }
        cout << bp.size() << endl;
        for(int i = 0; i < bp.size() - 1; ++i){
            if(bp[i+1] - bp[i] > 1)
                ret += S.substr(bp[i]+2, bp[i+1]-bp[i]-2);
            else
                ret += S.substr(bp[i]+1, bp[i+1]-bp[i]);
        }
        return ret;
    }
};