#include <stdio.h>

int arraySize(FILE *in) {
    int size;
    
    fscanf(in, "%d", &size);
    return size;
}

void arrayScan(FILE *in, int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        fscanf(in, "%d", &array[i]);
    }
}

void merge(int array[], int lo, int mid, int hi, int size) {
    int newarray[size];
    int i = lo;
    int m = mid + 1;
    int k = 0;
    int j = lo;
   
    
    for ( ; j <= mid && m <= hi; ) {
        if ( array[j] <= array[m] ) {
            newarray[i] = array[j];
            j += 1;
        } else {
            newarray[i] = array[m];
            k += 1;
        }
        i += 1;
    }

    if ( j > mid ) {
        for ( k = m; k <= hi; i++, k++ ) {
            newarray[i] = array[k];
        }
    } else {
        for ( k = j; k <= mid; i++, k++ ) {
            newarray[i] = array[k];
        }
    }

    for ( int k = lo; k <= hi; k++ ) {
        array[k] = newarray[k];
    }
}

void margeSort(int array[], int lo, int hi, int size) {
    int mid;
        printf("%d, %d\n", lo, hi);
    if ( lo < hi ) {
        mid = (lo + hi) / 2;
        margeSort(array, lo, mid, size);
        margeSort(array, mid+1, hi, size);
        merge(array, lo, mid, hi, size);
    }
}

void arrayPrint(FILE *out, int array[], int size) {
    for ( int i = 1; i < size; i++ ) {
        fprintf(out, "%d ", array[i-1]);
    }
    fprintf(out, "%d\n", array[size-1]);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = arraySize(in);
    int array[size];
    int len = size - 1;
    
    arrayScan(in, array, size);
//    arrayPrint(out, array, size);
    margeSort(array, 0, len, size);
    
    arrayPrint(out, array, size);
    return 0;
}

/*int main() {
    int len;
    int array[MAX];
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    fscanf(in, "%d", &len);
    
    for ( int i = 0; i < len; i++ ) {
        fscanf(in, "%d ", &array[i]);
    }
    
    len -= 1;
    partition(array, 0, len);
    
    for ( int i = 0; i < len; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[len]);
    
    return 0;
}*/
