#include <stdio.h>
#include <string.h>

#define SIZE_NAME 16
#define SIZE_CHARACTERS 21

/******************
 * Function Name:sort
 * Input: Array of separated words, number of words
 * Output: Void
 * Function Operation: Sorting the array
 ******************/

void sort(char sortedArr[][SIZE_CHARACTERS], int wordNum)
{

    char temp[SIZE_CHARACTERS];
    const int ONE = 1;

    // sorting the names by alphabetical order, comparing first name
    for (int k = 0; k < wordNum - ONE; k++)
    {

        // comparing second name
        for (int j = k + ONE; j < wordNum; j++)
        {

            // replace names only if the left name is bigger than right name
            if (strcmp(sortedArr[k], sortedArr[j]) > 0)
            {

                // replacing the order
                strcpy(temp, sortedArr[k]);
                strcpy(sortedArr[k], sortedArr[j]);
                strcpy(sortedArr[j], temp);
            }
        }
    }
}

/******************
 * Function Name:strList
 * Input: Empty array of words, array of words, array for the hint, array of tokens
 * Output: Number of elements in the array
 * Function Operation: separating array by words
 ******************/

int strList(char sortedArr[][SIZE_CHARACTERS], char mainStr[], char hint[], char sep[])
{

    // making a var to know where the words begin
    const char start = ':';

    // saving the hint
    for (int i = 0; mainStr[i] != start; i++)
    {
        hint[i] = mainStr[i];
    }

    // making a pointer to start from the first word
    char *token;
    token = strchr(mainStr, start);

    // separating the words
    token += sizeof(char);
    token = strtok(token, sep);

    // amount of words in the game
    int wordNum = 0;

    // coping each word to a new array
    while (token != NULL)
    {
        strcpy(sortedArr[wordNum], token);
        token = strtok(NULL, sep);
        wordNum++;
    }

    // returning the number of words in the game
    return wordNum;
}

/******************
 * Function Name:shape
 * Input:number of stage
 * Output:Void
 * Function Operation: printing the shape
 ******************/

void shape(int stage)
{
    const int ZERO = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6;

    // Stage 1 print
    if (stage == ONE)
    {
        printf("____________\n");
        for (int t = 0; t < FIVE; t++)
        {
            printf("|          |\n");
        }
        printf("|___________|\n");
    }

    // stage 2 print
    else if (stage == TWO)
    {
        printf("____________\n");
        for (int t = 0; t < FIVE; t++)
        {
            if (t == ONE || t == TWO)
            {
                printf("| **         |\n");
            }
            else
            {
                printf("|         |\n");
            }
        }
        printf("|__________|\n");
    }

    // stage 3 print
    else if (stage == THREE)
    {
        printf("____________\n");
        for (int t = 0; t < FIVE; t++)
        {
            if (t == ONE || t == TWO)
            {
                printf("| **       ** |\n");
            }
            else
            {
                printf("|            |\n");
            }
        }
        printf("|_____________|\n");
    }

    // stage 4
    else if (stage == FOUR)
    {
        printf("_______________\n");
        for (int t = 0; t < FIVE; t++)
        {
            if (t == ZERO)
            {
                printf("|  --       |\n");
            }
            else if (t == ONE || t == TWO)
            {
                printf("| **    ** |\n");
            }
            else
            {
                printf("|        |\n");
            }
        }
        printf("|_________|\n");
    }

    // stage 5
    else if (stage == FIVE)
    {
        printf(" _________________\n");
        for (int t = 0; t < FIVE; t++)
        {
            if (t == ZERO)
            {
                printf("|  --        --  |\n");
            }
            else if (t == ONE || t == TWO)
            {
                printf("|  **        **  |\n");
            }
            else
            {
                printf("|                |\n");
            }
        }
        printf("|________________|\n");
    }

    // stage 6 print
    else if (stage == SIX)
    {
        printf(" _________________\n");
        for (int t = 0; t < FIVE; t++)
        {
            if (t == ZERO)
            {
                printf("|  --        --  |\n");
            }
            else if (t == ONE || t == TWO)
            {
                printf("|  **        **  |\n");
            }
            else if (t == FOUR)
            {
                printf("| \\/\\/\\/\\/\\/\\/\\  |\n");
            }
            else
            {
                printf("|                |\n");
            }
        }
        printf("|________________|\n");
    }
}

/******************
* Function Name:game
* Input:sorted array, chosen option to play, length of the option, the hint arrray
* Output:Void
* Function Operation: playing "Hang Man"
******************/

