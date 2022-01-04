#include <iomanip>
#include "student.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void process() {
	int i,n;            /* i = index , n = number of record to be read */
	student *s;	        // *s is the pointer
	string tt;

	cin >> n; getline(cin,tt);  // Àò¨ú¦r¦ê:getline
//	cout << "n=" << n << endl;

	if (n > 1) s = new student[n];  /* dynamic memory allocation */
		cout << "Now reading the record from the input file....." << endl;
		for (i = 0; i < n; i++) {
			cin >> s[i].p.name >> s[i].p.pID >> s[i].p.age >> s[i].sID >> s[i].dept >> s[i].grade1 >> s[i].grade2 >> s[i].grade3;
		}

		cout << "Output the recorded data " << endl;
		for (i = 0; i < n; i++) {
			cout << i << setw(12) << s[i].p.name << setw(12) << s[i].p.pID << setw(4) << s[i].p.age << setw(14) << s[i].sID << setw(4) << s[i].dept << s[i].grade1 << s[i].grade2 << s[i].grade3 << s[i].average << endl;
		}
	
}

// linear search
void linear_search(student *a, const int n) {

	cout << "After Linear Search (Name & Avarage) :\n";
	
	int max = 0;
	for (int j = max + 1; j < n; j++) {
		if (a[max].average < a[j].average) {
			max = j;
		}
	}
	cout << "Highest average : " << setw(5) << a[max].p.name << setw(6) << a[max].average << endl;
	
	int min = 0;
	for (int i = min + 1; i < n;i++) {
		if(a[min].average > a[i].average){
			min = i;
		}
	}
	cout << "Lowest average : " << setw(7) << a[min].p.name << setw(5) << a[min].average << endl;
}

// select sort
void select_sort(student *a, const int n) {  // const:immutable integer variables
	for (int i = 0; i < n; i++) {
		int min = i;    // define minimum index before sorting
		for (int j = i + 1; j < n; j++) {
			if (a[min].average < a[j].average) {
				min = j;   // remember minimum index
			}
		}
		//interchange the value
		student temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		
	}

	cout << "-------------------------------------------------------------------------------\n";
	cout << "After Selection Sorting (Name & Avarage) :\n";
	cout << setw(9) << "-NAME-" << setw(8) << "-AVE-" << endl ;
	
	for (int i = 0; i < n; i++) {
		cout << setw(8) << a[i].p.name << setw(8) << a[i].average << endl;
	}
	cout << "-------------------------------------------------------------------------------\n";
}

void file_process() {
	int i, n; /* i is for index and n is the number of record to be read */
	student *s;
	string tt;
	ifstream fin("list2.txt"); if (!fin) exit(1); // exit if file open error
	fin >> n; getline(fin, tt);
	//	cout << "n=" << n << endl;
	if (n > 1) s = new student[n];  /* dynamic memory allocation */
		cout << "Now reading the record from the input file....." << endl;
		for (i = 0; i < n; i++) {
			fin >> s[i].p.name >> s[i].p.pID >> s[i].p.age >> s[i].sID >> s[i].dept >> s[i].grade1 >> s[i].grade2 >> s[i].grade3 ;
		};
		cout << "Output the recorded data : " << endl;
		cout << endl;
		cout << "Index" << setw(8) << "NAME" << setw(7) << "P_ID" << setw(10) << "AGE" << setw(8) << "S_ID" << setw(11) << "Dept" << setw(5) << "S1" << setw(7) << "S2" << setw(7) << "S3" << setw(8) << "AVE" << endl;

		for (i = 0; i < n; i++) {
			s[i].average = (s[i].grade1 + s[i].grade2 + s[i].grade3) / 3;
			cout << i << setw(12) << s[i].p.name << setw(12) << s[i].p.pID << setw(4) << s[i].p.age << setw(14) << s[i].sID << setw(4) << s[i].dept << setw(7) << s[i].grade1 << setw(7) << s[i].grade2 << setw(7) << s[i].grade3 << setw(8) << setprecision(3) << s[i].average << endl;
		}
		
		cout << "-------------------------------------------------------------------------------\n";
		linear_search(s, 12);
		select_sort(s, 12);
		
		
}



