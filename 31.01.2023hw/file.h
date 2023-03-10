#pragma once
#include <iostream>
using namespace std;

class file {
public:
	int number_openings;
	file() : number_openings{ 0 } {};
	virtual void display(const char* path) {
		FILE* out;
		char* tempStr = new char[126];
		if (!fopen_s(&out, path, "r")) {
			cout << "~~~~~~~~~~~~" << endl;
			while (!feof(out)) {
				fgets(tempStr, 126, out);
				cout << tempStr;
			}
			cout << endl << "~~~~~~~~~~~~" << endl;
			fclose(out);
			number_openings += 1;
		}
		else cout << "file no open";
	}
};

class FileObACIIChild : public file {
public:
	FileObACIIChild() : file() {};
	virtual void display(const char* path) {
		FILE* out;
		char* tempStr = new char[126];
		if (!fopen_s(&out, path, "r")) {
			cout << "~~~~~~~~~~~~\n";
			while (!feof(out)) {
				fgets(tempStr, 126, out);
				cout << tempStr;
			}
			cout << "\n~~~~~~~~~~~~\n";
			fclose(out);
			number_openings += 1;
		}
		else cout << "file no open";
	}
};

class fileBit : public file {
	void to_binary_code(int a) {
		int* number = new int[125];
		int lenght = 0; 
		while (a > 0) {
			number[lenght] = a & 1;
			lenght++;
			a >>= 1;
		}
		for (int i = lenght - 1; i > -1; i--) cout << number[i];
	}
public:
	fileBit() : file() {};
	virtual void display(const char* path) {
		FILE* out;
		char tempSym;
		if (!fopen_s(&out, path, "r")) {
			while (!feof(out)) {
				tempSym = fgetc(out);
				if (tempSym != '\n' && tempSym != '\0') to_binary_code((int)tempSym);
				else cout << endl;
			}
			fclose(out);
			number_openings += 1;
		}
		else cout << "File wasn't opened";
	}
};