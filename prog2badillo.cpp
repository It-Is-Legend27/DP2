/*****************************************************************************
* Name: Angel Badillo
*
* Course: CMPS-2433-101, Fall 2021, Springfellow
*
* Purpose: This program finds the numbers of squares in a grid of N * N,
*          (sum of n^2), for 1 <= n <= 100. Program prompts user for i/o
*          file names, solves the sum of n^2 for each number in the input 
*          file, then prints the solution to the output file.
*
*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int MIN = 1;
const int MAX = 100;

// Purpose:  Prompts user for names of input & output file, then opens them.
// Receives: ifstream object by reference, input file, 
//           ofstream object by reference, output file
// Returns:  ifstream and ofstream by reference (input and output file)
void openFiles(ifstream &infile, ofstream &outfile);

// Purpose:  Calculates the sum of n * n (iteratively)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int sum, sum of n * n
int loopSum(int n);

// Purpose:  Calculates the sum of n * n (recursively)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int sum, sum of n * n
int recSoln(int n);

// Purpose:  Calculates the sum of n * n (closed form)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int sum, sum of n * n
int closed(int n);

int main()
{
    ifstream infile;
    ofstream outfile;
    openFiles(infile, outfile);

    outfile << "Angel Badillo\n" << "Program 2: Squares\n"; // Print header
    outfile << right << "N" << setw(10) << "LoopSum" << setw(15) << "RecSoln" << setw(15) << "Closed\n";
    int numInts;
    infile >> numInts; // num of ints in input file
    int n; // value of n
    
    for(int i = 0; i < numInts; i++)
    {
        infile >> n;
        outfile << right << n << setw(10) << loopSum(n) << setw(15) << recSoln(n) << setw(15) << closed(n) << '\n';

        
    }

    infile.close();
    outfile.close();
    return 0;
}


// Purpose:  Prompts user for names of input & output file, then opens them.
// Receives: ifstream object by reference, input file, 
//           ofstream object by reference, output file
// Returns:  ifstream and ofstream by reference (input and output file)
void openFiles(ifstream &infile, ofstream &outfile)
{
    string inFileName;
    string outFileName;

    cout << "Enter the input filename: ";
    cin >> inFileName;

    infile.open(inFileName); //open input file
    cout << "Enter the output filename: ";

    cin >> outFileName;
    outfile.open(outFileName); //open output file
}

// Purpose:  Calculates the sum of n * n (iteratively)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int sum, sum of n * n
int loopSum(int n)
{
    int sum = 0;

    if(n < MIN || n > MAX) // Value not in range
    {
        return -1;
    }
    else // In range
    {
        for (int i = MIN; i <= n; i++) //
        {
            sum += i * i;
        }
    }
    return sum;
}

// Purpose:  Calculates the sum of n * n (recursively)
// Receives: int n, an integer 1 <= n <= 100
// Returns: int sum, sum of n * n
int recSoln(int n)
{
    if(n < MIN || n > MAX) // Value not in range
    {
        return -1;
    }
    else if(n == MIN) // Base case
    {
        return n*n;
    }
    return n*n + recSoln(n-1);
}

// Purpose:  Calculates the sum of n * n (closed form)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int sum, sum of n * n
int closed(int n)
{
    int sum = 0;
    
    if(n < MIN || n > MAX) // Value not in range
    {
        return -1;
    }
    else
    {
        sum = n * (n + 1) * ((2 * n) + 1) / 6;
    }
    return sum;
}
