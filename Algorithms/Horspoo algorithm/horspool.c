#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 256

int TABLE[MAX_SIZE];

void create_shift_table(char pattern[]){
    int length = strlen(pattern);
    // Filling all shift value as length of pattern
    for(int i = 0 ; i < MAX_SIZE ; i++){
        TABLE[i] = length;
    }
    // Shift values of characters in the pattern
    for(int i = 0 ; i < length - 1 ; i++){
        TABLE[pattern[i]] = length - i - 1;     // Here pattern[i] will change to ASCII value
    }
}

int horspool(char pattern[], char text[]){
    int pattern_length = strlen(pattern);
    int text_length = strlen(text);
    create_shift_table(pattern);
    int index_to_compare = pattern_length - 1;
    while(index_to_compare < text_length){
        int k = 0;
        // Loop goes until there is a mismatch
        while(k < pattern_length && (pattern[pattern_length-k-1] == text[index_to_compare - k])){
            k++;
        }
        // If found then k becomes equal to the length of pattern
        if(k == pattern_length){
            return index_to_compare - k + 1;
        }
        // Not found then shift
        else{
            index_to_compare += TABLE[text[index_to_compare]];
        }
    }
    return -1;

}

int main(){
    char text[MAX_SIZE];
	char pattern[MAX_SIZE];
	int found;
	printf("Enter the source string : ");
	gets(text);
	printf("Enter the pattern string : ");
	gets(pattern);
	found = horspool(pattern,text);
	if(found==-1)
		puts("\nMatching Substring not found.\n");
	else
		printf("\nMatching Substring found at position: %d\n",found+1);
	return 0;
}