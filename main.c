#include <stdio.h>
#include <time.h>//time as seed value
#include <stdlib.h>//random
#include <string.h>//for strcopy
int inarr(char word[],int len,char l);

int main()
{
    printf("WELCOME TO OUR GAME HANGMAN\nThe rules are:\nYou must guess a character each chance\n");
    printf("If the guessed character is correct it gets filled in \nElse you lose a life\nYou only have 7 lives so play wisely\n\n");
    
    int man = 7;
    srand(time(NULL));
    char words[20][20] = {"rabbit","turtle","gorilla","elephant"};
    int i = rand() %4;
    char final[20];
    strcpy (final, words[i]);//only constant type values can be passed to an array so i had to use strcopy
    //printf("%s",final);
    int lenght = strlen(final);//cannot use lenght to make array because initialisation done at runtime
    int freq[20] = {0};
    // because compiletime initialisation needs to be done arrays but we can use it in a for loop
    int check = 0;
    char letter;
    char wrongentry[30];//for when same wrong entry made twice
    char rightentry[30];//for when right entry made twice
    int index = 0,index1 = 0;
    int won = 0;

    

    
    while(man!=0 && won!=lenght)  // won =  how many char user got right;so when equals lenght you know user has one
    {
        int k;
        for(k=0;k<lenght;k++)
        {

            if (freq[k] == 1)
                printf("%c  ",final[k]);
            else
                printf("%c  ",'_');
           
        }
        printf("%c",'\n');
        printf("%c",'\n');
        printf("enter a character\n");
        //getchar() not used because \n cannot handle
        scanf(" %c",&letter);//takes the \n from before
     
        if (inarr(rightentry,lenght,letter)) // correct element only makes changes if it has not been entered before
        {
            for (k=0;k<lenght;k++)
            {
                if (letter == final[k] )
                {
                    won++;
                    rightentry[index1] = letter;
                    index1++;
                    check = 1;
                    freq[k] = 1;
                }
            }
        }
        else if (inarr(rightentry,lenght,letter) == 0)
        {
            check =1;
        }
        if (check == 0 && inarr(wrongentry,lenght,letter))
        {
            man-- ;
            printf("OH NO!!! YOU LOST A POINT\n\n");
            printf("YOU HAVE ONLY %d LIVES LEFT\n",man);
            wrongentry[index] = letter;
            index++;
        }
        check = 0;
        if (won == lenght )
        {
           
            printf("CONGRATULATIONS!!! YOU HAVE WON\n");
            printf("YOUR WORD WAS -----%s",final);
        }
        
    }
    return 0;
}
int inarr(char word[],int len,char l)//returns 1 when NOT in array
    {
        int h;
        for (h=0;h<len;h++)
        {
            if (word[h] == l)
                return 0;

        }
        return 1;
    }
