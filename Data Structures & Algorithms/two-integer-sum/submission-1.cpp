class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int tg = target - nums[i];
            if(mp.find(tg) != mp.end()){
                int j = mp[tg];

                return (i < j) ? vector<int>{i, j}:vector<int>{j, i};
            }
            mp[nums[i]] = i;
        }

        return {};
    }
};
