#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float **add_matrix(float** a, int ah, int aw, float** b, int bh, int bw);
float **fill2dArray(FILE* fp, float** a, float row, float col);
float **mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw);
float **transpose_matrix(float** a, int ah, int aw);
void freeArray(float** a, int row);

int main() {
  FILE * fp1 = NULL;
  FILE * fp2 = NULL;
  
  float **newMatrix = NULL;
  char aline[5];
  char fileName[2][20];
  char ops = '\0';
  int i = 0;
  float row1, col1, row2, col2;
  //printf("What operation do you want? (\'a\', \'m\', \'t\')\n");
  scanf("%c", &ops);
  
  if(ops != 'a' && ops != 'm' && ops != 't'){
    fprintf(stderr, "Invalid operation.\n");
    return -1;
  } 
  
  //if transpose matrix 
  if(ops == 't') {
    scanf("%s", fileName[0]);
    fp1 = fopen(fileName[0], "r");
    
    if(fp1 == NULL) { 
    fprintf(stderr, "Invalid file name. File open Error!\n");
    return -1;
 }
 
  fscanf (fp1, "%f %f", &row1, &col1);    
  
  float **matrix1 = NULL;
    matrix1 =(float**)malloc(row1*sizeof(*matrix1));
    for(int h=0; h<row1; h++)
      matrix1[h] = (float*)malloc(col1*sizeof(**matrix1));

  matrix1 = fill2dArray(fp1,matrix1,row1,col1);
  newMatrix = transpose_matrix(matrix1, row1, col1);
  freeArray(matrix1, row1);
  freeArray(newMatrix, col1);
  return 0;
  }
  
  //if addition or multiplication matrix
  //printf("Input files names:\n");
  
    for(i =0; i<2; i++) {
       scanf("%s", fileName[i]);
    }
    
  //read file and create pointer for file
  fp1 = fopen(fileName[0], "r");
  fp2 = fopen(fileName[1], "r");

  if(fp1 == NULL || fp2 == NULL){
    fprintf(stderr, "Invalid file name. File open Error!\n");
    return 0;
 }


//read first line of file and create 2D array accordingly 

    fscanf (fp1, "%f %f", &row1, &col1);    
    //printf("%f %f\n", row1,col1);
    
    fscanf (fp2, "%f %f", &row2, &col2);
    //printf("%f %f\n", row2,col2);
 
  float **matrix1 = NULL;
    matrix1 =(float**)malloc(row1*sizeof(*matrix1));
    for(int h=0; h<row1; h++)
      matrix1[h] = (float*)malloc(col1*sizeof(**matrix1));
      
  float **matrix2 = NULL;
    matrix2 =(float**)malloc(row2*sizeof(*matrix2));
    for(int h=0; h<row2; h++)
      matrix2[h] = (float*)malloc(col2*sizeof(**matrix2));
      

  matrix1 = fill2dArray(fp1,matrix1,row1,col1);
  //printf("\n");
  matrix2 = fill2dArray(fp2,matrix2,row2,col2);
  
  
  switch(ops) {
    case 'a': //if add matrix
      if(row1 == row2 && col1 == col2) {
        newMatrix = add_matrix(matrix1, row1, col1, matrix2, row2, col2); 
        freeArray(newMatrix, row1);  //deallocate newMatrix
      } else 
        printf("Matrix dimension mismatch");
      break;
  
    case 'm': //if mul matrix
      if(col1 == row2) {
        newMatrix = mul_matrix(matrix1, row1, col1, matrix2, row2, col2);
        freeArray(newMatrix, row1);  //deallocate newMatrix
      } else 
        printf("Matrix dimension mismatch");
      break;
  }
  
 //deallocate memory space of matrices
 freeArray(matrix1, row1);
 freeArray(matrix2, row2);
 return 0;
}



void freeArray(float** a, int row) {
  for(int i =0; i<row; i++) 
    free(a[i]);
  
  free(a);
  
  return;
}


float** fill2dArray(FILE* fp, float** a, float row, float col) {
    float num =0.0;
  
    for(int i =0; i< row ; i++) {
    for(int j =0; j<col; j++) {
    fscanf(fp, "%f", &num );
    a[i][j] = num;
    //printf("%0.1f ", a[i][j]);
  }
  //printf("\n");
  }  
  return a;
}


float **add_matrix(float** a, int ah, int aw, float** b, int bh, int bw) {

  float **p= NULL;
  
  p =(float**)malloc(ah*sizeof(*p));
    for(int k=0; k<ah; k++)
      p[k] = (float*)malloc(aw*sizeof(**p));
  
  printf("The output is:");
  printf("\n%d %d\n", ah, aw);
  
  for(int i =0; i<ah; i++) {
    for(int j=0; j<aw; j++) {
      p[i][j] = a[i][j] + b[i][j]; 
      
      if(j == aw-1)
        printf("%0.1f", p[i][j]);
      else 
        printf("%0.1f ", p[i][j]);
    }
    printf("\n");
  }
 
  return p;
}


float **mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw) {
  
  float **p= NULL;
  float sum = 0;
  
  p =(float**)malloc(ah*sizeof(*p));
    for(int k=0; k<ah; k++)
      p[k] = (float*)malloc(bw*sizeof(**p));
  
  printf("The output is:");
  printf("\n%d %d\n", ah, bw);
  
  for(int i =0; i<ah; i++) {
    for(int j =0; j<bw; j++) {
      for(int k =0; k<bh; k++) {
        sum += a[i][k]*b[k][j];
      }
      p[i][j] = sum;
      if(j == bw-1)
        printf("%0.1f", p[i][j]);
      else 
        printf("%0.1f ", p[i][j]);
      sum = 0;
    }
    printf("\n");
  }
    return p;
}


float **transpose_matrix(float** a, int ah, int aw) {
  float** p = NULL;
  
  p = (float**) malloc(aw*sizeof(*p));
  for(int k =0; k<aw ; k++)
    p[k] = (float*) malloc(ah*sizeof(**p));
  printf("The output is:");
  printf("\n%d %d\n", aw, ah);
    
  for(int i =0; i<ah; i++) {
    for(int j=0; j<aw; j++) {
      p[j][i] = a[i][j];
    }
  }
    
  for(int i=0; i<aw; i++) {
    for(int j=0; j<ah; j++) {
      if(j == ah-1)
        printf("%0.1f", p[i][j]);
      else 
        printf("%0.1f ", p[i][j]);
    }
    printf("\n");
  }
  return p;
}