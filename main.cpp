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

int main() {
  bool running = true;
  char command[10];
  char input[1000];
  
  cout << "Welcome to Heap" << endl;
  while (running == true) {
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
	cout << input << endl;
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
