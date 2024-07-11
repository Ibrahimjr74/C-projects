#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int lineno;
	int linelen;
	char linetext[100];
}fileline;

typedef struct{
bool isCorrect;
int linelen;
char linetext[100];
}Syntaxerror;

typedef struct{
int Arrnum[100];
char letterint;
}runtime_error;

typedef struct{
int arr[n];
int value;
}logical_error;

void file_reading(fileline [],int* linelen);
FILE *fptr;
 fptr = fopen("Syntax.txt", "r");
  if (fptr != NULL) {
    printf("File Open Successful");
  }
  else {
    printf("File Open Unsuccessful");
  }



}


int main(&argc &argv){



printf("paste your code here\n");

