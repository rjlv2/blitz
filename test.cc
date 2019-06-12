#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <vector>
#include <string>
#include <iostream>

#define SIZE 335909

using namespace std;

typedef struct {
	//properties of next character
	int start[26];
	int end[26];
	
	char curChar;
	int curStart;
	int curEnd;
	
	//character index
	int idx;
	
	//word index
	int wordIdx;
	
	//store of previous characters
	char prev[16];
	
	int boxnum;
	char neighbours[8];
	int boxUsed[16];
	
} lchar;

struct {
	int start[26];
	int end[26];
} charInit;

class grid
{
	public:
		bool used[4][4];
		bool neighbours[4][4];
		bool possible_moves[4][4];
		
		int position[4][4];
		int charIdx;
		
		char boxChar;
		
		void setPos();
		void move();
}

struct {
	int row;
	int col;
	bool used[4][4];
	int charIdx;
	char prev[16];
	char curChar;
}

//check all possible moves
void traverse()
{
	for(i=0; i<4; i++){ //TODO traverse function
		for(j=0; j<4; j++){
			if(possible_move(curPos, i, j)){ //TODO
				row = i; //create a new variable
				col = j;
				used += curPos;
				prev[charIdx] = curChar;
				charIdx++;
				curChar = character(i, j); //TODO
				traverse(newvar);//TODO //if cant continue then this function prints
			}
		}
		printf("%s\n", prev);
	}
}


void findchar(lchar next){
	
}



int main()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    char database[SIZE][16]; 

    fp = fopen("words6.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
		
		int i=0;
    while ((read = getline(&line, &len, fp)) != -1) {
        sprintf(database[i++], "%s", line);
    }
    
    //get initial character location properties
    for(char j='a'; j<='z'; j++){
		  charInit.start[j-'a'] = i;
			while(database[i][0] == j) {
				i++;
			}
			charInit.end[j-'a'] = i;
			i++;
    }
    
    for(i=0; i<26; i++){
    	printf("Character: %c\nStart: %d\nEnd: %d\n\n", (char)(i+'a'), charInit.start[i], charInit.end[i]);
    }
    
    /*i = a.curStart;
    //for(int i = a.curStart; i<a.curEnd; i++){
    while(i < a.curEnd){
    	for(uint8_t j='a'; j<='z'; j++){
    		lchar next;
		  	next.curChar = char(j);
		  	next.curStart = i;
    		while(database[i][a.idx] == j) i++;
		  	next.curEnd = i;
		  	next.idx = a.idx+1;
		  	if(
    	}
    } */
    
    i=0;
    /*while(i<SIZE){
    	for(char j='a'; j<='z'; j++){
		  	printf("%c Start: %d\n", j, i);
		  	printf("%c\n\n", database[i][0]);
		  	while(database[i][0] == j) {
		  		i++;
		  	}
		  	printf("%c End: %d\n\n", j, i);
		  	i++;
    	}
    }*/
    lchar a;
    a.curChar = '.';
    a.curStart = 0;
    a.curEnd = SIZE;
    a.idx = 0;
    a.wordIdx = 0;
    
    
		
    fclose(fp);
    return 0;
}
