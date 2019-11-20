//  file:  223_rectangle_area.cpp
//  author：lipcat
//  time：  2019-11-20 23:19


class Solution {
public:
    // 解题思路：
    // 计算两个举行共同包含的区域的时候可以先分别计算公共x和公共y的长度
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int delta_x = 0;
        if (E >= A && E <= C) {
            delta_x = min(C, G) - E;
        } else if (A >= E && A <= G) {
            delta_x = min(C, G) - A;
        }
        int delta_y = 0;
        if (H >= B && H <= D) {
            delta_y = H - max(F, B);
        } else if (D >= F && D <= H) {
            delta_y = D - max(F, B);
        }
        //cout << "dx=" << delta_x << " dy=" << delta_y <<endl;
        return (C - A) * (D - B) - delta_x * delta_y + (G - E) * (H - F);
    }
};
