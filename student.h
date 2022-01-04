//#ifndef STUDENT_H
//#define STUDENT_H
    typedef struct {  // This is a data structure for a person
		char name[40], pID[10];
		int age;
	} person ;
   
   typedef struct{   // a data structure for a student
	 person p;
	 char sID[10],dept[4];  // dept[2] ??? 
	 float grade1, grade2, grade3;   // add grade
	 float average;  // average grade
   } student;
//#endif