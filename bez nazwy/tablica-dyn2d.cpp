#include <iostream>
#include <iomanip>

using namespace std;

void fill(int**, int, int);
void print(int**, int, int);

int main(){
 int **board, rows, columns;
 cout << "Enter the number of rows and columns: ";
 cin >> rows >> columns;
 cout << endl;

 board = new int* [rows]; //create rows of board
 for(int row = 0; row < rows; row++)
  board[row] = new int[columns]; //create columns of board

 fill(board, rows, columns); //input elements into board
 cout << endl;

 print(board, rows, columns); //input elements into board
 cout << endl;

 for(int i=0; i<rows; i++)
     delete [] board[i];
 delete [] board;

 system("");
return 0;
}

void fill(int **p, int r, int c){
 for (int row = 0; row < r; row++){
  cout << "Enter " << c << " numbers for row number " << row << " : ";
  for(int col = 0; col < c; col++)
   cin >> p[row][col];
  cout << endl;
 }
}

void print(int **p, int r, int c){
 for(int row = 0; row < r; row++){
  for(int col = 0; col < c; col++)
   cout << setw(5) << p[row][col];
  cout << endl;
 }
}
