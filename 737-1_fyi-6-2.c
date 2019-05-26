 #include <stdio.h>
 #include <stdlib.h>

 void sorting_shella(int *arr, int size) {
    int i, j, step;
    int tmp;
    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; i++) {
             tmp = arr[i];
             for (j = i; j >= step; j -= step) {
                  if (tmp < arr[j - step])
                      arr[j] = arr[j - step];
                  else
                       break;
             }
             arr[j] = tmp;
         }
 }

 int main() {
    int n, i;

    scanf("%d", &n);

    int m[n];

    for(i=0; i<n; i++){
        scanf("%d", &m[i]);
    }
    sorting_shella(m, n);

    for (i = 0; i<n; i++){
 //       printf("%d ", m[i]);
    if (i == n-1) {
        printf("%d\n", m[i]);
    }
    else {
        printf("%d ", m[i]);
    }
 //   printf("\n");
    }
    return 0;
 }
