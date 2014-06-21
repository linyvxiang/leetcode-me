class Solution {
public:
#define UP 1
#define DOWN  0
    string convert(string s, int nRows) {
        if(nRows == 1 || s.size() <= 1)
            return s;
        int column = s.size();
        char str[nRows][column];
        int i, j;
        for(i = 0; i < nRows; i++)
            for(j = 0; j < column; j++)
                str[i][j] = '\0';

        int cur_direction = 0; // 0 stands for down, 1 stands for up
        int pre_direction = 1;
        string::iterator it = s.begin();
        int cur_row = 0, cur_column = 0;
        while(it != s.end()) {
            str[cur_row][cur_column] = *it;
            it++;
            if(cur_row == 0) {// at the top, see what is the direction
                    cur_direction = DOWN;
                    cur_row++;
            } else if(cur_row == nRows - 1) { // at the bottom
                cur_row--;
                cur_column++;
                cur_direction = UP;
            } else if(cur_direction == DOWN) {
                cur_row++;
            } else if(cur_direction == UP) {
                cur_column++;
                cur_row--;
            }
        }
        string res;
        for(i = 0; i < nRows; i++) {
            for(j = 0; j < cur_column; j++) {
                if(str[i][j])
                    res.insert(res.end(), str[i][j]);
            }
        }
        return res;
    }
};
