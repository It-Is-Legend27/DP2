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

const int MIN = 1;   // Minimum value for n
const int MAX = 100; // Maximum value for n

// Purpose:  Prompts user for names of input & output file, then opens them.
// Receives: ifstream object by reference, input file,
//           ofstream object by reference, output file
// Returns:  ifstream and ofstream by reference (input and output file)
void openFiles(ifstream &infile, ofstream &outfile);

// Purpose:  Prints headers to output file
// Receives: ofstream object by reference, output file
// Returns:  ofstream object by reference, output file
void printHeader(ofstream &outfile);

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

// Purpose:  Determines whether n is 1 <= n <= 100
// Receives: int n by value, an integer
// Returns:  bool value 0 or 1, 1 if valid, 0 if invalid
bool isValid(int n);

int main()
{
    ifstream infile;
    ofstream outfile;
    int numInts, n;
    
    openFiles(infile, outfile);

    // Prints headers to output file
    printHeader(outfile);

    infile >> numInts;

    for (int i = 0; i < numInts; i++)
    {
        infile >> n;

        if (isValid(n)) // If 1 <= n <= 100
        {
            outfile << right << setw(3) << n << setw(10) << loopSum(n)
                    << setw(17) << recSoln(n) << setw(16) << closed(n) << '\n';
        }
        else // If n < 1 or n > 100
        {
            outfile << right << setw(3) << n << setw(10) << "ERROR"
                    << setw(17) << "ERROR" << setw(16) << "ERROR" << '\n';
        }
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

// Purpose:  Prints headers to output file
// Receives: ofstream object by reference, output file
// Returns:  ofstream object by reference, output file
void printHeader(ofstream &outfile)
{
    outfile << "Angel Badillo\n"
            << "Program 2: Squares\n";
    outfile << setw(3) << "N" << setw(10) << "LoopSum"
            << setw(17) << "RecSoln" << setw(17) << "Closed\n";
}

// Purpose:  Calculates the sum of n * n (iteratively)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int sum, sum of n * n
int loopSum(int n)
{
    int sum = 0;

    for (int i = MIN; i <= n; i++)
    {
        sum += i * i;
    }

    return sum;
}

// Purpose:  Calculates the sum of n * n (recursively)
// Receives: int n, an integer 1 <= n <= 100
// Returns: int sum, sum of n * n
int recSoln(int n)
{
    if (n == MIN) // Base case
    {
        return n * n;
    }
    return n * n + recSoln(n - 1);
}

// Purpose:  Calculates the sum of n * n (closed form)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int sum, sum of n * n
int closed(int n)
{
    int sum = 0;
    sum = n * (n + 1) * ((2 * n) + 1) / 6;
    return sum;
}

// Purpose:  Determines whether n is 1 <= n <= 100
// Receives: int n by value, an integer
// Returns:  bool value 0 or 1, 1 if valid, 0 if invalid
bool isValid(int n)
{
    return MIN <= n && n <= MAX;
}