//Cameron Lohr
//CIS3362
//This program is designed to help decode the Vignere Cipher.
//It takes in a list of keys, attempts to decode every variation, and prints them to a file.
//You are then able to search that file via a text editor (I used Notepad++) to find the correct answer.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	//Variables for the file.
	char filename[20];
	char input[500];
	//Variables for the algo
	int i, j, buzzlength, codelength, bigloop;
	char code[500];
	char buzzword[1000][25];
	char buzzwordcode[1000][500];
	char codenomore[1000][500];
	
	//This function reads in the 1000 possible keys.
	printf("Please enter the location of the dictionary file:\n");
	scanf("%s", filename);
	FILE *buzzlist = fopen(filename, "r");
	if (buzzlist == NULL){
		printf("File could not be read...\n");
	}
	while (fgets(buzzword[i], 500, buzzlist) != NULL){
		buzzword[i][strlen(buzzword[i]) - 1] = '\0';
		i++;
	}
	//Print function for initial testing purposes.
//    for(i = 0; i < 1000; ++i)	{
//        printf("%s\n", buzzword[i]);
//	}
	//Takes in the code and file of words to be tested...
	//I also added a manual input for inital algorithm testing. It's been commeted out for the main functionality.
	printf("Enter the scrambled message... (No Spaces or Puncuation Please!)\n");
	scanf("%s", code);
	codelength = strlen(code);
	
//	printf("Enter the keyword... (Testing Purposes Only before trying the list...)\n");
//	scanf("%s", buzzword);
	//This is the main loop for obtaining all of the encrypted codes.
	for (bigloop = 0; bigloop < 1000 ; bigloop ++){
		//Gets the length of the next possible key.
		buzzlength = strlen(buzzword[bigloop]);
		//Pads the key with itself until the length is equal to the message.
		for (i=0, j=0; i < codelength ; i++, j++){
			if (j == buzzlength){
				j = 0;
			}
		buzzwordcode[bigloop][i] = buzzword[bigloop][j];
	}
	//Adds a end character to signify the end of the message.
	buzzwordcode[bigloop][i] = '\0';
	//Decrypting Algorithm
	i = 0;
	while(i < codelength){
		codenomore[bigloop][i] = (((code[i] - buzzwordcode[bigloop][i])+26) % 26) + 'A';
		i = i + 1;
	}
	//Adds another end character to signify the end of the message.
	codenomore[bigloop][i] = '\0';
	
	}
	//Prints out the decoded message. (Testing Purposes)
//	printf("The orignal plaintext was...\n");
//	for(i = 0; i < 1000; ++i) {
//    	printf("Key: %s \n Code: %s\n", buzzword[i], codenomore[i]);
//	}
	
	
	FILE *codelist = fopen ("output.txt","w");
	for(i = 0; i < 1000;i++){
       fprintf (codelist, "Key: %s \n Decoded Text: %s\n\n\n", buzzword[i], codenomore[i]);
   	}
   	printf("Output has been printed to /whereeverthisprogramislocated/output.txt\n");
	
	fclose (codelist);
	fclose (buzzlist);
	
	return 0;
}
