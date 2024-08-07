class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthesis;

        unordered_map<char,char> matching = {
            {')','('},
            {']','['},
            {'}','{'}
        };

        for(char ch : s){
            if (matching.count(ch)){        // count checks for "ch" in keys.
                if(parenthesis.empty() || parenthesis.top()!=matching[ch]){
                    return false;
                }
                parenthesis.pop();
            }
            else parenthesis.push(ch);
        }
        return parenthesis.empty();
    }
};