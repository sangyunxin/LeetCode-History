class Solution {
public:
    int maxArea(vector<int>& height) {
        int left, resL, right, resR, res, curRes;
        left = resL = 0;
        right = resR = height.size() - 1;
        res = (resR - resL) * min(height[resR], height[resL]);
        
        while(left < right){
            if(height[left] <= height[right]){
                for(; left <= resR; left++){
                    if(height[left] <= height[resL])
                        continue;
                    curRes = (resR - left) * min(height[resR], height[left]);
                    if(res <= curRes){
                        res = curRes;
                        resL = left;
                        break;
                    }
                    if(height[left] > height[resR]){
                        resL = left;
                        break;
                    }
                        
                }
            }else{
                for(; resL <= right; right--){
                    if(height[right] <= height[resR])
                        continue;
                    curRes = (right - resL) * min(height[right], height[resL]);
                    if(res <= curRes){
                        res = curRes;
                        resR = right;
                        break;
                    }
                    if(height[right] > height[resL]){
                        resR = right;
                        break;
                    }
                        
                }
            }
        }
        return res;
    }
};