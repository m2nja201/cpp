#include <stdio.h>

int main()
{
    char input;
    scanf("%c", &input);
    
    if ((input >= '0' && input <= '9') || (input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')){
        printf("%d", input);
    }
    return 0;
}