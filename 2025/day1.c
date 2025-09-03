#include <stdlib.h>
#include <stdio.h>


void sort(int array[], int size){
		int temp;
		for(int i=0; i<size-1; i++){
				for(int j=0; j<size-i-1; j++){
						if (array[j]>array[j+1]){
								temp = array[j];
								array[j] = array[j+1];
								array[j+1] = temp;
						}
				}
		}
}

int count_file_lines(FILE *input_ptr){
		int line_count =0;
		int a, b;
		while(fscanf(input_ptr, "%d %d", &a, &b)==2) line_count++;
		return line_count;
}

int main(){
		FILE *input = fopen("inputs/day1_input.txt", "r");
		if (input==NULL){
				perror("File could not be loaded\n");
				exit(0);
		}
		//first pass for readingwa
		int lines_count = count_file_lines(input);
		printf("lines: %d\n", lines_count);
		int *list_left = malloc(lines_count*sizeof(int));
		int *list_right = malloc(lines_count*sizeof(int));
		if (!list_left || !list_right){
				perror("Could not allocate memory for lists\n");
				exit(0);
		}
		//second pass for reading and assinging the valueswa
		rewind(input);
		for(int i=0; i<lines_count; i++){
				fscanf(input, "%d %d", &list_left[i], &list_right[i]);
		}
		sort(list_left, lines_count);
		sort(list_right, lines_count);
		int difference = 0;
		for (int i=0; i<lines_count; i++){
				difference = difference + abs(list_left[i]-list_right[i]);
		}
		printf("%d\n", difference);
}