void game(char sortedArr[][SIZE_CHARACTERS], int option, int lenOfOption, char hint[]){

    // var to know in what stage you are
    int stage = 1;

    // flags for the clue and the same letter statement
    int hintFlag = 1;
    int outFlag= 1;
    int correctFlag =1;

    //array of answers
    char answers[SIZE_CHARACTERS];

    //index of the letter in the array
    int letIndex = 0;

    //choice of the user
    char choice = 0;
    char enter;

    // constant chars for the arrays of the answer and the line
    const char UNDERLINE = '_', SPACE = ' ', ASTERISK = '*' ;

    //answer line array
    char line[lenOfOption];

    //making the answer line
    for (int i = 0; i < lenOfOption; i++)
    {
        //if the spot is a letter
        if(sortedArr[option][i] != SPACE){
            line[i] = UNDERLINE;
        }

        //if the spot is a space
        else{
            line[i] = SPACE;
        }
    }
    
    //constant integers for the logic tree in the game
    const int ZERO =0, ONE =1, SIX= 6;

    //the game itself
    while(ONE){

        //printing shape
        shape(stage);

        //checking if the user won, if he did - break
        if (strcmp(line, sortedArr[option]) == ZERO){
            printf("the word is %s, good job!", sortedArr[option]);
            break;
        }

        //printing the answer line
        for(int i = 0; i < lenOfOption; i++){
            printf("%c", line[i]);
        }

        //checking the need of printing the "hint" statement
        if(hintFlag == ONE) {
            printf("\ndo you want a clue? press -> *");
        }

        //letters the user tried
        printf("\nThe letter that you already tried:");

        //printing the array of the used letters
        for(int k =0; k<letIndex; k++){
            if(k == letIndex - ONE) {
                printf("%c", answers[k]);
            }
            else{
                printf("%c", answers[k]);
            }
        }

        //asking fo a letter
        printf("\nplease choose a letter:\n");

        scanf("%*[^\n]");
        scanf("%*[^\n]");
        scanf("%c %c", &enter, &choice);

        //if the user wants a clue
        if(choice == ASTERISK && hintFlag == ONE){
            printf("the clue is: ");
            for(int i = 0; i< strlen(hint); i++){
                printf("%c", hint[i]);
            }
            printf(".\n");
            hintFlag = 0;
        }

        //if the user doesnt want a clue
        else if(choice != ASTERISK){

            //checking if the letter was used
            for(int i =0; i< letIndex; i++){

                //if the letter was used
                if(choice == answers[i]){
                    outFlag = 0;
                }
            }

            //if it hasnt been used
            if(outFlag == ONE){

                //put it in the used letters array
                answers[letIndex] = choice;
                letIndex++;

                //if the letter is correct
                for(int i = 0; i< lenOfOption; i++){
                    if (sortedArr[option][i] == choice)
                    {
                        line[i] = choice;
                        correctFlag=0;
                    }
                    
                }

                //if the letter is wrong
                if(correctFlag == ONE){

                    //raise a stage
                    stage++;

                    //if its the final stage
                    if(stage == SIX) {
                        shape(stage);
                        printf("The word is %s, GAME OVER!", sortedArr[option]);
                        break;
                    }
                }
            }

            //if the letter was used
            else{
                printf("You have already tried that letter. \n");
            }

        }

        //redefine all flags
        outFlag = 1;
        correctFlag = 1;
    }

}

int main() {

    //the main array of words to be guessed in the game
    char mainStr[SIZE_NAME * SIZE_CHARACTERS];
    char sortedArr[SIZE_NAME][SIZE_CHARACTERS];
    char hint[SIZE_CHARACTERS] = {0};

    //asking the user for words
    printf("Enter your words:\n");
    scanf("%[^\n]", mainStr);


    //sending the array of words be seperated and getting the number of words
    int wordNum = strList(sortedArr, mainStr, hint, ",");

    //sending the seperated array to be sorted
    sort(sortedArr, wordNum);

    //printing the sorted array as a list
    const int ONE = 1;
    printf("choose an option:\n");
    for(int i = 0; i<wordNum; i++){
        printf("%d: %s\n", (i + ONE), sortedArr[i]);
    }

    //var to store the option
    int option;
    scanf("%d", &option);
    option -= ONE;

    //checking the length of the word. because the array begin from 0, but the list from 1, so (option-  1).
    int lenOfOption = strlen(sortedArr[option]);

    //going to start the game!
    game(sortedArr, option, lenOfOption, hint);

    return 0;

}