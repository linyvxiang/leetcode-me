/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.empty())
            return 0;
        if(points.size() <= 2)
            return points.size();

        int i, j, k, max_num = 0;
        for(i = 0; i < points.size(); i++) {
            for(j = i + 1; j < points.size(); j++) {
                Point x1 = points[i], x2 = points[j];
                if(x1.x == x2.x && x1.y == x2.y)
                    continue;
                int cur_num = 0;
                for(k = 0; k < points.size(); k++) {
                    if((points[k].y - x2.y) * (x1.x - x2.x) ==
                        (points[k].x - x2.x) * (x1.y - x2.y))
                        cur_num++;
                }
                if(cur_num > max_num)
                    max_num= cur_num;
            }
        }
        return max_num ? max_num : points.size();
    }
};
