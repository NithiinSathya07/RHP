#include <iostream>
//To check elements from 0-9
int main() 
{
    char str[1000001];
    scanf("%s", str);
    int flag = 0;

    for(int i = 0; str[i]; i++)
    {
        if (str[i] >= '0' && str[i] <= '9') 
        {
            // Map '0'-'9' to bits 0-9
            flag |= (1 << (str[i] - '0'));
        }
    }

    // 10 bits set to 1 equals (2^10 - 1) which is 1023
    printf((flag == (1 << 10) - 1)?"Yes":"No");
    return 0;
}