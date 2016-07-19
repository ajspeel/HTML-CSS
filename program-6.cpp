// Alex Castillo
// Cpp-4
// This program will read a list of numbers from a file and echo some calcuclations. 

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	ofstream outputFile("GradeReport.txt"); // file the data will be written to
	ifstream inputFile; // file that will be read
	string filename;    // name of the file that the user enters
	int number; // numbers to be read in file
	int num = 1; // counter 



	cout << "Alex Castillo" << endl;
	cout << endl;

	// Get the filename from the user.
	cout << "Enter the input file name : ";

	// user enters filename
	getline(cin, filename);

	// Open the input file.
	inputFile.open(filename);

	cout << endl;

	// test to see if the input file oppened successfully
	if (inputFile.fail())
	{
		// echo error
		cout << "Error opening file: " << filename << endl;
		cout << endl;
		cout << "Program Terminated " << endl;
	}
	cout << endl;

	// Read the numbers from the file and write them.
	while (inputFile >> number)
	{

		// write the contents of each line into another file
		outputFile << setw(2) << num << ". " << setw(3) << number << "\n";


		//increment number by 1
		num++;

		//conditional to print invalid
		if (number < 0 || number > 100)

			//print invalid
			outputFile << "INVALID" << endl;
	}
// declare variables for getting total for each invalid and valid	
int validGrades = number >= 100 || number <= 0;
int invalidGrades = number > 100 || number < 0;

// echo the amount of students for each invalid and valid
outputFile << "Number of VALID grades: " << validGrades;
outputFile << "Number of INVALID grades: " << invalidGrades;



		// Close the file.
		inputFile.close();
		outputFile.close();
		return 0;

	
}