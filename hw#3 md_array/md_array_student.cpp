#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

double** set_2D_array(int ,int);
double*** set_3D_array(int, int, int);
double **multiplication_2D_array(double **, double **, int, int);
double **sum_2D_array(double **, double **, int, int);
void print_2D_array(double **ptr, int M, int N);

// main program
int main() {
	double **aptr,**bptr,**cptr;      // 指標宣告二維陣列
		// ** 越遠離變數型態的維度越小 (ex: *aptr = aptr 的第一維度)
	int Row, Col;
	cin >> Row >> Col;

	aptr = set_2D_array(Row, Col);
	bptr = set_2D_array(Row, Col);
	cptr = multiplication_2D_array(aptr,bptr,Row, Col);  // 二維陣列相乘

	print_2D_array(aptr, Row, Col);   // print a 二維陣列
	print_2D_array(bptr, Row, Col);   // print b 二維陣列

	cout <<"After Performing array multiplications :\n";   // print 陣列相乘結果
	print_2D_array(cptr, Row, Col);

	cout <<"\nAfter Performing array summations :\n";      // print 陣列相加結果
	print_2D_array(sum_2D_array(aptr,bptr, Row, Col),Row, Col);

	system("pause");
  return 0;  
};

// ========================================================
// This function is to allocate(配置) 2D array memeory space
// whose dimension is M x N (double)
// ========================================================
double** set_2D_array(int M, int N) {
	// 2D-array dynamic announcement: * = []
	// 陣列三種宣告方法 : **array = *array[N] = array[M][N] 
	// ** 越遠離變數型態的維度越小
	double** ptr = new double*[M];  // *[] = 2D array , total rows = M
	for(int i=0; i<M; i++)  ptr[i] = new double[N];  // total columns = N

	for (int i=0; i<M; i++)
		for (int j=0; j<N; j++)
			cin >> ptr[i][j];     // input the value from keyboard
			// ptr[i][j] = i*N + j;  assign arbitrary(任意) number 
	return ptr;
}

// This function is to allocate 3D array memeory space
// whose dimension is M x N x O (double)
double ***set_3D_array(int M, int N, int O) {
	M=1000; N=1000; O=1000;
	// *** 越遠離變數型態的維度越小
    double*** ptr = new double**[M];  // ptr 的第一維度 = M

	for(int i=0; i<M; i++)  {
		ptr[i] = new double*[N];  // ptr 的第二維度 = N

		for(int j=0; j< O; j++)
			ptr[i][j] = new double[O];  // ptr 的第三維度 = O
	}
	   return ptr;

}
// ========================================================
// This function is used to print out the 2D array data (M x N)
// ========================================================
void print_2D_array(double **ptr, int M, int N)   
{
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++)
			cout << setw(4) << ptr[i][j];
		cout << endl;
	}
	cout << endl;
}

// ========================================================
// This function is used to perform 2D-array multiplication
// A * B whose dimenaion is M by N
// ========================================================
double **multiplication_2D_array(double **a, double **b, int M, int N){
	double **c = new double*[M];
	for (int i = 0; i < M; i++)  c[i] = new double[N]; 

	// Complete the program by your self here
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			c[i][j] = 0;
			for (int k = 0; k < N; k++)
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
		}
	return c;
}
// ========================================================
// This function is used to perform 2D array addition
// A * B whose dimenaion is M by N
// ========================================================
double **sum_2D_array(double **a, double **b, int M, int N){
	double **c = new double*[M];
	for (int i = 0; i < M; i++)  c[i] = new double[N];

	// Complete the program by yourself here
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			c[i][j] = a[i][j] + b[i][j];
 return c;
}