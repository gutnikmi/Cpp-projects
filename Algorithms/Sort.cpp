#include <iostream>
#include "../Headers/Sort.h"
using namespace std;



void Sort(int A[], int p, int r)
{
    int q;
    if (p < r){

        q=(p+r)/2;
        Sort(A, p, q);
        Sort(A, q+1, r);
        merge(A,p,r,q);
    }
}

void merge(int A[],int p, int r, int q)
{
    int mergedList[8];
    int i, j, k;
    i = p;
    k = p;
    j = q + 1;

    while (i <= q && j <= r) {
        if (A[i] < A[j]) {
            mergedList[k] = A[i];
            k++;
            i++;
        }
        else {
            mergedList[k] = A[j];
            k++;
            j++;
        }
    }

    while (i <= q) {
        mergedList[k] = A[i];
        k++;
        i++;
    }

    while (j <= r) {
        mergedList[k] = A[j];
        k++;
        j++;
    }

    for (i = p; i < k; i++) {
        A[i] = mergedList[i];
    }
}

int test_merge_sort()
{
    int A[8]={5,2,4,6,1,3,2,6};
    int length = (sizeof(A)/sizeof(*A));
    cout<<"Input array ...\n";
    for (int i = 0; i < 8; i++)
    {
        cout<<A[i]<<" ";
    }
    Sort(A, 0, length-1);
    cout<<"\n\nSorted array ... \n";
    for (int i = 0; i < 8; i++)
    {
        cout<<A[i]<<" ";
    }
}
