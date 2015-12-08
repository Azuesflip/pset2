#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    printf("Please enter your name: \n");
    
    string name = GetString();
    
    if(name != NULL)
    {
        printf("%c", toupper(name[0]));
        
        for( int i = 0; i < strlen(name); i++)
        {
            if(name[i] == 32)
            {
                printf("%c", toupper(name[i + 1]));
            }
        }
        
        printf("\n");
        printf("Thank you there are your initials!\n");
    }
}
