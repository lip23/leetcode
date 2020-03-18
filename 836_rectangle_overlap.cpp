//  file:  836_rectangle_overlap.cpp
//  author：lipcat
//  time：  2020-03-18 23:52


class Solution {
public:
    // 先判断x方向是否有重叠，再判断y方向是否有重叠
    // 如果两个矩形有相交则x和y方向都应该有重叠
    // 判断x方向是否有重叠方法：总共x方向有4条直线，如果最小的两条直线属于同一个矩形，则x方向没有重叠
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int min_x1 = min(rec1[0], rec2[0]);
        int min_x2 = min_x1 == rec1[0] ? min(rec2[0], rec1[2]) : min(rec1[0], rec2[2]);
        if ((min_x1 == rec1[0] && min_x2 == rec1[2]) ||
            (min_x1 == rec2[0] && min_x2 == rec2[2])) {
            return false;
        }
        int min_y1 = min(rec1[1], rec2[1]);
        int min_y2 = min_y1 == rec1[1] ? min(rec2[1], rec1[3]) : min(rec1[1], rec2[3]);
        if ((min_y1 == rec1[1] && min_y2 == rec1[3]) ||
            (min_y1 == rec2[1] && min_y2 == rec2[3])) {
            return false;
        }
        return true;
    }
};
