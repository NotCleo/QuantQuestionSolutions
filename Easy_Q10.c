#include <stdio.h>

int main() 
{
    long long digitsumcount = 0;

    for (int i = 1; i <= 1000000; i++) 
    {
        int num = i;
        while (num != 0) 
        {
            digitsumcount += num % 10;
            num /= 10;
        }
    }

    printf("Total sum of all digits from 1 to 1,000,000: %lld\n", digitsumcount);
    return 0;
}
