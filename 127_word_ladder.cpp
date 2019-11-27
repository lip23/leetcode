//  file:  127_word_ladder.cpp
//  author：lipcat
//  time：  2019-11-28 00:38


class Solution {
public:
    // solution
    // jump game2解法，维护一个当前一种走到的数组集合
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> used(wordList.size(), false);
        vector<string> words(1, beginWord);
        int cur = 0, level_end = 1, level = 1;
        while (cur < words.size()) {
            for (int i = 0; i < wordList.size(); ++i) {
                if (used[i] == false && diffCount(words[cur], wordList[i]) == 1) {
                    if (wordList[i] == endWord) {
                        return level + 1;
                    } else {
                        words.push_back(wordList[i]);
                        used[i] = true;
                    }
                }
            }
            if (++cur == level_end) {
                ++level;
                level_end = words.size();
            }
        }
        return 0;
    }
    int diffCount(const string& lhs, const string& rhs) {
        int count = 0, cur = 0;
        while (cur < lhs.length() && cur < rhs.length()) {
            if (lhs[cur] != rhs[cur]) {
                ++count;
            }
            ++cur;
        }
        return count + lhs.length() + rhs.length() - 2 * cur;
    }
};
