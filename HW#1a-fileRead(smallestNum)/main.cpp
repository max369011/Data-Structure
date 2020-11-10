#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
   char aFilename[1024];
   char aLine[1024];
   int aInt[1024]; 
   
   FILE* fp; 
   int i = 0;
   int iNum = 0;
   
   printf("Input filename: ");
   scanf("%s", aFilename);
   
   fp = fopen(aFilename, "r");
   
   while(fgets(aLine, 1024, fp)){
     
     if((aLine[0]>=48) && (aLine[0]<=57)) {
        i++;
     aInt[i-1]= atoi(aLine);    // convert aLine to integer and put it in aInt
     }
     
   }
   
   iNum = i-1; 
   int smallest = aInt[0];
   
   // Now you have the numbers in aInt and the length of it is iNum. 
   // find the smallest number. 
   
  for(int j =1; j<=iNum ; j++) {
    if(aInt[j]<smallest) 
      smallest = aInt[j];
    } 
  
   printf("\nThe smallest number is %d", smallest);
   
   return 0;
}