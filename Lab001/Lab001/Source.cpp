#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::getline;
using std::string;

int ReadData(ifstream& in, double& first1, double& first2, double& last1, double& last2) {
	int count = 0;
	double tmp;
	if (!in.is_open()) {
		return 999;
	}
	while (in >> tmp) {
		if (count == 0) {
			first1 = tmp;
			last2 = first1;
		} else if (count == 1) {
			first2 = tmp;
			last1 = first1;
			last2 = first2;
		}
		else {
			last1 = last2;
			last2 = tmp;
		}
		count++;
	}
	return count;
}

int main() {
	double first1 = 0;
	double first2 = 0;
	double last1 = 0;
	double last2 = 0;
	double valHolder = 0;
	ifstream inFile;
	string fileName;

	
	cout << "Please enter the name of the file:" << endl;
	getline(cin, fileName);
	inFile.open(fileName);
	
	int count = ReadData(inFile, first1, first2, last1, last2);
	inFile.close();
	cout << "The first 2 and last 2 numbers are:" << first1 << " " << first2 << " " << last1 << " " << last2 << endl;
	cout << "There are " <<count << " numbers in the file" << endl;
	system("PAUSE");
	return 0;
}