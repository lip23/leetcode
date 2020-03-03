//  file:  593_valid_square.cpp
//  author：lipcat
//  time：  2020-03-03 17:57


class Solution {
public:
    // 4个节点两两之间共有6条边
    // 其中4较短的边长度相等，2条较长边的长度相等，并且两条较短边的平方和等于较长边的平方
    // 为了避免在计算两点之间距离时开根号造成精度损失，可以用边长的平方代替边长
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int, int> um;
        ++um[pow(p1.front() - p2.front(), 2) + pow(p1.back() - p2.back(), 2)];
        ++um[pow(p1.front() - p3.front(), 2) + pow(p1.back() - p3.back(), 2)];
        ++um[pow(p1.front() - p4.front(), 2) + pow(p1.back() - p4.back(), 2)];
        ++um[pow(p2.front() - p3.front(), 2) + pow(p2.back() - p3.back(), 2)];
        ++um[pow(p2.front() - p4.front(), 2) + pow(p2.back() - p4.back(), 2)];
        ++um[pow(p3.front() - p4.front(), 2) + pow(p3.back() - p4.back(), 2)];
        return um.size() == 2 && um.begin()->second == 4 && um.rbegin()->second == 2 &&
            um.begin()->first * 2 == um.rbegin()->first;
    }
};
