class Solution {
public:
    string pushDominoes(string dominoes) {
        string tmp = "L" + dominoes + "R";
        int left = 0, right = 1;
        while(right < tmp.size()){
            while(tmp[right] == '.')
                right++;
            if(tmp[left] == 'R' && tmp[right] == 'L'){
                for(int i = 1; i <= (right - left) / 2 && left + i != right - i; ++i){
                    tmp[left+i] = 'R';
                    tmp[right-i] = 'L';
                }
            }else if(tmp[left] == tmp[right] && tmp[left] == 'R'){
                for(int i = left+1; i < right; ++i)
                    tmp[i] = 'R';
            }else if(tmp[left] == tmp[right] && tmp[right] == 'L'){
                for(int i = left+1; i < right; ++i)
                    tmp[i] = 'L';
            }
            
            left = right++;
        }
        
        return tmp.substr(1, tmp.size()-2);
    }
};