class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(n == 3)
            return 5;

        int ret = 0;
        int p = n - 1;
        for(; p >= n / 2; p--)
            ret += 2 * numTrees(p) * numTrees(n - 1 - p);
        if(n % 2)
            ret -= numTrees(n / 2) * numTrees(n / 2);

        return ret;
    }
};
