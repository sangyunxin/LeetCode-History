class NumArray {
public:
    NumArray(vector<int> nums) {
        this->nums = nums;
    }

    int sumRange(int i, int j) {
        int ret = 0;
        for(int k = i; k <= j; ++k)
            ret += nums[k];
        return ret;
    }

private:
    vector<int> nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */