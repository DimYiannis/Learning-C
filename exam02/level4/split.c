#include <stdlib.h>

// Check if a character is whitespace
int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

// Count the number of words in the string
int count_words(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        while (str[i] && is_whitespace(str[i]))
            i++;
        if (str[i] && !is_whitespace(str[i]))
        {
            count++;
            while (str[i] && !is_whitespace(str[i]))
                i++;
        }
    }
    return count;
}

// Allocate a word
char *alloc_word(char *start, int len)
{
    char *word = (char *)malloc(sizeof(char) * (len + 1));
    int i;

    if (!word)
        return NULL;

    i = 0;
    while (i < len)
    {
        word[i] = start[i];
        i++;
    }
    word[i] = '\0';
    return word;
}

// Main ft_split function
char **ft_split(char *str)
{
    int words = count_words(str);
    char **arr = (char **)malloc(sizeof(char *) * (words + 1));
    int i = 0;
    int w = 0;
    int start;

    if (!arr)
        return NULL;

    while (str[i] && w < words)
    {
        while (str[i] && is_whitespace(str[i]))
            i++;
        start = i;
        while (str[i] && !is_whitespace(str[i]))
            i++;
        arr[w++] = alloc_word(str + start, i - start);
    }
    arr[w] = NULL;
    return arr;
}
