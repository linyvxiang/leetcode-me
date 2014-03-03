class Solution {
public:

    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> occur;
        int i;
        int len = num.size();
        for(i = 0; i < len; i++)
            occur[num[i]] = false;
            
        int longest = 0;
        
        for(i = 0; i < len; i ++) {
            if(occur[num[i]])
                continue;
            int length = 1;
            occur[num[i]] = true;
            int j;
            for(j = num[i] + 1; occur.find(j) != occur.end(); j++) {
                occur[j] = true;
                length++;
            }
            for(j = num[i] - 1; occur.find(j) != occur.end(); j--) {
                occur[j] = true;
                length++;
            } 
            if(length > longest)
                longest = length;
        }
        return longest;
    }
};
