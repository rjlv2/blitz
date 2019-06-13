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

char gameGrid[ROW_SIZE*COL_SIZE];

char gridChar(int row, int col){
	if(row>=0 && row<=3 && col>=0 && col<=3)
		return gameGrid[COL_SIZE*row + col];
	else return 0;
}

int gridIdx(int row, int col){
	if(row>=0 && row<=3 && col>=0 && col<=3)
		return COL_SIZE*row + col + 1;
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
	
	//records the traversal
	int idx_record[ROW_SIZE*COL_SIZE+1];
	
	//records the index of all alphabets
	int start[ROW_SIZE*COL_SIZE]; //start and end records the index in the database of current characters
	int end[ROW_SIZE*COL_SIZE];
	
	int next_start[ALPHABET_SIZE];
	int next_end[ALPHABET_SIZE];
	
} lchar;

bool possible_move(lchar current, int next_row, int next_col){
	//within bounds
	if(abs(next_row-current.row)<=1 && abs(next_col-current.col)<=1 && (current.row!=next_row || current.col!=next_col)){
		if(current.used[next_row][next_col]){
			return false;
		}
		else return true; //and not yet traversed
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
					
					memcpy(next.idx_record, current.idx_record, (ROW_SIZE*COL_SIZE+1)*sizeof(int)); //TODO +1 necessary?
					next.idx_record[next.charIdx] = gridIdx(i, j);
					
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
			int rIdx = 0;
			while(1){
				printf("%d", current.idx_record[rIdx++]);
				if(current.idx_record[rIdx] != 0) printf("-");
				else break;
			}
			printf("\n");
			//printf("%s\t", current.str);
		}
	}
}


int main(int argc, char* argv[])
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
	
	
	i = 0;
	while(i<ROW_SIZE*COL_SIZE){
		if((c = fgetc(stdin)) != '\n') {
			gameGrid[i++] = c;
		}
	}
	
	//for all members of the grid, traverse
	for(int row = 0; row<ROW_SIZE; row++){
		for(int col=0; col<COL_SIZE; col++){
			a.row = row;
			a.col = col;
			memset(a.used, false, ROW_SIZE*COL_SIZE*sizeof(bool));
			memset(a.str, 0, (ROW_SIZE*COL_SIZE+1)*sizeof(char));
			a.charIdx = 0;
			a.str[a.charIdx] = gridChar(row, col);
			
			memset(a.idx_record, 0, (ROW_SIZE*COL_SIZE+1)*sizeof(int));
			a.idx_record[a.charIdx] = gridIdx(row, col);
			
			memset(a.start, 0, ROW_SIZE*COL_SIZE*sizeof(int));
			memset(a.end, 0, ROW_SIZE*COL_SIZE*sizeof(int));
			a.start[a.charIdx] = charInit.start[a.str[a.charIdx]-'a'];
			a.end[a.charIdx] = charInit.end[a.str[a.charIdx]-'a'];
			
			traverse(a);
		}
	}

	return 0;
}
