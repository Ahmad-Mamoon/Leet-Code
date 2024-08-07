class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>> &result, vector<int> &tempList ,int start){
        result.push_back(tempList);

        for(int i = start ;i<nums.size() ; i++){
            if (i > start && nums[i]==nums[i-1]) continue;
            tempList.push_back(nums[i]);
            backtrack(nums,result,tempList, i+1);
            tempList.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tempList;

        sort(nums.begin(), nums.end());

        backtrack(nums,result,tempList,0);
        return result;
    }
};