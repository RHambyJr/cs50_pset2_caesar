/*
 * Robert Hamby
 * Caesarian Shift encryption exercise
 * CS50 - PSet2 - caesar
 * Program takes a command line argument int, to shift message that number of letters
 * Takes user input once program has started, and outputs encrypted text
 * Case sensative, and ignores punctuations (or letters that's not in the english alphabet, really...)
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void shiftText(string text, int shift);
char caesarianShift(char letter, int shift);

int main(int argc, string argv[])
{
    // Checks to see if more than one command line argument was added
    if (argc != 2)
    {
        printf("Error. Please provide one (and only one) number to shift the alphabet.\n");
        return EXIT_FAILURE;
    }

    // Converts command line argument to int
    int shift = strtol(argv[1], NULL, 10);

    // Gets user text to encrypt
    string text = get_string("plaintext:");
    printf("ciphertext:");
    // Converts user text
    shiftText(text, shift);
    printf("\n");
}

/*
 * Takes a string of text and an int to shift, and prints out shifted (encrypted) text
 * Arguments: string for text to be encrypted
 *            int for number of places a letter should shift
 * Returns: nothing
 */
void shiftText(string text, int shift)
{
    //holds current element in string
    int pos = 0;
    //cycles through each element in array and calls checkLetter then prints
    while (text[pos] != '\0')
    {
        char letter = text[pos];
        if (isalpha(letter))
        {
            letter = caesarianShift(letter, shift);
        }

        printf("%c", letter);
        pos++;
    }
}

/*
 * Uses the equation cᵢ = (pᵢ + k) % 26
 * cᵢ is the cypher text, pᵢ is the plaintext, and k is the shift amount
 * Takes a letter and converts it to alpha key (a = 0, z = 26).
 * Performs caesarian shift equation, then converts back to ascii
 * Arguments: char for letter to be shifted
 *            int for number of places to shift
 *            bool for whether letter is capital or not
 * Returns: char caesarian shifted letter
 */
char caesarianShift(char letter, int shift)
{
    const int UPPER_A = (int)'A';
    const int LOWER_A = (int)'a';
    const int ALPHA = 26;
    int ascii = (int)letter;
    char converted; // holds shifted character
    bool upper = isupper(letter);

    //Applies caesarian shift forumla to base ascii 65 or 97, depending on upper or not
    if (upper)
    {
        converted = (((ascii - UPPER_A) + shift) % ALPHA) + UPPER_A;
    }
    else
    {
        converted = (((ascii - LOWER_A) + shift) % ALPHA) + LOWER_A;
    }

    return converted;
}