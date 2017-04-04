题目是Longest Substring Without Repeating Characters，在给定字符串中找最长的无重复字符的子串


自己的问题：
1. 一开始不熟悉string，find函数第二参数以为是tail，然而是length。
2. 没有考虑到空string。


更好的代码，使用了hash_map，加快检索的速度，
```
   public int lengthOfLongestSubstring(String s) {
        if (s.length()==0) return 0;
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int max=0;
        for (int i=0, j=0; i<s.length(); ++i){
            if (map.containsKey(s.charAt(i))){
                j = Math.max(j,map.get(s.charAt(i))+1);
            }
            map.put(s.charAt(i),i);
            max = Math.max(max,i-j+1);
        }
        return max;
    }
```


