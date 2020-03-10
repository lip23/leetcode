//  file:  164_maximum_gap.cpp
//  author：lipcat
//  time：  2020-03-10 10:56

class Solution {
public:
    // 求排序后相邻元素的最大gap
    // 由于max_gap <= (max_val - min_val) / (nums.size() - 1) = bucket_size
    // 所以可以用bucket_size作为桶大小来分桶
    // 桶内的元素之间的gap都是小于bucket_size的，所以max_gap肯定不会存在桶内
    // 因此问题就转化成求相邻桶之间的最大gap
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int min_val = nums.front();
        int max_val = nums.front();
        for (const auto& num : nums) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }
        if (min_val == max_val) {
            return 0;
        }
        int interval = max(1, (max_val - min_val) / static_cast<int>(nums.size() - 1));
        vector<pair<int,int>> buckets((max_val - min_val) / interval + 1, {1, -1});
        for (const auto& num : nums) {
            int ind = (num - min_val) / interval;
            //cout <<"num=" << num << " ind=" << ind << endl;
            if (buckets[ind].first > buckets[ind].second) {
                buckets[ind].first = buckets[ind].second = num;
            } else {
                buckets[ind].first = min(num, buckets[ind].first);
                buckets[ind].second = max(num, buckets[ind].second);
            }
        }
        int ans =interval;
        int pre_max = buckets[0].second;
        for (int i = 1; i < buckets.size(); ++i) {
            if (buckets[i].first > buckets[i].second) {
                continue;
            }
            if (buckets[i].first - pre_max > ans) {
                ans = buckets[i].first - pre_max;
            }
            pre_max = buckets[i].second;
        }
        return ans;
    }
};
