//Metodo insertion sort 
 #include <iostream> 
 using namespace std;
  
 void print(int t, int *a) { 
     cout << "----------------------" << endl; 
     for(int i=0; i<t; ++i) { 
         cout << "Elemento " << i << ": " << a[i] << endl; 
     } 
     cout << "----------------------" << endl; 
 } 
  
 void insertion_sort(int t, int *a) { 
     int key, j; 
     for(int i = 1; i < t; ++i) { 
         key = a[i]; 
         j = i - 1; 
  
         while(j >= 0 && a[j] > key) { 
             a[j+1] = a[j]; 
             j = j - 1; 
         } 
  
         a[j+1] = key; 
     } 
 }
  
 //Metodo Quick sort
 void change (int* a, int* b) { 
     int temp = *a; 
     *a = *b; 
     *b = temp; 
 } 
  
 int partition(int *a, int low, int high) { 
     int pivot = a[high]; 
     int i = low - 1; 
  
     for(int j = low; j <= high - 1; ++j) { 
         if(a[j] < pivot) { 
             ++i; 
             change(&a[i], &a[j]); 
         } 
     } 
  
     change(&a[i+1], &a[high]); 
     return i+1; 
 } 
  
 void quick_sort(int *a, int low, int high) { 
     if(low < high) { 
         int pi = partition(a, low, high); 
  
         quick_sort(a, low, pi-1); 
         quick_sort(a, pi+1, high); 
     } 
 } 
  
 //Selection Sort
  void selection_sort(int *a, int t) { 
     for(int i = 0; i < t-1; ++i) { 
         int min_index = i; 
         for(int j = i+1; j < t; ++j) { 
             if(a[j] < a[min_index]) { 
                 min_index = j; 
             } 
         } 
         change(&a[i], &a[min_index]); 
     } 
 } 
  
  
 //Merge Sort 
 void merge(int *a, int left, int mid, int right) { 
     int n1 = mid - left + 1; 
     int n2 = right - mid; 
  
     int *L = new int[n1]; 
     int *R = new int[n2]; 
  
     for(int i = 0; i < n1; ++i) { 
         L[i] = a[left + i]; 
     } 
     for(int j = 0; j < n2; ++j) { 
         R[j] = a[mid + 1 + j]; 
     } 
  
     int i = 0; 
     int j = 0; 
     int k = left; 
  
     while(i < n1 && j < n2) { 
         if(L[i] <= R[j]) { 
             a[k] = L[i]; 
             ++i; 
         } else { 
             a[k] = R[j]; 
             ++j; 
         } 
         ++k; 
     } 
  
     while(i < n1) { 
         a[k] = L[i]; 
         ++i; 
         ++k; 
     } 
  
     while(j < n2) { 
         a[k] = R[j]; 
         ++j; 
         ++k; 
     } 
  
     delete[] L; 
     delete[] R; 
 } 
  
 void merge_sort(int *a, int left, int right) { 
     if(left < right) { 
         int mid = left + (right - left) / 2; 
  
         merge_sort(a, left, mid); 
         merge_sort(a, mid + 1, right); 
  
         merge(a, left, mid, right); 
     } 
 } 
  
 int main(int argc, char** argv) { 
     int v[8] = {49, 38, 58, 87, 34, 93, 26, 13}; 
     print(8, v); 
     merge_sort(v, 0, 7); 
     print(8, v); 
     return 0; 
 } 
  
  
 //Shell Sort 
 void shell_sort(int *a, int t) { 
     for(int gap = t/2; gap > 0; gap /= 2) { 
         for(int i = gap; i < t; ++i) { 
             int temp = a[i]; 
             int j; 
             for(j = i; j >= gap && a[j-gap] > temp; j -= gap) { 
                 a[j] = a[j-gap]; 
             } 
             a[j] = temp; 
         } 
     } 
 } 
  
 int main(int argc, char** argv) { 
     int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
     print(8, v); 
     shell_sort(v, 8); 
     print(8, v); 
     
     v = {49, 38, 58, 87, 34, 93, 26, 13}; 
     print(8, v); 
     merge_sort(v, 0, 7); 
     print(8, v);
     
     v[] = {49, 38, 58, 87, 34, 93, 26, 13}; 
     print(8, v); 
     selection_sort(v, 8); 
     print(8, v);
     
     v[] = {49, 38, 58, 87, 34, 93, 26, 13}; 
     print(8, v); 
     quick_sort(v, 0, 7); 
     print(8, v);
     
     v[] = {49, 38, 58, 87, 34, 93, 26, 13}; 
     print(8, v); 
     insertion_sort(8, v); 
     return 0; 
 }