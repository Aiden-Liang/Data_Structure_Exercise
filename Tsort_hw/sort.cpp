template<class T>
void selectSort(T arr[], int n) {
         int iMin;
         // a temporary variable used to sort the array. 
         // Notice it uses the type T that was defined in the template parameters?
         T temp;          
         
         for (int i=0;i<n-1;i++){
                 iMin = i;
                 for (int j=i+1;j<n;j++) {
                         if (arr[j] < arr[iMin]) {
                                iMin = j;                  
                         }
                 } 
                 if (iMin != i) {
                        // the smallest item is somewhere else in the array so move it to this position
                        temp = arr[i];
                        arr[i] = arr[iMin];
                        arr[iMin] = temp;                  
                 }   
         }
}
