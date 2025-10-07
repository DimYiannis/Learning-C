#include <stdlib.h>

int count_words(const char *s, char *c)
{
    int count = 0;
    int in_word = 0;

    while (*s)
    {
        if (*s != *c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == *c)
        {
            in_word = 0;
        }
        s++;
    }
    return count;
}

int in_sep(char *s, char *c)
{
    int in_sep = 0;
    while (*s && *s == *c)
    {
        in_sep = 1;
        s++;
        
    }
}

int word_length(char *s, char *c)
{
    int length = 0;
    while (*s && *s != *c)
    {
        length++;
        s++;
    }
    return length;
}

char **split(char *s, char *c)
{
    if (!s)
    {
        return NULL;
    }

    int word_count = count_words(s, c);
    char **result = (char **)malloc((word_count + 1)* sizeof(char *));
    if (!result)
    {
        return NULL;
    }

    int i = 0;
    while (*s)
    {
        if (*s != *c)
        {
            int len = word_length(s, c);
            result[i] = (char *)malloc((len + 1) * sizeof(char));
            if (!result[i])
            {
                while (i-- > 0)
                {
                    free(result[i]);
                    free(result);
                    return NULL;
                }  
            }
            int j = 0;
            while ( j < len)
            {
                result[i][j] = *s++;
                j++;   
            }
            result[i][j] = '\0';
            i++;
        }
        else
        {
            s++;
        }
    }
    result[i] = NULL;
    return result;
}

#include <stdio.h>

int main(void)
{
    char str[] = "hello-----there";
    char **arr;
    int i;

    i = 0;
    arr = split(str, '-');
    while (arr[i])
    {
        printf("%s", arr[i]);
        i++;
    }
    return 0;
}
