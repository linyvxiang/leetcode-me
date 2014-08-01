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
        if(points.size() == 0 || points.size() == 1)
            return points.size();
        int cur_pos, sec_pos, front_pos, max_num = -1;
        for(cur_pos = 0; cur_pos < points.size(); cur_pos++) {
            for(sec_pos = cur_pos + 1; cur_pos < points.size(); cur_pos++) {
                if(same_points(cur_pos, sec_pos, points))
                    continue;
                int diff_x = points[cur_pos].x - points[sec_pos].x;
                int diff_y = points[cur_pos].y - points[cur_pos].y;
                int cur_num = 2;
                for(front_pos = 0; front_pos < points.size();
                            front_pos++) {
                    if(same_points(cur_pos, front_pos, points)
                        || same_points(sec_pos, front_pos, points))
                        continue;
                    int dx = points[front_pos].x - points[cur_pos].x;
                    int dy = points[front_pos].y - points[cur_pos].y;
                    if(dx * diff_y == dy * diff_x)
                        cur_num++;
                }
                if(cur_num > max_num)
                    max_num = cur_num;
            }
        }
        return max_num;
    }
private:
    bool same_points(int a, int b, vector<Point> &points)
    {
        return points[a].x == points[b].x &&
                points[a].y == points[b].y;
    }
};
