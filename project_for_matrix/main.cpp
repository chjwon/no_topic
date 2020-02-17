#include <iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>


using namespace std;


bool Get_DataArray(ifstream& input_File,
	int &max, float dataArray[], float *ptrArray[]) {

	if (!(input_File >> max)) {
		return true;
	}

	for (int i = 0; i < max; i++) {
		input_File >> dataArray[i];
		ptrArray[i] = &dataArray[i];
	}
	return false;
}

void Print_DataArray(float dataArray[], int max) {
	cout << "Data Array elements are: " << endl;
	for (unsigned i = 0; i < max; i++) {
		cout << dataArray[i] << setw(6);
	}
	cout << endl;
}


void Print_PointerArray(float* ptrArray[], int max) {
	cout << "The Pointer Array" << endl;
	for (int i = 0; i < max; i++) {
		cout << *ptrArray[i] << setw(6);
	}
	cout << endl;
}

void Swap_ptr(float*& a, float*& b){
	float* temp = a;
	a = b;
	b = temp;
}

void Sorting(float* ptrArray[], int max) {
	for (int i = 0; i < max; i++) {
		for (int j = i + 1; j < max; j++) {
			if (*ptrArray[j] < *ptrArray[i])
				Swap_ptr(ptrArray[j], ptrArray[i]);
		}
	}
}

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
		cout << "File " << input_file_name << "could not be opened" << endl;
		cin.get();
		exit(EXIT_FAILURE);
	}
	
	while (! Get_DataArray (input_matrix_FIle, max, data_Array,ptr_Array)) {
		Sorting(ptr_Array, max);
		Print_PointerArray(ptr_Array, max);
		Print_DataArray(data_Array, max);
		cout << endl << "Press any key to continue ...";
		cin.get();
		cout << endl << endl;
	}
	
	input_matrix_FIle.close();
	return EXIT_SUCCESS;
	}