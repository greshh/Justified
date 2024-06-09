#include <iostream>
#include <string>
using namespace std;

void display();

string input;
int i, width, characters, words, extra, temp;
int space[40];

int main() {
  cout << "Enter a line of text: ";
  getline(cin, input);
  width = input.length();
  while (width > 40) {
    cout << "ERROR: Input must not be greater than 40 characters: ";
    getline(cin, input);
    width = input.length();
  } // for error message
  characters = 0;
  words = 1;
  for (i = 0; i < width; i++) {
    if (input[i] != ' ') {
      characters++;
    } else if (input[i] == ' ') {
      words++;
    }
  } // counting characters and words
  temp = (40 - characters) / (words - 1);
  extra = 40 - characters - (temp * (words - 1));
  for (i = 0; i < (words - 1); i++) {
    space[i] = temp;
  } // initialising the spaces
  for (i = 0; i < (words - 1); i++) {
    if (extra > 0) {
      space[i] = space[i] + 1;
      extra--;
    }
  } // adding the remainder to each space
  display();
}

void display() {
  int j, k; // i, j, k = indexes for different arrays/strings
  string output;
  i = 0;
  k = 0;
  cout << endl << "1234567890123456789012345678901234567890" << endl;
  if (input[i] != ' ') {
    output = input[i];
  } else if (input[i] == ' ') {
    for (j = 0; j < space[k]; j++) {
      output = ' ';
    }
    k++;
  }
  for (i = 1; i < width; i++) {
    if (input[i] != ' ') {
      output = output + input[i];
    } else if (input[i] == ' ') {
      for (j = 0; j < space[k]; j++) {
        output = output + ' ';
      }
      k++;
    }
  }
  cout << output << endl << endl;
}
