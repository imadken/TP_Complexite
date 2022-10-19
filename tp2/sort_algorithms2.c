#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void load_data(FILE *f,int tab [],int size);
void print_array(int tab [],int size);
void swap(int* xp, int* yp);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);
void bubbleSort(int arr[], int n);
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r);
void heapify(int arr[], int N, int i);
void heapSort(int arr[], int N);
void complexite(FILE *f,int size);


int main(){

// srand(time(0));


FILE *f1=fopen("10-4.txt","r");
FILE *f2=fopen("10-4_inv.txt","r");
FILE *f3=fopen("10-4_rand.txt","r");


printf("\n fichier triee de taille 10^4 \n\n-------------------------------------\n\n");
complexite(f1,10000);

printf("\n fichier inversee de taille 10^4 \n\n-------------------------------------\n\n");
complexite(f2,10000);

printf("\n fichier random de taille 10^4 \n\n-------------------------------------\n\n");
complexite(f3,10000);



fclose(f1);
fclose(f2);
fclose(f3);


}
// cette procedure permet de charger les donnes du fichier vers un tableau d'entiers
void load_data(FILE *f,int tab [],int size){
    char x [10];
    int i=0;
while (  fscanf(f, "%[^\n] ", x)!= EOF) {
    
    tab[i]=atoi(x);
    i++;
    }
}

void print_array(int tab [],int size){
for (int i=0 ; i<size ; i++) printf("%d\n",tab[i]);
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// tri par selection

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

// tri par insertion

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
//////////////////////////////////////////////

// tri rapide
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
//   int pivot = array[low];
//   int pivot = array[(low+high)/2];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}



// tri a bulle
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}




// tri par fusion
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}


void heapify(int arr[], int N, int i)
{
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int N)
{
 
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
 
        heapify(arr, N, i);
 
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}




// cette procedure prend en entree un fichier et la taille des donnees ,exp taille = 10^4
//elle permet de calculer le temps d'execution pour chaqu'un des algorithmes de tri 

void complexite(FILE *f,int size){

  int tab1[size];

clock_t t1,t2;

double delta;



// loading data
load_data(f,tab1,size);

//setting the file cursor back to beginning
rewind(f);

// important !! we have to load data and set the cursor back to beginning each time we sort the array 




t1=clock();
selectionSort(tab1,size);
t2=clock();
delta = (t2-t1)/CLOCKS_PER_SEC;

printf("trie par selection : %f \n",delta);
printf("------------------------------------------\n\n");

load_data(f,tab1,size);


rewind(f);


t1=clock();
insertionSort(tab1,size);
t2=clock();
delta = (t2-t1)/CLOCKS_PER_SEC;

printf("trie par inserion : %f \n",delta);
printf("------------------------------------------\n\n");

load_data(f,tab1,size);


rewind(f);


t1=clock();
bubbleSort(tab1,size);
t2=clock();
delta = (t2-t1)/CLOCKS_PER_SEC;

printf("trie a bulle : %f \n",delta);
printf("------------------------------------------\n\n");

load_data(f,tab1,size);
rewind(f);


t1=clock();
quickSort(tab1,0,size-1);
t2=clock();
delta = (t2-t1)/CLOCKS_PER_SEC;

printf("trie rapide : %f \n",delta);
printf("------------------------------------------\n\n");

load_data(f,tab1,size);


rewind(f);


t1=clock();
mergeSort(tab1,0,size-1);
t2=clock();
delta = (t2-t1)/CLOCKS_PER_SEC;

printf("trie par fusion : %f \n",delta);
printf("------------------------------------------\n\n");

load_data(f,tab1,size);





t1=clock();
heapSort(tab1,size);
t2=clock();
delta = (t2-t1)/CLOCKS_PER_SEC;

printf("trie par tas : %f \n",delta);
printf("------------------------------------------\n\n");


}





