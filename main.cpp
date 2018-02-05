#include <iostream>

using namespace std;


// Function to Merge Arrays L and R into A.
// lefCount = number of elements in L
// rightCount = number of elements in R.
void Merge(int *A , int *L,int leftCound, int *R,int rightCount){
    int i= 0 , j=0, k=0 ;
    // i - to mark the index of left aubarray (L)
    // j - to mark the index of right sub-raay (R)
    // k - to mark the index of merged subarray (A)

    while(i < leftCound && j <rightCount){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<leftCound)     A[k++] = L[i++];
    while (j<rightCount)    A[k++] = R[j++];

}

// Recursive function to sort an array of integers.
void MergeSort(int *A , int n){
    if(n < 2)
        return;
    int mid = n/2;
    // create left and right subarrays
    // mid elements (from index 0 till mid-1) should be part of left sub-array
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    int *L = new int [mid];
    int *R = new int [n-mid];

    for(int i=0;i<mid;i++)  L[i]= A[i];
    for(int i=mid;i<n;i++)  R[i-mid] = A[i];

    MergeSort(L,mid);   // sorting the left subarray
    MergeSort(R,n-mid); // sorting the Right subarray
    Merge(A,L,mid,R,n-mid);// Merging L and R into A as sorted list
    delete(L);
    delete(R);

}


int main() {

    int A[] = {6,2,3,1,9,10,15,13,12,17};
    int i,numberOfElements;

    numberOfElements = sizeof(A)/sizeof(A[0]);

    MergeSort(A,numberOfElements);

    for(i = 0;i < numberOfElements;i++) {
        cout<<A[i]<<" ";
    }

    return 0;
}