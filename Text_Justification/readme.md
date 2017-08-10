Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
```
For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.
```

Return the formatted lines as:
```
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```
这题感觉要求真多...第一反应是想写成递归，为了保证左边的空格比右边的多，所以倒序插入单词，但又要考虑最后一句要左对齐，搞得最后的if else略多.
leetcode上还有20行的答案，默默记下