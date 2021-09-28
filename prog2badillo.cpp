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
#include <fstream>
#include <string>

using namespace std;

// Purpose:  Prompts user for names of input & output file, then opens them.
// Receives: ifstream object by reference, input file, 
//           ofstream object by reference, output file
// Returns:  ifstream and ofstream by reference (input and output file)
void openFiles(ifstream &infile, ofstream &outfile);

// Purpose:
// Receives:
// Returns:
int sumIt(int n);

// Purpose:
// Receives:
// Returns:
int sumRec(int n);

// Purpose:
// Receives:
// Returns:
int sumClose(int n);

int main()
{
    ifstream infile;
    ofstream outfile;
    openFiles(infile, outfile);





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
    outfile.open(outFileName); //open out putfile
}
