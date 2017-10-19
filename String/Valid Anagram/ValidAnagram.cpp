// sort
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty() && t.empty()) {
            return true;
        }
        
        if (s.size() != t.size()) {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

// 计数
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty() && t.empty()) {
            return true;
        }
        
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, int> count;
        
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
            count[t[i]]--;
        }
        
        unordered_map<char, int>::iterator it;
        
        for (it = count.begin(); it != count.end(); it++) {
            // 第二属性必须等于0，才是 Anagram
            if (it->second) {
                return false;
            }
        }
        
        return true;
    }
};
