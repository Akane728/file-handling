#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//FILE *add;

void mainMenu();
void addFruits();
void updateFruits();

int main (void) 
{
	
	mainMenu();

	
	
}

void mainMenu()
{
	
	int choice;
	
	
	while (1)
	{
	printf("\n\n\n\t\t\tCHOOSE AN OPTION:\n\n");	
	printf("\t\t\t1.) ADD fruits \n\t\t\t2.) UPDATE fruits \n\t\t\t3.) DELETE fruits \n\t\t\t4.) SEARCH fruits \n\t\t\t5.) JUMBLE fruits \n\t\t\t6.) SUMMARY \n\t\t\t7.) SCORES \n\t\t\t8.) EXIT \n\t\t\tChoice: ");
		if(scanf("%d",&choice))
		{
			switch(choice)
			{
				case 1:
					system("cls");
					addFruits();
					break;
				case 2:
					system("cls");
				    updateFruits();
					break;
				case 3:
					system("cls");
				    //deleteFruits();
				    break;
				case 4:
					system("cls");
				    //searchFruits();
					break;
				case 5:
					system("cls");
				    //jumbleFruits();
				    break;
				case 6:
					system("cls");
				    //summary();
				    break;
				case 7:
					system("cls");
				    //scores();
				    break;
				case 8:
					system("cls");
					printf("\n\n\n\n\n\n\n\t\t\t\t\t\tEXIT PROGRAM!");
				    exit(0);
				default:
					printf("\n\t\t\tWRONG INPUT!");
					printf("\n\n\n\n\n\t\t\tEnter any key...");
					getch();
					system("cls");
					break;
			}
					
		}
		else
		{
			fflush(stdin);
			printf("\n\t\t\tWRONG INPUT!");
			printf("\n\n\n\n\n\t\t\tEnter any key...");
			getch();
			system("cls");
			mainMenu();
		}
	}
}

void addFruits()
{
    char add_fruit[10];
    FILE *add;  // declare the file pointer
    
    add = fopen("addF.txt", "a");
    if (add == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    
    printf("\nEnter a fruit: ");
    if (scanf(" %9s", add_fruit) != 1)
    {
        fprintf(stderr, "Error reading input\n");
        exit(1);
    }
    
    if (fprintf(add, "%s\n", add_fruit) < 0)
    {
        fprintf(stderr, "Error writing to file\n");
        exit(1);
    }
    
    if (fclose(add) != 0)
    {
        fprintf(stderr, "Error closing file\n");
        exit(1);
    }
  	
    printf("\nThe fruit is added!\n");
} 

void updateFruits()
{
	FILE *search, *update;
    char word[100], ch, read[100], replace[100];
    int word_len, i, p = 0;
 
    search = fopen("addF.txt", "r");
    update = fopen("addF.txt", "w+");
    if (search == NULL || update == NULL) {
        printf("Can't open file.");
        exit(0);
    }
    puts("THE CONTENTS OF THE FILE ARE SHOWN BELOW :\n");
 
    // displaying file contents
    while (1) {
        ch = fgetc(search);
        if (ch == EOF) {
            break;
        }
        printf("%c", ch);
    }
 
    puts("\n\nEnter the word to find:");
    fgets(word, 100, stdin);
 
    // removes the newline character from the string
    word[strlen(word) - 1] = word[strlen(word)];
 
    puts("Enter the word to replace it with :");
    fgets(replace, 100, stdin);
 
    // removes the newline character from the string
    replace[strlen(replace) - 1] = replace[strlen(replace)];
 
    fprintf(update, "%s - %s\n", word, replace);
 
    // comparing word with file
    rewind(search);
    while (!feof(search)) {
 
        fscanf(search, "%s", read);
 
        if (strcmp(read, word) == 0) {
 
            // for deleting the word
            strcpy(read, replace);
        }
 
        // In last loop it runs twice
        fprintf(update, "%s ", read);
    }
 
    // Printing the content of the Output file
    rewind(update);
    while (1) 
	{
        ch = fgetc(update);
        if (ch == EOF) {
            break;
        }
        printf("%c", ch);
    }
 
    fclose(search);
    fclose(update);
}
		
