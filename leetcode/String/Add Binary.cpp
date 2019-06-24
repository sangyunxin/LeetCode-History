class Solution {
public:
    string addBinary(string a, string b) {

        string res, add;
        int carry = 0;
        if(a.length() > b.length()){
            res = a;
            add = b;
        }else{
            res = b; 
            add = a;
        }
        
        int i = res.length() - 1;
        int j = add.length() - 1;
        
        while(j >= 0){
            if( (res[i] - '0') + (add[j] - '0') + carry >= 2 ){
                res[i] = (((res[i] - '0') + (add[j] - '0') + carry) % 2) + '0';
                carry = 1;
            }else{
                res[i] = res[i] + add[j] + carry - '0';
                carry = 0;
            }  
            
            i--;
            j--;
        }
        
        while(i >= 0 && carry != 0){
            if( (res[i] - '0') + carry >= 2 ){
                res[i] = ((res[i] - '0') + carry) % 2 + '0';
                carry = 1;
            }else{
                res[i] = res[i] + carry;
                carry = 0;
            } 
            
            i--;
        }
        
        if(carry == 1)
            res = "1" + res;
        
        return res;
        
    }
};