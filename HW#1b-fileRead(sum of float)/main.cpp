#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
FILE* fp;
char fileName[1024];
char aLine[1024];
double number = 0;
double count = 0;
int i = 0;
double sum = 0;
bool have_number = false;
bool is_float = false;

//printf("Enter the file name: ");
scanf("%s", fileName);
fp = fopen(fileName, "r");

while(fgets(aLine, sizeof(aLine)/sizeof(char) ,fp) != NULL) {
        
      for(i=0;i< (sizeof(aLine)/sizeof(char));i++) {
        
         if(aLine[i] == '\0') {    //NULL 값 까지만 읽기
              break;
              
          } else if(aLine[i]>='0' && aLine[i]<='9') { //숫자이면 읽기 
              have_number = true;
              number = number * 10 + (aLine[i] - '0');  //숫자를 이어서 저장 (한 값으로)
              if(is_float) 
                count++;
              
          } else if(have_number) { //읽은 값이 숫자가 아니고 숫자 더하는 중일때(have_number true) = 숫자의 끝
              have_number = false;
          
           if(aLine[i] == '.'){   //. 뒤에 숫자 값이 나올시 (float 일때)
              is_float = true;
              count=0.0;
              continue;
            }
          
            if(count>=1.0) {      //'.' 뒤에 나온 수 만큼 값 계산
              number = number / pow(10.0,count);
              count = 0.0;
              is_float = false;
            }
              sum = sum + number;
              number = 0;
        }

}
}
printf("The sum is %.1f", sum);
return 0;
}

