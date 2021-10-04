bool canJump(vector<int>& nums) {
        bool ans = false;
        int mj=0;
        for(int i=nums.size()-2; i>=0; i--) {
            mj++;
            if(nums[i]>=mj) mj=0;
        }
        if(mj==0) return true;
        return false;
    }
