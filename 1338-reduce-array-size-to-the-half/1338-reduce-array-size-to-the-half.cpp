class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> frequency;
        vector<int> frequencies;

        for(int integer : arr){
            frequency[integer]++;
        }

        for(auto digit: frequency){
            frequencies.push_back(digit.second);
        }

        sort(frequencies.rbegin(),frequencies.rend());

        int removed_elements = 0;
        int target_size = arr.size()/2;
        int set_size = 0;

        for (int freq : frequencies) {
            removed_elements += freq;
            set_size++;
            if (removed_elements >= target_size) {
                break;
            }
        }
        return set_size;
    }
};