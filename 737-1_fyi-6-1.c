 #include <stdio.h>
 #include <stdlib.h>

 void sorting_brush(int *arr, int size) {
    if (arr && size) {
        int jump = size;
        int i;
        int change = 1;
        while (jump > 1 || change) {
            if (jump > 1)
                jump /= 1.24733;
            change = 0;
            for (i = 0; i + jump < size; ++i)
                if (arr[i + jump] < arr[i]) {
                    int tmp;
                    tmp = arr[i];
                    arr[i] = arr[i + jump];
                    arr[i + jump] = tmp;
                    change = 1;
                }
        }
    }
 }

 int main() {
    int n, i;

    scanf("%d", &n);

    int m[n];

    for(i=0; i<n; i++) {
        scanf("%d", &m[i]);
    }
    sorting_brush(m, n);

    for (i = 0; i<n; i++) {
  //      printf("%d", m[i]);
    if (i == n-1) {
        printf("%d\n", m[i]);
    }
   else {
         printf("%d ", m[i]);
    }
   // printf("\n");
    } 
    return 0;
 }

