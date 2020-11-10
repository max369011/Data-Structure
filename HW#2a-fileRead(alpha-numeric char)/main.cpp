#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024
void printFunction(int x, int y);

int main(){
  FILE *fp;
  char file_name[MAX_LEN];
  char line[MAX_LEN];
  int savedASCII[MAX_LEN];
  int lineCount = 0;
  int count;
  //printf("Input file name: ");
  scanf("%s", file_name);
  
  fp = fopen(file_name, "r");
  if(fp == NULL){
    fprintf(stderr, "ERROR: file open has failed.");
    return -1;
  }
  
  while(fgets(line, MAX_LEN, fp)){
    
    for(int i=0; i<MAX_LEN;i++) {
      
    if(line[i] == '\0')
    break;
    
    savedASCII[lineCount] = line[i];  //save ASCII number into savedASCII[] array
    lineCount++;
    }
}
 
  //find ASCII number of (A~Z, a~z) in savedASCII[] then print the count
    for(int loopNum = 65; loopNum<=90; loopNum++) {
      count =0;
      for(int lineLoop = 0; lineLoop<MAX_LEN; lineLoop++) {
        if(savedASCII[lineLoop] == '\0') break;
              else if(savedASCII[lineLoop] == loopNum || savedASCII[lineLoop] == (loopNum + 32)) {
                count++;
              }
      }
      printf("%c: %d\n", (char) loopNum, count);
  }
  
  
  //find ASCII number of (0~9) in savedASCII[] then print the count 
    for(int loopNum = 48; loopNum<=57; loopNum++) {
      count =0;
      for(int lineLoop = 0; lineLoop<MAX_LEN; lineLoop++) {
        if(savedASCII[lineLoop] == '\0') break;
              else if(savedASCII[lineLoop] == loopNum) {
                count++;
              }
      }
      printf("%c: %d\n", (char) loopNum, count);
  } 
  
  fclose(fp);
  return 0;
}