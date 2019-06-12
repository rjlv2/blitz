#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define SIZE 405384

#define COL_SIZE 4
#define ROW_SIZE 4
#define ALPHABET_SIZE 26

char database[SIZE][ROW_SIZE*COL_SIZE]; 

char gameGrid[ROW_SIZE*COL_SIZE];/* = {
	't','o','a','n',
	'i','e','a','s',
	'm','i','e','t',
	't','i','i','a'
};*/

char gridChar(int row, int col){
	if(row>=0 && row<=3 && col>=0 && col<=3)
		return gameGrid[COL_SIZE*row + col];
	else return 0;
}

struct {
	int start[ALPHABET_SIZE];
	int end[ALPHABET_SIZE];
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
	
	int next_start[ALPHABET_SIZE];
	int next_end[ALPHABET_SIZE];
	
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
		while(database[i][next_idx]==0) i++;
		if(i<=target->end[idx] && database[i][next_idx]==j){
			target->next_start[j-'a'] = i;
			while(database[++i][next_idx] == j);
			target->next_end[j-'a'] = i-1;
		}
		else {
			target->next_start[j-'a'] = -1;
			target->next_end[j-'a'] = -1;
		}
	}
}

//check all possible moves
void traverse(lchar current)
{
	if(current.charIdx < ROW_SIZE*COL_SIZE-1){
		findNextIndex(&current);
	}
	for(int i=0; i<ROW_SIZE; i++){
		for(int j=0; j<COL_SIZE; j++){
			if(possible_move(current, i, j)){
				char char_n = gridChar(i, j);
				if(current.next_start[char_n-'a']!=-1 && current.next_end[char_n-'a']!=-1) {
				
					lchar next;
					next.row = i;
					next.col = j;
					memcpy(next.used, current.used, ROW_SIZE*COL_SIZE*sizeof(bool));
					next.used[current.row][current.col] = true;
					memcpy(next.str, current.str, (ROW_SIZE*COL_SIZE+1)*sizeof(char));
					next.charIdx=current.charIdx + 1;
					next.str[next.charIdx] = char_n;
					
					memcpy(next.start, current.start, ROW_SIZE*COL_SIZE*sizeof(int));
					memcpy(next.end, current.end, ROW_SIZE*COL_SIZE*sizeof(int));
					next.start[next.charIdx] = current.next_start[char_n-'a'];
					next.end[next.charIdx] = current.next_end[char_n-'a'];
					traverse(next);
				}
			}
		}
	}
	int cStart = current.start[current.charIdx];
	int cEnd = current.end[current.charIdx];
	
	for(int cIdx = cStart; cIdx <= cEnd; cIdx++){
		if(!strcmp(current.str, database[cIdx])) {
			printf("%s\t", current.str);
		}
	}
}


int main()
{
	FILE * fp;
	char line[20];
	//size_t len = 0;

	fp = fopen("data.txt", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	int i=0;
	while (fgets(line, 20, fp)) {
		line[strlen(line)-1] = '\0';
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

	fclose(fp);
	
	lchar a;
	
	/*int row = 0;
	int col = 0;
	
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
	
	traverse(a);*/
	
	char c;
	
	
	while(1){
		
		/*for(i=0; i<ROW_SIZE*COL_SIZE; i++){
			c = fgetc(stdin);
			gameGrid[i] = c;
			printf("%d ", i);
		}*/
		i = 0;
		printf("\nInput: ");
		while(i<ROW_SIZE*COL_SIZE){
			if((c = fgetc(stdin)) != '\n') {
				//printf("%d ", i);
				gameGrid[i++] = c;
			}
		}
		
		while(fgetc(stdin) != '\n'); // captures until the newline character
		printf("\n*********************************\n**********List of Words**********\n*********************************\n");
		
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
	}

	return 0;
}
