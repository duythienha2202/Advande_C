#include <stdio.h>

int myAtoi(char *s)
{
    int res = 0, sign = 1, i = 0; 
    while (s[i] == ' ')
    {
        i++;
    }
    if(s[0] == '-')
    {
        sign = -1;
        i++;
    }
    while(s[i] != '\0')
    {
        res = res*10 + s[i] - '0';
        ++i;
    }
    return sign*res;
}

int main()
{
    char s1[] = "-1234";
    int val1 = myAtoi(s1);
    printf("val1 is: %d\n", val1);
    char s2[] = "234";
    int val2 = myAtoi(s2);
    printf("val2 is: %d\n", val2);
    char s3[] = "34";
    int val3 = myAtoi(s3);
    printf("val3 is: %d\n", val3);
    return 0;
}