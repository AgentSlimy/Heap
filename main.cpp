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

int main() {
  bool running = true;
  char command[10];
  char input[1000];
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
    if (strcmp(command, "RUN") == 0 || strcmp(command, "Run") == 0) {
      cout << "File input or Manual input? ";
      cin.get(command, 10);
      cin.clear();
      cin.ignore(10000, '\n');
      if (strcmp(command, "FILE") == 0 || strcmp(command, "File") == 0) {
	cout << "File" << endl;
      }
      else if (strcmp(command, "MANUAL") == 0 || strcmp(command, "Manual") == 0) {
	cout << "Enter each number followed by a space:" << endl;
	cin.get(input, 1000);
	cin.clear();
	cin.ignore(10000, '\n');
	PARSE(input, modify, count);
	cout << "Input: ";
	for (int i = 0; i < 100; i++) {
	  if (modify[i] == 0) break;
	  cout << modify[i] << " ";
	}
	cout << endl;
      }
      else {
	cout << "Invalid command, restart." << endl;
      }
    }
    else if (strcmp(command, "QUIT") == 0 || strcmp(command, "Quit") == 0) {
      cout << endl << "Quitting Program." << endl << endl;
      running = false;
    }
    else {
      cout << endl << "Invalid input, try again" << endl;
    }
  }
}

void PARSE(char* in, int* modify, int &count) {
  int x = 0;
  for (int i = 0; i < strlen(in); i++) {
    if (in[i] = ' ') {
      if (x == 1) {
	int temp = 0;
	temp = in[x - 1] - '0';
	modify[count] = temp;
	count++;
	x = 0;
      }
      else {
	int temp = 0;
	for (int y = 0; y < 1; y++) {
	  temp = 10 * temp + (in[i - x + y] - '0');
	}
	modify[count] = temp;
	count++;
	x = 0;
      }
    }
    else {
      int temp = 0;
      x++;
      if (x == strlen(in) - 1) {
	for (int z = 0; z < 1; z++) {
	  temp = 10 * temp + (in[i + z + 1 - x] - '0');
	}
	modify[count] = temp;
	count ++;
      }
    }
  }
}
