#include <stdio.h>

void sorting_hoar(int* m, int first, int last) {

    int i = first, j = last;
    double tmp, x = m[(first + last) / 2];

    do {
        while (m[i] < x)
            i++;  
        while (m[j] > x)
            j--;

        if (i <= j) {
            if (i < j) {
                tmp=m[i];
                m[i]=m[j];
                m[j]=tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        sorting_hoar(m, i, last);
    if (first < j)
        sorting_hoar(m, first,j);
 }

 int main() {
    int n, i;

    scanf("%d", &n);

    int m[n];

    for(i=0; i<n; i++) {
        scanf("%d", &m[i]);
    }

    sorting_hoar(m,0,n-1);

    for(i=0; i<n; i++){
        printf("%d", m[i]);
	if (i != n-1) {
	    printf(" ");
	}
    }
   printf("\n");
   return 0;
 }
 
