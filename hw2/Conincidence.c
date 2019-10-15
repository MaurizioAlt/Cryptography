//Cameron Lohr
//CIS3362
//This program is designed find the index of coincidence from two strings.
//It takes two strings, counts the number of characters, and processes the Index of Coincidence from that.
//The final results are then printed out on the terminal window as output is relatively minimal.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	//Variables
	char input[2][500];
	int i, j;
	int length[2];
	double IoC[2];
	int IoCFrac[2];
	//Set all character counts to 0 to prevent counting errors.
	int charcount[2][26];
	for (i=0; i < 2; i++){
		for(j = 0; j < 26; j++){
			charcount[i][j] = 0;
		}
	}
	//Taking in those meaty inputs
	printf("Please enter the first string...\n");
	scanf("%s", input[0]);
	printf("Please enter the second string...\n");
	scanf("%s", input[1]);
	//Length of each string.
	length[0] = strlen(input[0]);
	length[1] = strlen(input[1]);
	//Sets all the characters to lowercase for simplicity.
	for (i=0; i < 2; i++){
		for(j = 0; j < length[i]; j++){
			input[i][j] = tolower(input[i][j]);
		}
	}
	
	//Count the number of characters in the strings...
	for (i=0; i < 2; i++){
		for(j = 0; j < length[i]; j++){
    		if (input[i][j] == 'a') 
            charcount[i][0] = charcount[i][0] + 1; 
            else if (input[i][j] == 'b') 
			charcount[i][1] = charcount[i][1] + 1;
			else if (input[i][j] == 'c') 
			charcount[i][2] = charcount[i][2] + 1;
			else if (input[i][j] == 'd') 
			charcount[i][3] = charcount[i][3] + 1;
			else if (input[i][j] == 'e') 
			charcount[i][4] = charcount[i][4] + 1;
			else if (input[i][j] == 'f') 
			charcount[i][5] = charcount[i][5] + 1;
			else if (input[i][j] == 'g') 
			charcount[i][6] = charcount[i][6] + 1;
			else if (input[i][j] == 'h') 
			charcount[i][7] = charcount[i][7] + 1;
			else if (input[i][j] == 'i') 
			charcount[i][8] = charcount[i][8] + 1;
			else if (input[i][j] == 'j') 
			charcount[i][9] = charcount[i][9] + 1;
			else if (input[i][j] == 'k') 
			charcount[i][10] = charcount[i][10] + 1;
			else if (input[i][j] == 'l') 
			charcount[i][11] = charcount[i][11] + 1;
			else if (input[i][j] == 'm') 
			charcount[i][12] = charcount[i][12] + 1;
			else if (input[i][j] == 'n') 
			charcount[i][13] = charcount[i][13] + 1;
			else if (input[i][j] == 'o') 
			charcount[i][14] = charcount[i][14] + 1;
			else if (input[i][j] == 'p') 
			charcount[i][15] = charcount[i][15] + 1;
			else if (input[i][j] == 'q') 
			charcount[i][16] = charcount[i][16] + 1;
			else if (input[i][j] == 'r') 
			charcount[i][17] = charcount[i][17] + 1;
			else if (input[i][j] == 's') 
			charcount[i][18] = charcount[i][18] + 1;
			else if (input[i][j] == 't') 
			charcount[i][19] = charcount[i][19] + 1;
			else if (input[i][j] == 'u') 
			charcount[i][20] = charcount[i][20] + 1;
			else if (input[i][j] == 'v') 
			charcount[i][21] = charcount[i][21] + 1;
			else if (input[i][j] == 'w') 
			charcount[i][22] = charcount[i][22] + 1;
			else if (input[i][j] == 'x') 
			charcount[i][23] = charcount[i][23] + 1;
			else if (input[i][j] == 'y') 
			charcount[i][24] = charcount[i][24] + 1;
			else if (input[i][j] == 'z') 
			charcount[i][25] = charcount[i][25] + 1;
			else
			printf("Character not found... make sure you only entered letters!\n");
		}
	}
	
	//A working array for calculating the IoC tally
	int working[26];
	int final = 0;
	for(i=0; i<26; i++){
		working[i] = 0;
	}
	//Finding the IoC in decimal value. Saves the tally in a separate value for printing the fraction.
	for(i=0;i<2;i++){
		final = 0;
		for(j = 0; j < 26; j++){
			working[j] = charcount[i][j] * (charcount[i][j] -1);
			final = final + working[j];
		}
		IoCFrac[i] = final;
		IoC[i] = final;
		IoC[i] = IoC[i] / (length[i] * (length[i] - 1));
	}
	
	//Print the final results
	printf("\nIf a character doesn't appear, it is not present in the string!\n");
	for (i=0; i < 2; i++){
		printf("\nString %d! The IoC of this string is %lf decimal, %d / %d fraction.", i, IoC[i], IoCFrac[i], length[i] * (length[i] - 1));
		printf("\n------------------------------------------\n");
		for(j = 0; j < 26; j++){
			if(charcount[i][j] != 0){
				printf("The number of %c's in String %d is %d! \n",j + 'a', i, charcount[i][j]);
			}
		}
	}
	
	return 0;
}
