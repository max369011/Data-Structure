#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#define MAX 2048
using namespace std;

typedef struct {
    int count = 1;
    string data;
} word;

void quicksort(word list[], int left, int right);
void bubblesort(word list[], int n);
void swap(word* list1, word* list2);
void printArray(word list[], int count);


int main() {
    ifstream ifs;
    string fileName, newWord;
    word wordArray[MAX];
    char* ptr;
    char line[MAX];
    int count = 0;
    bool found = false;

    cin >> fileName;
    ifs.open(fileName);

    if (ifs.is_open()) 
    {
        while (ifs.getline(line, MAX)) 
        {
            ptr = strtok(line, " ");
            while (ptr != NULL) {
                string newLine = ptr;
                
                //store word into string newWord
                for (int i = 0; i < newLine.length(); i++) {
                    if (toupper(newLine.at(i)) >= 'A' && toupper(newLine.at(i)) <= 'Z') {
                        newWord += toupper(newLine.at(i));
                    }
                }
                
                found = false;
                //if array is empty store word
                if (count == 0) {
                    wordArray[0].data = newWord;
                    count++;
                } else if (count > 0) {
                    for (int n = 0; n < count; n++) {
                        //if word found in array raise the count of word
                        if (wordArray[n].data == newWord) {
                            wordArray[n].count++;
                            break;
                        }
                    }
                    //if word not found raise the overall count
                    if(!found) {
                      wordArray[count].data = newWord;
                      count++;
                    }
                }
                newWord.clear();
                ptr = strtok(NULL, " ");
            }
        }
    } else {
        cout << "Could not open";
        exit(1);
    }
    
    //sort the array by frequency
    quicksort(wordArray, 0, count - 1);
    //sort the array by alphabetical order if same frequency
    bubblesort(wordArray, count);
    
    printArray(wordArray, count);
    
    ifs.close();
}


void quicksort(word list[], int left, int right) {
    int pivot;
    int i, j;

    if (left < right) {
        i = left;
        j = right + 1;
        pivot = list[left].count;

        do
        {
            do i++; while (i < right && list[i].count > pivot);
            do j--; while (j > left&& list[j].count < pivot);

            if (i < j) {
                swap(&list[i], &list[j]);
            }

        } while (i < j);
        swap(&list[left], &list[j]);

        quicksort(list, left, j - 1);
        quicksort(list, j + 1, right);
    }
}


void bubblesort(word list[], int n) {
    int i, j;

    for (i = n - 1; i > 0; i--) {
        //repeat from 0~(i-1)
        for (j = 0; j < i; j++) {
          //swap if j data is greater and count is smaller
            if ((list[j].data > list[j + 1].data) && (list[j].count <= list[j + 1].count)) {
                swap(&list[j], &list[j + 1]);
            }
        }
    }
}


void swap(word* list1, word* list2) {
    word listTemp = *list1;
    *list1 = *list2;
    *list2 = listTemp;
}


void printArray(word list[], int count) {
  for (int i = 0; i < 5 ; i++) {
        cout << list[i].data << ": " << list[i].count << endl;
    }
}