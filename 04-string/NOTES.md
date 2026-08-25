> **字符串专题笔记**
>
> 做题过程中随手积累，专题收尾时统一整理。

# 题目回顾

## leetcode_28_find_first_occurrence_in_string

为什么这么求next数组？

```cpp
vector<int> next(needle.size(), 0);
// 求next数组
// i为后缀末尾，j为前缀末尾
int j = 0;
// TODO 暂时有一点不理解，但原理是根据最长相等前后缀的长度
for (int i = 1; i < next.size(); i++) {
    while (j > 0 && needle[i] != needle[j]) {
        j = next[j - 1];
    }
    if (needle[i] == needle[j])j++;
    next[i] = j;
}
```

