bool lessthan(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    if (lhs.first == rhs.first) 
        return lhs.second < rhs.second;
    return lhs.first < rhs.first;
}
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    
    int i,j;
    vector<pair<int,int>> V;
    for(i = 0; i < numbers.size(); i++) {
        V.push_back(make_pair(numbers[i],i+1));
    }
    sort(V.begin(),V.end(),lessthan);
    i = 0;
    j = V.size() - 1;
    vector<int> ans;
    while(i < j) {
        if(V[i].first + V[j].first == target) {
            ans.push_back(min(V[i].second,V[j].second));
            ans.push_back(max(V[i].second,V[j].second));
            break;
        } else if(V[i].first + V[j].first < target) {
            i++;
        } else {
            j--;
        }
    }
    return ans;
   }
};
