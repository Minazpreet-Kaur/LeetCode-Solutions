class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> v;
     
        for (int i = 0; i < n; i++) {
            v.push_back({score[i], i});
        }
   
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        vector<string> ans(n);
        
        for (int rank = 0; rank < n; rank++) {
            int original_index = v[rank].second;
            if (rank == 0) {
                ans[original_index] = "Gold Medal";
            } else if (rank == 1) {
                ans[original_index] = "Silver Medal";
            } else if (rank == 2) {
                ans[original_index] = "Bronze Medal";
            } else {
                ans[original_index] = to_string(rank + 1);
            }
        }
        
        return ans;
    }
};