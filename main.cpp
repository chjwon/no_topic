#include<iostream>
#include<fstream>

#include<conio.h>

#pragma warning(disable : 4996)

using namespace std;

const unsigned int MATRIX_SIZE = 20;

void Function();

int main() {
	Function();
}

void Function() {


	int row = 0, column = 0;
	ifstream matrixFile;
	string file = "C:/Users/USER/Desktop/ÀÚ·á/txt/matrix.txt";

	float input_arr[MATRIX_SIZE][MATRIX_SIZE];

	//Inputing Demension from File
	matrixFile.open(file);



	while (!matrixFile.eof()) {

		matrixFile >> column;
		matrixFile >> row;
		matrixFile.ignore();


		if (row <= 0) {
			cout << "no value" << endl;
			exit(1);
		}



		/*
		//cin >> column >> row;
		cout << endl;
		//Input array
		float** input_arr = (float**)malloc(sizeof(float*) * column * row);


		for (int i = 0; i < column; i++)
			input_arr[i] = (float*)malloc(sizeof(float) * row);

		*/

		//Input the numbers
		for (int i = 0; i < column; i++) {
			for (int j = 0; j < row; j++) {
				matrixFile >> input_arr[i][j];
			}
		}

		//matrixFile.close();



		//sum array
		float* sum_arr = (float*)malloc(sizeof(float) * row);

		//reset the sum array
		for (int i = 0; i < row; i++) {
			sum_arr[i] = 0;
		}

		//get the sum array
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				sum_arr[i] += input_arr[j][i];
			}
		}

		//print input
		cout << "Input:" << endl;
		cout << fixed;
		cout.precision(3);
		//cout << column << ' '<< row << endl;

		for (int i = 0; i < column; i++) {
			for (int j = 0; j < row; j++) {
				cout << fixed;
				cout.precision(3);
				cout << ' ' << ' ' << ' ';
				cout << input_arr[i][j];
			}
			cout << endl;
		}





		//print sum

		cout << "Sum:" << endl;
		for (int i = 0; i < row; i++) {
			cout << fixed;
			cout.precision(3);
			cout << ' ' << ' ' << ' ';
			cout << sum_arr[i];
		}
		cout << endl;


		//sort

		int num_num = row * column;//size of 1D

		//sort array

		float* sort_arr = (float*)malloc(sizeof(float) * num_num);




		//ger the number into 1D array
		for (int i = 0; i < column; i++) {
			for (int j = 0; j < row; j++) {
				int sort_num = i * row + j;
				sort_arr[sort_num] = input_arr[i][j];
			}
		}

		//sort

		//bubble sort
		float temp;
		for (int i = 0; i < num_num; i++) {
			for (int j = 0; j < num_num - i - 1; j++) {
				if (sort_arr[j] > sort_arr[j + 1]) {
					temp = sort_arr[j];
					sort_arr[j] = sort_arr[j + 1];
					sort_arr[j + 1] = temp;
				}
			}
		}


		//make the Input array sorted

		for (int i = 0; i < num_num; i++) {
			int j;
			j = i / row;

			input_arr[j][i % row] = sort_arr[i];
		}



		//print sorted array
		cout << "Sorted: " << endl;
		for (int i = 0; i < column; i++) {
			for (int j = 0; j < row; j++) {
				cout << fixed;
				cout.precision(3);
				cout << ' ' << ' ' << ' ';
				cout << input_arr[i][j];
			}
			cout << endl;
		}

		//vertical additive symmetry
		cout << "Vertical additive symmetry : " << endl;


		int middle = (row / 2);
		int sym = 1;
		for (int i = 0; i < middle; i++) {
			if (sum_arr[i] == sum_arr[row - 1 - i]) {
				continue;
			}
			else {
				//cout << "No"<<endl;
				//exit(0);
				sym = 0;
			}
		}
		if (sym == 1) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}

		//end part
		cout << "Press any key to continue..." << endl;
		getch();
	}

}