/*==========================================================
 This program is used to demonstrate 
  1. how to use data structure for composite data 
  2. how to use dynamic memory allocation
  Designed by Jiann-Jone Chen, 2020.03.12 updated
  =========================================================
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "student.h"
using namespace std;
void process();
void file_process();


int main() {
	student s1[10]; /* Static memory allocation, but we use dynamic mem allocation */
	// process();  /* consol mode execution*/

	file_process(); /* file open exeution*/
	// open file & search & sorting

	system("pause");
}


