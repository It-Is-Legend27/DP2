//-----------------------------------------------------------------------------
//
// Name: Angel Badillo
//
// Course: CMPS-2433-101, Fall 2021, Springfellow
//
// Purpose: This program reads integers from an input file with values of 0 to 
//          65535, then reverses the order of the bits, then prints out the 
//          original number and the reverse number to an output file.
//
//-----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>

// Purpose:  Prompts user for names of input & output file, then opens them.
// Receives: ifstream object by reference, input file, 
//           ofstream object by reference, output file
// Returns:  ifstream and ofstream by reference (input and output file)
void openFiles(ifstream &infile, ofstream &outfile);

int main()
{
    
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
    char inFileName[40];
    char outFileName[40];

    cout << "Enter the input filename: ";
    cin >> inFileName;

    infile.open(inFileName); //open input file
    cout << "Enter the output filename: ";

    cin >> outFileName;
    outfile.open(outFileName); //open out putfile
}
