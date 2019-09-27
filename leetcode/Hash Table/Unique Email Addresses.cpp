class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        
        for(string email: emails){
            string cur = "";
            string::size_type pos = email.find("@");
            for(int i = 0; i < pos; ++i){
                if(email[i] == '@' || email[i] == '+')
                    break;
                if(email[i] == '.')
                    continue;
                cur += email[i];
            }
            cur += email.substr(pos);
            s.insert(cur);
        }
        
        return s.size();
    }
};