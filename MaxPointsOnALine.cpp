/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
bool cmp_func(const Point &a, const Point &b)
{
	if(a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
		if(points.empty())
			return 0;
		if(points.size() <= 2)
			return points.size();

		std::sort(points.begin(), points.end(), cmp_func);        

		int p_a, p_b, p_c, max_num = 0;
		for(p_a = 0; p_a < points.size(); p_a++) {
			int x_a = points[p_a].x;
			int y_a = points[p_a].y;
			int cur_points_num = 1;
			p_b = p_a + 1;

			while(p_b < points.size() && points[p_b].x == x_a
					&& points[p_b].y == y_a) {
				cur_points_num++;
				p_b++;
			}
			if(p_b == points.size()) {
				if(cur_points_num > max_num)
					max_num = cur_points_num;
				break;
			}
			int same_a = cur_points_num;
			for(; p_b < points.size(); p_b++) {
				int x_b = points[p_b].x;
				int y_b = points[p_b].y;
				cur_points_num++;

				for(p_c = p_b + 1; p_c < points.size(); p_c++) {
					int x_c = points[p_c].x;
					int y_c = points[p_c].y;
					if((y_c - y_b) * (x_b - x_a) == (y_b - y_a) * (x_c - x_b))
						cur_points_num++;
				}
				if(cur_points_num > max_num)
					max_num = cur_points_num;
				cur_points_num = same_a;
			}
		}
		return max_num;
	}
};
