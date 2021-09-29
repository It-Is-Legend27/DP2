/*****************************************************************************
* Name: Angel Badillo
*
* Course: CMPS-2433-101, Fall 2021, Springfellow
*
* Purpose: This program finds the numbers of squares in a grid of N * N,
*          (sum of n^2), for 1 <= n <= 100. Program prompts user for i/o
*          file names, solves the sum of n^2 for each number in the input 
*          file, then prints the solution to the output file. The sum is
*          calculated by 3 different functions that serve the same purpose,
*          but have different implementations, and is printed to the output
*          file for each function.
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

// Purpose:  Calculates the sum of n * n (iteratively)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int sum, sum of n * n
int loopSum(int n);

// Purpose:  Calculates the sum of n * n (recursively)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int sum, sum of n * n
int recSum(int n);

// Purpose:  Calculates the sum of n * n (closed form)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int sum, sum of n * n
int closedSum(int n);

// Purpose:  Determines whether n is 1 <= n <= 100
// Receives: int n by value, an integer
// Returns:  bool value 0 or 1, 1 if valid, 0 if invalid
bool isValid(int n);

int main()
{
    ifstream infile;  // Input file stream
    ofstream outfile; // Output file stream
    int numInts;      // Number of ints in input file
    int n;            // Number of squares

    // Opens i/o files
    openFiles(infile, outfile);

    // Prints header and column names to output file
    outfile << "Angel Badillo\n"
            << "Program 2: Squares\n\n";
    outfile << setw(3) << "N" << setw(10) << "LoopSum"
            << setw(17) << "RecSoln" << setw(17) << "Closed\n";

    infile >> numInts;

    // Loops for every int in the file
    for (int i = 0; i < numInts; i++)
    {
        infile >> n;

        // If valid, prints out n, then sum calculated via 3 different ways
        if (isValid(n))
        {
            outfile << right << setw(3) << n << setw(10)
                    << loopSum(n) << setw(17) << recSum(n)
                    << setw(16) << closedSum(n) << '\n';
        }
        // If invalid input, prints out n and error message
        else
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
    string inFileName;  // std::strings are better
    string outFileName; // in my opinion v. c-strings

    cout << "Enter the input file name: ";
    cin >> inFileName;

    infile.open(inFileName); // Open input file
    cout << "Enter the output file name: ";

    cin >> outFileName;
    outfile.open(outFileName); // Open output file
}

// Purpose:  Calculates the sum of n * n (iteratively)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int sum, sum of n * n
int loopSum(int n)
{
    int sum = 0;

    // Adds i^2, with sum of prev i^2, where i increase 1 every iteration
    for (int i = MIN; i <= n; i++)
    {
        sum += i * i; // Adds last i^2 to prev sum of i^2
    }

    return sum;
}

// Purpose:  Calculates the sum of n * n (recursively)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int, sum of n * n
int recSum(int n)
{
    if (n == MIN)     // Base case
    {
        return n * n; // 1^2, or 1
    }
    return n * n + recSum(n - 1); // Adds last n^2 to sum of previous n^2
}

// Purpose:  Calculates the sum of n * n (closed form)
// Receives: int n, an integer 1 <= n <= 100
// Returns:  int, sum of n * n
int closedSum(int n)
{
    return n * (n + 1) * ((2 * n) + 1) / 6;
}

// Purpose:  Determines whether n is 1 <= n <= 100
// Receives: int n by value, an integer
// Returns:  bool value 0 or 1, 1 if valid, 0 if invalid
bool isValid(int n)
{
    return MIN <= n && n <= MAX;
}