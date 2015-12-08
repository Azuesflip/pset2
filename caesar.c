#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key = 0;
    string userInput = "";
    int inputLength = 0;
    bool inputGood = false;
    
    do
    {
        // Check to see if user did command prompt correctly.
        if(argc != 2)
        {
            printf("You are not doing the command line prompt correctly.\n");
            printf("Please use: \'./caesar key\' where key is equal to a number 1-26\n");
            // Error code for falure to give proper command prompt.
            return 1;
        }
        else
        {
            key = atoi(argv[1]);
            
            // Check to see if the user used a valid int value to cypher the text.
            if(key >= 1 && key <= 26)
            {
                inputGood = true;
            }
            else
            {
                printf("You are not doing the command line prompt correctly.\n");
                printf("Please use: \'./caesar key\' where key is equal to a number 1-26\n");
                // Error code for failed int value.
                return 2;
            }
        }
    } while(!inputGood);
    
    // Gets input from user to cypher.
    printf("Enter text to Caesar Cypher: \n");
    userInput = GetString();
    
    // Show user their input.
    printf("You entered: \n %s \n", userInput);
    
    printf("Here is your cyphered text: \n");
    
    
    // Creates a variable of the inputs length to cut down on processing time.
    inputLength = strlen(userInput);
    
    // Loop through text and cypher it.
    for(int i = 0; i < inputLength; i++)
    {
        // Check to see if char is alphabetical letter and not a number or symbol.
        if(isalpha(userInput[i]))
        {
            // If the char is a letter check to see if it is uppercase.
            if(isupper(userInput[i]))
            {
                printf("%c", (((userInput[i] - 65) + key) % 26) + 65);
            }
            // Deal with lowercase letter chars
            else
            {
                printf("%c", (((userInput[i] - 97) + key) % 26) + 97);
            }
        }
        // Deal with non-letter chars and print them out.
        else
        {
            printf("%c", userInput[i]);
        }        
    }
    
    // End of program.
    printf("\n");
    return 0;
}
