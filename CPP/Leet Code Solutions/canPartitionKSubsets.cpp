// Level: Medium
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=0;
        
        for(int ele: nums) total+=ele;
        
        if(total%k != 0) return false;
        if(nums.size() < k) return false;
        
        int subset_sum = total/k;
        
        vector<bool> visited(nums.size());
        return helper(nums, visited, 0, k, 0, subset_sum);
    }
    bool helper(vector<int>& nums, vector<bool>& visited, int start, int k, int cs,int ss) {
        if(k == 0) return true;
        if(cs > ss) return false;
        if(cs == ss) return helper(nums, visited, 0, k-1,0, ss);
        for(int i=start; i<nums.size(); i++) {
            if(visited[i]) continue;
            visited[i] = true;
            if(helper(nums, visited, i+1, k, cs+nums[i], ss)) return true;
            visited[i] = false;
        }
        return false;
    }
};
