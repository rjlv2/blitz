#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 335270

#define COL_SIZE 4
#define ROW_SIZE 4

char database[SIZE][ROW_SIZE*COL_SIZE]; 

char gameGrid[ROW_SIZE*COL_SIZE] = {
	'a', 'b', 'c', 'd',
	'e', 'f', 'g', 'h',
	'i', 'j', 'k', 'l',
	'm', 'n', 'o', 'p'
};

char gridChar(int row, int col){
	if(row>=0 && row<=3 && col>=0 && col<=3)
		return gameGrid[COL_SIZE*row + col];
	else return 0;
}

struct {
	int start[26];
	int end[26];
} charInit;

typedef struct {
	int row;
	int col;
	bool used[ROW_SIZE][COL_SIZE];
	int charIdx;
	char str[ROW_SIZE*COL_SIZE+1];
	
	//records the index of all alphabets
	int start[ROW_SIZE*COL_SIZE];
	int end[ROW_SIZE*COL_SIZE];
	
	int next_start[26];
	int next_end[26];
	
} lchar;

bool possible_move(lchar current, int next_row, int next_col){
	if(abs(next_row-current.row)<=1 && abs(next_col-current.col)<=1 && (current.row!=next_row || current.col!=next_col)){
		if(current.used[next_row][next_col]){
			return false;
		}
		else return true;
	}
	else{
		return false;
	}
	return false;
}

void findNextIndex(lchar * target){
	
	int idx = target->charIdx;
	int next_idx = idx+1;
	int i = target->start[idx];
	
	for(char j='a'; j<='z'; j++){
		if(i<=target->end[idx] && database[i][next_idx]==j){
			target->next_start[j-'a'] = i;
			while(database[++i][next_idx] == j);
			target->next_end[j-'a'] = i-1;
		}
		else {
			target->next_start[j-'a'] = 0;
			target->next_end[j-'a'] = 0;
		}
	}
}

//check all possible moves
void traverse(lchar current)
{
	if(current.charIdx < ROW_SIZE*COL_SIZE-1){
		//printf("%d\n", current.charIdx);
		findNextIndex(&current);
	}
	for(int i=0; i<ROW_SIZE; i++){
		for(int j=0; j<COL_SIZE; j++){
			//printf("row: %d, col: %d\n", i, j);
			if(possible_move(current, i, j)){
				char char_n = gridChar(i, j);
				if(current.next_start[char_n-'a']!=current.next_end[char_n-'a']) {
				
					lchar next;
					next.row = i;
					next.col = j;
					//printf("approved\nrow: %d, col: %d\n", i, j);
					memcpy(next.used, current.used, ROW_SIZE*COL_SIZE*sizeof(bool));
					next.used[current.row][current.col] = true;
					memcpy(next.str, current.str, (ROW_SIZE*COL_SIZE+1)*sizeof(char));
					next.charIdx=current.charIdx + 1;
					next.str[next.charIdx] = char_n;
					
					memcpy(next.start, current.start, ROW_SIZE*COL_SIZE*sizeof(int));
					memcpy(next.end, current.end, ROW_SIZE*COL_SIZE*sizeof(int));
					next.start[next.charIdx] = current.next_start[char_n-'a'];
					next.end[next.charIdx] = current.next_end[char_n-'a'];
					//TODO next_start?
					traverse(next);
				}
			}
		}
	}
	int cStart = current.start[current.charIdx];
	int cEnd = current.end[current.charIdx];
	
	for(int cIdx = cStart; cIdx <= cEnd; cIdx++){
		if(!strcmp(current.str, database[cIdx])) {
			printf("%s %d\n", current.str, cIdx+1);
		}
	}
}




int main()
{
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("words7.txt", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	int i=0;
	while ((read = getline(&line, &len, fp)) != -1) {
		//printf("%ld\n", strlen(line));
		line[strlen(line)-1] = '\0';
		//printf("%ld\n\n", strlen(line));
		sprintf(database[i++], "%s", line);
	}


	i=0;
	//get initial character location properties
	for(char j='a'; j<='z'; j++){
		if(database[i][0]==j){
			charInit.start[j-'a'] = i;
			while(database[++i][0] == j);
			charInit.end[j-'a'] = i-1;
		}
		else {
			charInit.start[j-'a'] = 0;
			charInit.end[j-'a'] = 0;
		}
	}

	//used for debugging
	for(i=0; i<26; i++){
		printf("Character: %c\nStart: %d\nEnd: %d\n\n", (char)(i+'a'), charInit.start[i], charInit.end[i]);
	}

	fclose(fp);

	/*
	lchar a;
	a.row = 0;
	a.col = 0;
	memset(a.used, false, ROW_SIZE*COL_SIZE*sizeof(bool));
	memset(a.str, 0, (ROW_SIZE*COL_SIZE+1)*sizeof(char));
	a.charIdx = 0;
	a.str[a.charIdx] = gridChar(0, 0);
	memset(a.start, 0, ROW_SIZE*COL_SIZE*sizeof(int));
	memset(a.end, 0, ROW_SIZE*COL_SIZE*sizeof(int));
	a.start[a.charIdx] = charInit.start[a.str[a.charIdx]-'a'];
	a.end[a.charIdx] = charInit.end[a.str[a.charIdx]-'a'];

	traverse(a);
	*/
	
	lchar a;
	
	//for all members of the grid, traverse
	for(int row = 0; row<ROW_SIZE; row++){
		for(int col=0; col<COL_SIZE; col++){
			a.row = row;
			a.col = col;
			memset(a.used, false, ROW_SIZE*COL_SIZE*sizeof(bool));
			memset(a.str, 0, (ROW_SIZE*COL_SIZE+1)*sizeof(char));
			a.charIdx = 0;
			a.str[a.charIdx] = gridChar(row, col);
			memset(a.start, 0, ROW_SIZE*COL_SIZE*sizeof(int));
			memset(a.end, 0, ROW_SIZE*COL_SIZE*sizeof(int));
			a.start[a.charIdx] = charInit.start[a.str[a.charIdx]-'a'];
			a.end[a.charIdx] = charInit.end[a.str[a.charIdx]-'a'];
			
			traverse(a);
		}
	}








	return 0;
}
