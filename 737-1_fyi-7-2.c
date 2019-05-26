 #include <stdio.h>
 #include <stdlib.h>

 void siftDown(int *num, int root, int size) {
    int maxChild;
    int done = 0;
    while ((root * 2 <= size) && (!done)) {
        if (root * 2 == size){
            maxChild = root * 2;
        }
        else if (num[root * 2] > num[root * 2 + 1]){
            maxChild = root * 2;
        } else {
            maxChild = root * 2 + 1;
        }
        if (num[root] < num[maxChild]) {
            int temp = num[root];
            num[root] = num[maxChild];
            num[maxChild] = temp;
            root = maxChild;
        }else
            done = 1;
    }
 }

 void sorting_piramid(int *num, int arr_size) {
    for (int i = (arr_size / 2) - 1; i >= 0; i--)
        siftDown(num, i, arr_size);
    for (int i = arr_size - 1; i >= 1; i--) {
        int temp = num[0];
        num[0] = num[i];
        num[i] = temp;
        siftDown(num, 0, i - 1);
    }
 }
 int main() {
    int n, i;

    scanf("%d", &n);

    int m[n];

    for(i=0; i<n; i++){
        scanf("%d", &m[i]);
    }
    sorting_piramid(m, n);

    for (i = 0; i<n; i++){
        printf("%d", m[i]);
        if(i != n-1) {
           printf(" ");
      }
    }
    printf("\n");
    return 0;
 }
