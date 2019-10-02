class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        for(char c: s){
            if(!st.empty() && c == st.back().first){
                if(++st.back().second == k)
                    st.pop_back();
            }else{
                st.push_back({c, 1});
            }
        }
        
        string ret;
        for(auto p: st)
            ret += string(p.second, p.first);
        return ret;
    }
};