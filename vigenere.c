#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int cypherKey(int index, string key);
void cypher(string input, string key);

int main(int argc, string argv[])
{
    string key = "";
    string userInput = "";
    bool inputGood = false;
    
    do
    {
        // Check to see if user did command prompt correctly.
        if(argc != 2)
        {
            printf("You are not doing the command line prompt correctly.\n");
            printf("Please use: \'./vigenere key\' where key is a single word to use as your cypher\n");
            // Error code for falure to give proper command prompt.
            return 1;
        }
        else
        {
            key = argv[1];
            
            int keyLen = strlen(key);
            
            // Check to see if the user used a valid int value to cypher the text.
            for(int i = 0; i < keyLen; i++)
            {
                if(isalpha(key[i]))
                {
                    inputGood = true;
                }
                else
                {
                    printf("You are not doing the command line prompt correctly.\n");
                    printf("Please use: \'./vigenere key\' where key is a single word to use as a cypher\n");
                    // Error code for failed int value.
                    return 2;
                }
            }
        }
    } while(!inputGood);
    
    // Gets input from user to cypher.
    printf("Enter text to Vigenere Cypher: \n");
    userInput = GetString();
    
    // Show user their input.
    printf("You entered: \n %s \n", userInput);
    
    printf("Here is your cyphered text: \n");
    
    cypher(userInput, key);
    
    return 0;
}

int cypherKey(int index, string key)
{
    int keyOutput = 0;
    
    if(isupper(key[index]))
    {
        keyOutput = key[index] - 65;
    }
    else
    {
        keyOutput = key[index] - 97;
    }
    
    return keyOutput;
}

void cypher(string input, string key)
{
    int counter = 0;
    int keyLength = strlen(key);
    int inputLength = strlen(input);
    int cypherInt = 0;
    
    for(int i = 0; i < inputLength; i++)
    {
        if(isalpha(input[i]))
        {
            if(isupper(input[i]))
            {
                cypherInt = cypherKey(counter, key);
                printf("%c", (((input[i] - 65) + cypherInt) % 26) + 65);
            }
            else
            {
                cypherInt = cypherKey(counter, key);
                printf("%c", (((input[i] - 97) + cypherInt) % 26) + 97);
            }
            // The video zamyla made with the modulo example is incorrect for the requirements for this problem... messed me up for a while till I saw the clip in the actual specs. May need to remake video for future students.
            // Good example on how to solve the problem in a real life situation but just doesn't match up to problem specs.
            if(counter < keyLength - 1)
                counter++;
            else
                counter = 0;
        }
        else
        {
            printf("%c", input[i]);
        }
    }
    
    printf("\n");
}
