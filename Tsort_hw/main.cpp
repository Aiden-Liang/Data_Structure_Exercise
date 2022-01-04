#include "rectangle.h"
// demonstrating sorting an array of objects
int main() {
// Sort integers 
	int nums[6] = {3,2,4,5,6,7};
		sort(nums, 6);
		for (int i=0;i<6;i++) {cout << nums[i] << " ";}
			cout << "end of sorting integer"<<endl << endl;

// Sort floating numbers
	float rnums[6]={-1.0, -3.8, 4, 9.0, -18.2, 6.9};
		sort(rnums, 6);
		for (int i=0;i<6;i++) {cout << rnums[i] << " ";}
			cout << "end of sorting floating numbers"<<endl<<endl;

// Sort rectangles by its Area
		rect shapes[6]={rect(9, 9), rect(4,8), rect(5,2), rect(11, 11), rect(8, 10), rect(1,2)};
		sort(shapes, 6);
		for (int i=0;i<6;i++) cout << shapes[i];
		cout << "end of sorting rectangle objects accroding to their area"<<endl;

system("pause");
return 0;
}