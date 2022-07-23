#include <stdio.h>

void my_reverse(char str[], int len)
{
    int start, end;
    char temp;
    for(start=0, end=len-1; start < end; start++, end--) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
    }
}
 
char* my_itoa(int num, char* str, int base)
{
    int i = 0, isNegative = 0;
    if (num == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }
    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }
  
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'A' : rem + '0';
        num = num/base;
    }

    if (isNegative){
        str[i++] = '-';
    }
  
    str[i] = '\0';
 
    my_reverse(str, i);
  
    return str;
}

int main() {
    int i, b;
    char charArray[128];
    printf("Enter a number\n");
    scanf("%d", &i);
    printf("Enter base\n");
    scanf("%d", &b);
    printf("String : %s", my_itoa(i, charArray, b));
    return 0;
}
 