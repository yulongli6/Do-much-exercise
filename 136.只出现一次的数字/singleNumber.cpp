class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];
        for(size_t i = 1; i < nums.size(); ++i)
            ret ^= nums[i];
        return ret;

    }


};
