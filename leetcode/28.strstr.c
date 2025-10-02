/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

int ft_strncmp(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while (i < n && (s1[i] || s2[i]))
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
      i++;
    }
    return 0;
}
int strStr(char* haystack, char* needle) {
    int i;
    int len;

    len = 0;
    while (needle[len])
    {
        len++;
    }
    if (len == 0)
		return (0);
    i = 0;
    while (haystack[i])
    {
        if (ft_strncmp(haystack+i, needle, len) == 0)
        {
           return i;
        }
        i++;
    }
    return -1;
}

#include <stdio.h>
int main()
{
    char *haystack; 
    char *needle;
    
    haystack = "aaaabbbaaaaaaabbababbbbabababbbbbbbaaaaaaabbaaabbaababbbbababababaabbbbbbaaaaababbbbaaabababbbaaaabbbaabbbbbbabababbabaaaaabaabaaababbbaaabaababbaaabaaababbabbbbababaaaaaaababaabaabbaabbbaaabaaaaaa";
    needle = "abb";
    printf("%d ", strStr(haystack, needle));
}