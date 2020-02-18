#include <iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>


using namespace std;

//Functions
bool ReadIntoDataArray(ifstream& input_File,
	int& max, float dataArray[], float* ptrArray[]);

void Print_dataArray(float dataArray[], int max);
void Print_ptrArray(float* ptrArray[], int max);

void SwapIntPtr(float*& a, float*& b);
void Sort_Array(float* ptrArray[], int max);

int main() {
	//Variable declaration
	const unsigned       ARRAY_SIZE = 20;
	int                  max = 0;
	float                data_Array[ARRAY_SIZE];
	float                * ptr_Array[ARRAY_SIZE];
	string               input_file_name = "arrayData.txt";
	ifstream             input_matrix_FIle;

	input_matrix_FIle.open(input_file_name);
	if (input_matrix_FIle.fail()) {
		cout << "File " << input_file_name << "has the error!!" << endl;
		cin.get();
		exit(EXIT_FAILURE);
	}
	
	while (!ReadIntoDataArray(input_matrix_FIle, max, data_Array,ptr_Array)) {
		Sort_Array(ptr_Array, max);
		Print_ptrArray(ptr_Array, max);
		Print_dataArray(data_Array, max);
		cout << endl << "Press any key to continue ,,,,";
		cin.get();
		cout << endl << endl;
	}
	
	input_matrix_FIle.close();
	return EXIT_SUCCESS;
}

bool ReadIntoDataArray(ifstream& input_File,
	int& max, float dataArray[], float* ptrArray[]) {

	if (!(input_File >> max)) {
		return true;
	}

	for (int i = 0; i < max; i++) {
		input_File >> dataArray[i];
		ptrArray[i] = &dataArray[i];
	}
	return false;
}

void Print_dataArray(float dataArray[], int max) {
	cout << "Now displaying data in the original order " << endl;
	for (unsigned i = 0; i < max; i++) {
		cout << dataArray[i] << setw(6);
	}
	cout << endl;
}

void Print_ptrArray(float* ptrArray[], int max) {
	cout << "Now displaying data in sorted order" << endl;
	for (int i = 0; i < max; i++) {
		cout << *ptrArray[i] << setw(6);
	}
	cout << endl;
}

void SwapIntPtr(float*& a, float*& b) {
	float* temp = a;
	a = b;
	b = temp;
}

void Sort_Array(float* ptrArray[], int max) {
	for (int i = 0; i < max; i++) {
		for (int j = i + 1; j < max; j++) {
			if (*ptrArray[j] < *ptrArray[i])
				SwapIntPtr(ptrArray[j], ptrArray[i]);
		}
	}
}