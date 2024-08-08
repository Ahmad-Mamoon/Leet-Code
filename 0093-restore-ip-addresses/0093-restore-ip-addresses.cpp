class Solution {
public:

    bool isValid(string &segment){
        
        if(segment.length()>3 || segment.length() == 0) return false;
        if(segment[0]=='0' && segment.length()>1) return false;

        int num = stoi(segment);
        return num >= 0 && num <=255;
    }

    void backtrack(string s, vector<string> &result, vector<string> &current, int start){

        if(current.size() == 4 && start == s.length()){
            result.push_back(current[0]+"."+current[1]+"."+current[2]+"."+current[3]);
            return;
        }

        for(int len = 1; len <=3 && start+len <= s.length() ; len++){
            string segment = s.substr(start,len);

            if(isValid(segment)){
                current.push_back(segment);

                backtrack(s, result , current, start+len);

                current.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        // length = s.length();
        vector<string> result;
        vector<string> current;
        backtrack(s,result, current, 0);
        return result;
    }
};