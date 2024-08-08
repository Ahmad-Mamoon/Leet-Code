class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int,int>> solider_rows;
        for(int i=0; i<mat.size(); i++){
            int solider_count = count(mat[i].begin(),mat[i].end(),1); // counts the no of soliders in each row
            solider_rows.push_back({solider_count,i});
        }

        sort(solider_rows.begin(),solider_rows.end());

        vector<int> weakest_rows;
        for(int i=0;i<k;i++){
            weakest_rows.push_back(solider_rows[i].second);
        }
        return weakest_rows;
    }  
};