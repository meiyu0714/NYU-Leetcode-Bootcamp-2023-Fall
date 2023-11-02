class Solution {
public:
    bool static cmp(const pair<int, int>& a, const pair<int, int>&b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //create the unordered_map to record the frequency of 
        vector<int> ans;
        unordered_map<int, int> freq_num;
        for(int i = 0; i < nums.size(); i++){
            freq_num[nums[i]] ++;
        }
        vector<pair<int,int>> freq_v(freq_num.begin(), freq_num.end());
        sort(freq_v.begin(), freq_v.end(), cmp);
        for(int i = 0; i < k; i++){
            ans.push_back(freq_v[i].first);
        }
        return ans;
    }
};