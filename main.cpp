/*
https://en.wikipedia.org/wiki/Heap_(data_structure)
https://en.wikipedia.org/wiki/Binary_tree
 */
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  bool running = true;
  char command[10];
  
  cout << "Welcome to Heap" << endl << endl;
  while (running == true) {
    cout << "Options: RUN and QUIT" << end;
    cin.get(command, 10);
    cin.clear();
    cin.ignore(10000, '\n');
    if (strcmp(command, "RUN") == 0 || strcmp(command, "Run") == 0) {
      cout << "Run" << endl;
    }
    else if (strcmp(command, "QUIT") == 0 || strcmp(command, "Quit") == 0) {
      cout << "Quitting Program." << endl << endl;
      running = false;
    }
    else {
      cout << endl << "Invalid input, try again" << endl;
    }
  }
}
