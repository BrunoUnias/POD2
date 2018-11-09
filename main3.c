#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 10000
#define MAX 25

int* inicializaVetorRandom() {
    int i;
    int *ret = malloc(sizeof(int) * TAMANHO_VETOR);
    srand(time(NULL));
    for(i = 0; i < TAMANHO_VETOR;i++) {
        ret[i] = rand();
    }
    return ret;
}

int* inicializaVetorOrdenado() {
    int i;
    int *ret = malloc(sizeof(int) * TAMANHO_VETOR);
    for(i = 0; i < TAMANHO_VETOR;i++) {
        ret[i] = i;
    }
    return ret;
}

int* inicializaVetorInvertido() {
    int i;
    int *ret = malloc(sizeof(int) * TAMANHO_VETOR);
    for(i = 0; i < TAMANHO_VETOR;i++) {
        ret[i] = TAMANHO_VETOR - i;
    }
    return ret;
}

void selectionSort(int vet[], int tam){
	int i, j, min, aux;
	for(i=0; i<tam; i++){
		for(j=i+1; j<tam; j++){
			if(vet[min] > vet[j])
			min = j;
		}
		aux = vet[i];
		vet[i] = vet[min];
		vet[min] = aux;
		
	}
}

void insertionSort(int vet[], int tam) {
    int i,j = 0, aux = 0;
    for(i = 1; i < tam; i++) {
        aux = vet[i];
        j = i - 1;
        while((j >= 0) && (vet[j] > aux)){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = aux; 
    }
}

void bubbleSort(int vert[], int tam){
	int i,j,aux;
	for(i= tam-1; i>0; i--){
		for(j=0; j<i; j++){
			if(vert[j] > vert[j+1]){
				aux = vert[j];
				vert[j] = vert[j+1];
				vert[j+1] = aux;
			}
		}
	}
}

void quickSort(int a[], int n){
	int i, j, p, t;
	if(n<2)
	return;
	p = a[n/2];
	for(i=0,j = n-1;; i++, j--){
		while(a[i] < p)
			i++;
			while(p< a[j])
			if(i >= j)
			break;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			
	}
	quickSort(a,i);
    quickSort(a+i, n-i);
}

 void random_shuffle(int arr[])

    {

        int i, j, temp;

        srand(time(NULL));

        for (i = MAX - 1; i > 0; i--) {

             j = rand()%(i + 1);

             temp = arr[i];

             arr[i] = arr[j];

             arr[j] = temp;

        }

    }

    void  max_heapify(int a[], int i, int heapsize)

    {

        int tmp, largest;

        int l = (2 * i) + 1;

        int r = (2 * i) + 2;

        if ((l <= heapsize) && (a[l] > a[i]))

             largest = l;

        else

             largest = i;

        if ((r <= heapsize) && (a[r] > a[largest]))

             largest = r ;

        if (largest != i) 

        {

             tmp = a[i];

             a[i] = a[largest];

             a[largest] = tmp;

             max_heapify(a, largest, heapsize);

        }

     

    }

    void  build_max_heap(int a[], int heapsize)

    {

        int i;

        for (i = heapsize/2; i >= 0; i--)

        {

             max_heapify(a, i, heapsize);

        }

     

    }

    void heap_sort(int a[], int heapsize)

    {

        int i, tmp;

        build_max_heap(a, heapsize);

        for (i = heapsize; i > 0; i--) 

        {

            tmp = a[i];

            a[i] = a[0];

            a[0] = tmp;

            heapsize--;

            max_heapify(a, 0, heapsize);

        }

    }

void merge(int vetor[], int comeco, int meio, int fim) {

    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;

    int *vetAux;

    vetAux = (int*)malloc(tam * sizeof(int));


    while(com1 <= meio && com2 <= fim){

        if(vetor[com1] < vetor[com2]) {

            vetAux[comAux] = vetor[com1];

            com1++;

        } else {

            vetAux[comAux] = vetor[com2];

            com2++;

        }

        comAux++;

    }


    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade

        vetAux[comAux] = vetor[com1];

        comAux++;

        com1++;

    }


    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade

        vetAux[comAux] = vetor[com2];

        comAux++;

        com2++;

    }


    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original

        vetor[comAux] = vetAux[comAux-comeco];

    }

    

    free(vetAux);

}


void mergeSort(int vetor[], int comeco, int fim){

    if (comeco < fim) {

        int meio = (fim+comeco)/2;


        mergeSort(vetor, comeco, meio);

        mergeSort(vetor, meio+1, fim);

        merge(vetor, comeco, meio, fim);

    }

}

int main () {
    long int start, end;
    int* v;
    printf("InsertionSort: \n");
    v = inicializaVetorRandom();
    start = clock();
    insertionSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Random: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    v = inicializaVetorOrdenado();
    start = clock();
    insertionSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Ordenado: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    v = inicializaVetorInvertido();
    start = clock();
    insertionSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Invertido: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
       
   printf("BubbleSort\n");
   v = inicializaVetorRandom();
    start = clock();
    bubbleSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Random: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    v = inicializaVetorOrdenado();
    start = clock();
    bubbleSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Ordenado: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    v = inicializaVetorInvertido();
    start = clock();
    bubbleSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Invertido: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    
    printf("selectionSort\n");
     v = inicializaVetorRandom();
    start = clock();
    selectionSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Random: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    v = inicializaVetorOrdenado();
    start = clock();
    selectionSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Ordenado: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    v = inicializaVetorInvertido();
    start = clock();
    selectionSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
     f("\t Invertido: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    printf("QuickSort\n");
     v = inicializaVetorRandom();
    start = clock();
    quickSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Random: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    v = inicializaVetorOrdenado();
    start = clock();
    quickSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Ordenado: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    v = inicializaVetorInvertido();
    start = clock();
    quickSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Invertido: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    printf("mergeSort: \n");
    
    v = inicializaVetorRandom();
    start = clock();
    /*mergeSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Random: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));

    v = inicializaVetorOrdenado();
    start = clock();
    mergeSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Ordenado: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    v = inicializaVetorInvertido();
    start = clock();
    mergeSort(v, TAMANHO_VETOR);
    end = clock();
    free(v);
    printf("\t Invertido: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    printf("heap_sort")
    
    v = inicializaVetorRandom();
    start = clock();
    Heap_sort(v, MAX);
    end = clock();
    free(v);
    printf("\t Random: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));

    v = inicializaVetorOrdenado();
    start = clock();
    Heap_sort(v, MAX);
    end = clock();
    free(v);
    printf("\t Ordenado: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));
    
    v = inicializaVetorInvertido();
    start = clock();
    Heap_sort(v, MAX);
    end = clock();
    free(v);
    printf("\t Invertido: %ld milisegundos\n", (end - start) / (CLOCKS_PER_SEC / 1000));*/
       
       
    return 0;
}
