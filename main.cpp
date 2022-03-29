/*
https://en.wikipedia.org/wiki/Heap_(data_structure)
https://en.wikipedia.org/wiki/Binary_tree
https://www.geeksforgeeks.org/heap-using-stl-c
https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation
https://www.geeksforgeeks.org/array-representation-of-binary-heap

*/
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void PARSE(char* in, int* modify, int &count);
void DELETE();
void PRINT();
int maxHeap(int* array);
void HEAP(int* modify, int* heap, int size);


int main() {
  bool running = true;
  char command[10];
  char input[10000];
  int modify[100];
  for (int i = 0; i < 100; i++) {
    modify[i] = 0;
  }
  int count = 0;
  
  cout << "Welcome to Heap" << endl;
  while (running == true) {
    for (int i = 0; i < 100; i++) {
      modify[i] = 0;
    }
    count = 0;
    cout << endl << "Options: RUN and QUIT" << endl;
    cin.get(command, 10);
    cin.clear();
    cin.ignore(10000, '\n');
    if (strcmp(command, "RUN") == 0 || strcmp(command, "Run") == 0) { //Run command
      cout << "File input or Manual input? ";
      cin.get(command, 10);
      cin.clear();
      cin.ignore(10000, '\n');
      if (strcmp(command, "FILE") == 0 || strcmp(command, "File") == 0) { //File command, for file input use
	cout << "File" << endl;
      }
      else if (strcmp(command, "MANUAL") == 0 || strcmp(command, "Manual") == 0) { //Manual command, for user manual input
	cout << "Enter each number followed by a space:" << endl;
	char in[100000];
	cin.get(in, 100000);
	cin.clear();
	cin.ignore(1000000, '\n');
	//parse input by spaces
	PARSE(in, modify, count);  //parse input to modif array
	cout << "Input: ";
	for (int i = 0; i < 100; i++) {
	  if (modify[i] == 0) break;
	  cout << modify[i] << " ";
	}
	cout << endl;      
      }
      else {
	cout << "Invalid input, restart." << endl;
      }
      int heap[101];
      for (int z = 0; z < 101; z++) {
	heap[z] = 0;
      }
      int size = 0;
      for (int i = 0; i < 100; i++) {
	if (modify[i] != 0) {
	  size++;
	} else break;
      }
      HEAP(modify, heap, size);
      cout << "HEAP: " << endl;
      for (int i = 1; i < 101; i++) {
	if (heap[i] == 0) break;
	cout << heap[i] << " ";
      }

      
    }
    else if (strcmp(command, "QUIT") == 0 || strcmp(command, "Quit") == 0) { //Quit command
      cout << endl << "Quitting Program." << endl << endl;
      running = false;
    }
    else { //Invalid inputs
      cout << endl << "Invalid input, try again" << endl;
    }
  }
}

void PARSE(char* in, int* modify, int &count) {
  int x = 0; //keeps track of number of chars before space
  for (int i = 0; i < strlen(in); i++) {
    if (in[i] == ' ') {
      if (x == 1) {
	int temp = 0;
	temp = in[i-1] - '0';
	modify[count] = temp;
	count++;
	x = 0;
      } else {
	int temp = 0;
	for (int a = 0; a < x; a++) {
	  temp = 10 * temp + (in[i-x+a] - '0');
	}
	modify[count] = temp;
	count++;
	x = 0;
      }
    } else {
      int temp = 0;
      x++;
      if (i == strlen(in) - 1) { //last possible pair of chars
	for (int a = 0; a < x; a++) {
	  temp = 10 * temp + (in[i+a+1-x] - '0');
	}
	modify[count] = temp;
	count++;
      }
    }
  }
}

void HEAP(int* modify, int* heap, int size) {
  int current = 1;
  heap[1] = modify[maxHeap(modify)];
  modify[maxHeap(modify)] = 0;
  while (current <= size) {
    if (heap[2*current] == 0) {
      heap[2*current] = modify[maxHeap(modify)];
      modify[maxHeap(modify)] = 0;
      heap[2*current+1] = modify[maxHeap(modify)];
      modify[maxHeap(modify)] = 0;
    }
    else {
      heap[2*current+1] = modify[maxHeap(modify)];
      modify[maxHeap(modify)] = 0;
    }
    current++;
  }
}

int maxHeap(int* array) {
  int i;
  for (int x = 0; x < 100; x++) {
    if (array[x] >= array[i]) {
      i = x;
    }
  }
  return i;
}
