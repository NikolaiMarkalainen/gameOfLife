#include <iostream>
#include <vector>
#include  <bits/stdc++.h>
#include <fstream>

using namespace std;


class Life {

public:
   void initialize();
   void print();
   void update();
   void readFile();
   int maxrow,maxcol;
   Life(){
       maxrow = 20;
       maxcol = 60;
       grid.resize(maxrow+2, vector<int>(maxcol+2));
   }
private:
    vector<vector<int>> grid;  //  allows for two extra rows and columns
   int neighbor_count(int row, int col);
};

int Life::neighbor_count(int row, int col)
{
    int i, j;
    int count = 0;
    int row_start = max(row - 1, 1);
    int row_end = min(row + 1, maxrow);
    int col_start = max(col - 1, 1);
    int col_end = min(col + 1, maxcol);
    for (i = row_start; i <= row_end; i++)
        for (j = col_start; j <= col_end; j++)
            count += grid[i][j];  //  Increase the count if neighbor is alive.
    count -= grid[row][col]; //  Reduce count, since cell is not its own neighbor.
    return count;
}


void Life::update()
{
   int row, col;
   int new_grid[maxrow + 2][maxcol + 2];

   for (row = 1; row <= maxrow; row++)
      for (col = 1; col <= maxcol; col++)
         switch (neighbor_count(row, col)) {
         case 2:
            new_grid[row][col] = grid[row][col];  //  Status stays the same.
            break;
         case 3:
            new_grid[row][col] = 1;                //  Cell is now alive.
            break;
         default:
            new_grid[row][col] = 0;                //  Cell is now dead.
         }

   for (row = 1; row <= maxrow; row++)
      for (col = 1; col <= maxcol; col++)
         grid[row][col] = new_grid[row][col];
}


void instructions(int maxrow, int maxcol)
{
   cout << "Welcome to Conway's game of Life." << endl;
   cout << "This game uses a grid of size "
        << maxrow << " by " << maxcol << " in which" << endl;
   cout << "each cell can either be occupied by an organism or not." << endl;
   cout << "The occupied cells change from generation to generation" << endl;
   cout << "according to the number of neighboring cells which are alive."
        << endl;
}


void Life::initialize()
{
   int row, col;
   string userInput;
   int inputLength, rowCount = -1;
   cout << "What size of grid do you wish to have x by x" << endl;
   cin >> maxrow >> maxcol;
   grid.resize(maxrow+2, vector<int>(maxcol+2));
   instructions(maxrow, maxcol);
   for (row = 0; row <= maxrow+1; row++)
      for (col = 0; col <= maxcol+1; col++)
         grid[row][col] = 0;
   cout << "how many columns do you wish to add" << endl;
   cin >> inputLength;
   cout << "Enter the living cells with '*' and space as dead cells" << endl;
   while(rowCount < inputLength) {
       getline(cin, userInput);
       if (userInput.length() > maxcol) {
           cout << "Column length is too long" << endl;
       } else {
           rowCount +=1;
           for (int i = 0; i <= userInput.length(); i++) {
               if (userInput[i] == '*') {
                   grid[rowCount][i] = 1;
               }
           }
       }
   }

}


void Life::print()
{
   int row, col;
   cout << "\nThe current Life configuration is:" <<endl;
   for (row = 1; row <= maxrow; row++) {
      for (col = 1; col <= maxcol; col++)
         if (grid[row][col] == 1) cout << '*';
         else cout << ' ';
      cout << endl;
   }
   cout << endl;
}


bool user_says_yes()
{
   int c;
   bool initial_response = true;

   do {  //  Loop until an appropriate input is received.
      if (initial_response)
         cout << " (y,n)? " << flush;

      else
         cout << "Respond with either y or n: " << flush;

      do { //  Ignore white space.
         c = cin.get();
      } while (c == '\n' || c ==' ' || c == '\t');
      initial_response = false;
   } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
   return (c == 'y' || c == 'Y');
}

void Life::readFile() {
    int row, col;
    string lines;
    int rowCounter;
    string fileName;
    cout << "Enter grid size of the file" << endl;
    cin >> maxrow >> maxcol;
    grid.resize(maxrow+2, vector<int>(maxcol+2));
    for (row = 0; row <= maxrow+1; row++)
        for (col = 0; col <= maxcol+1; col++)
            grid[row][col] = 0;
    cout << "Enter text file name" << endl;
    cin >> fileName;
    ifstream confFile (fileName);


    if( confFile.is_open() ) {
        while ( confFile >> ws && getline(confFile, lines) ){
            cout << lines << endl;
            rowCounter +=1;
            for(int i = 0; i <= lines.length(); i++){
                if(lines[i] == '*'){
                    grid[rowCounter][i] = 1;
                }
            }
            confFile >> lines;
        }
    }
    cout << "Continue with this text file ? " << endl;
}

int main () {
    Life configuration;
    string answer;
    cout << "Do you have initial file configuration" << endl;
    getline(cin, answer);
    if(answer == "y" || answer == "Y"){
        configuration.readFile();
    }
    else if(answer == "n" || answer == "N"){
        configuration.initialize();
        configuration.print();
        }
    else{
        cout << "Wrong input ( y / n )";
    }
    while(user_says_yes()){
    configuration.update();
    configuration.print();
    cout << "Continue viewing new generations?" << endl;
    }
}

