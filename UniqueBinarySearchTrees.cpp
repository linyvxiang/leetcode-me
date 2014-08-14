class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(n == 3)
            return 5;
        int i, sum = 0;
        for(i = 0; i <= n - 1; i++)
            sum += numTrees(i) * numTrees(n - 1 - i);
        return sum;
    }
};
