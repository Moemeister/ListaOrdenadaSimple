#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Nodo{
	int valor;
	struct Nodo* next;
}Nodo;
//NUMBER OF NODES IN THE LINKED LIST
int n = 20;
int c=0;

Nodo* L = NULL;
Nodo* L2 = NULL;
Nodo* createNodo(){
	Nodo* n = (Nodo*)malloc(sizeof(Nodo));
	return n;
}

Nodo* createList(){
	return NULL;
}
int generateRamdomNumber(){
	return rand()%1501;
}
void insert(Nodo* n){
	n->next = L;
    //n2->next = L2;

	L=n;
    //L2 = n2;
}
void insert2(Nodo* n){
	n->next = L2;
	L2=n;
}
int ramdomN;
void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        }else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1){ 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2){ 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r){ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
void llenar(int tam){
	Nodo* nuevo = NULL;
    Nodo* nodosMenores = NULL;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = generateRamdomNumber();
    }
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    mergeSort(arr,0,arr_size-1);
	for(int i=0;i<tam;i++){
		nuevo = createNodo();
		nuevo->valor = arr[i];
		nuevo->next=NULL;
        if (arr[i]<100){
            c++;       
        }
		insert(nuevo);

	}
    int arrTemp[c];
    for(int j=0;j<c;j++){
        nodosMenores = createNodo();
        nodosMenores->valor = arr[j];
        nodosMenores->next =NULL;
        insert2(nodosMenores);
    }
}


void show(){
	Nodo* otroL = L;
    Nodo* otroL2 = L2;
	while(otroL!=NULL){
		printf("%d\n",otroL->valor);
		otroL = otroL->next;
	}
    printf("LISTA 2: \n");
    while(otroL2!=NULL){
        if(otroL2->valor == 0){
            printf("NO HAY NUMEROS MENORES A 100\n");
            otroL2 = otroL2->next;
        }else{
            printf("%d\n",otroL2->valor);
            otroL2 = otroL2->next;
        }
        
    }

}
int main(){
	time_t t;
	srand((unsigned) time(&t));
	L=createList();
    L2=createList();
	llenar(n);
	show();

}