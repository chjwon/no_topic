#include <iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>

// fixed
using namespace std;

//Functions
bool ReadIntoDataArray(ifstream& input_File,
	unsigned& max, int dataArray[], int* ptrArray[]);

void Print_dataArray(int dataArray[], unsigned max);
void Print_ptrArray(int* ptrArray[], unsigned max);

void SwapIntPtr(int*& a, int*& b);
void Sort_Array(int* ptrArray[], unsigned max);

int main() {
	//Variable declaration
	const unsigned       ARRAY_SIZE = 20;
	unsigned             max = 0;
	int                  data_Array[ARRAY_SIZE];
	int                  * ptr_Array[ARRAY_SIZE];
	string               INPUT_FILE_NAME = "arrayData.txt";
	ifstream             inputArray;

	inputArray.open(INPUT_FILE_NAME);
	if (inputArray.fail()) {
		cout << "File " << INPUT_FILE_NAME << "has the error!!" << endl;
		cin.get();
		exit(EXIT_FAILURE);
	}

	while (!ReadIntoDataArray(inputArray, max, data_Array, ptr_Array)) {
		Sort_Array(ptr_Array, max);
		Print_ptrArray(ptr_Array, max);
		Print_dataArray(data_Array, max);
		cout << endl << "Press any key to continue ,,,,";
		cin.get();
		cout << endl << endl;
	}

	inputArray.close();
	return EXIT_SUCCESS;
}

bool ReadIntoDataArray(ifstream& input_File,
	unsigned& max, int dataArray[], int* ptrArray[]) {

	if (!(input_File >> max)) {
		return true;
	}

	for (int i = 0; i < max; i++) {
		input_File >> dataArray[i];
		ptrArray[i] = &dataArray[i];
	}
	return false;
}

void Print_dataArray(int dataArray[], unsigned max) {
	cout << "Now displaying data in the original order " << endl;
	for (unsigned i = 0; i < max; i++) {
		cout << dataArray[i] << setw(6);
	}
	cout << endl;
}

void Print_ptrArray(int* ptrArray[], unsigned max) {
	cout << "Now displaying data in sorted order" << endl;
	for (int i = 0; i < max; i++) {
		cout << *ptrArray[i] << setw(6);
	}
	cout << endl;
}

void SwapIntPtr(int*& a, int*& b) {
	int *temp = a;
	a = b;
	b = temp;
}

void Sort_Array(int* ptrArray[], unsigned max) {
	for (int i = 0; i < max; i++) {
		for (int j = i + 1; j < max; j++) {
			if (*ptrArray[j] < *ptrArray[i])
				SwapIntPtr(ptrArray[j], ptrArray[i]);
		}
	}
}