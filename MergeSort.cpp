#include<iostream>
using namespace std;

void merge(int A[],int left,int mid,int right)
{
    // BUG FIX: Changed parameter order from (left,right,mid) to (left,mid,right)
    // The function was being called with (left,mid,right) but defined as (left,right,mid)
    // This caused parameters to be swapped, resulting in wrong partition calculations
    int n1= mid-left+1;
    int n2= right-mid;

    int L[n1], R[n2];

    for(int i=0;i<n1;i++)
    {
        // BUG FIX: Changed from A[left+1] to A[left+i]
        // Was copying the same element repeatedly instead of populating the left array correctly
        L[i]= A[left+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i]= A[mid+1+i];
    }

    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        // BUG FIX: Changed from R[i] to R[j]
        // Was comparing L[i] with R[i] instead of comparing L[i] with R[j]
        if(L[i]<=R[j]){
            A[k]=L[i];
            k++,i++;
        }
        else{
            A[k]=R[j];
            k++,j++;
        }
    }
    
    // Copy remaining elements from left array
    while(i<n1){
        A[k]=L[i];
        k++,i++;
    }
    
    // Copy remaining elements from right array
    while(j<n2){
        A[k]=R[j];
        k++,j++;
    }

}

void mergeSort(int A[],int left,int right)
{
    if(left>=right) return;
    
    int mid= left+(right-left)/2;

    mergeSort(A,left,mid);
    mergeSort(A,mid+1,right);
    // BUG FIX: Removed extra recursive call - third mergeSort call was incorrect
    // mergeSort(A,left,right);  // This caused infinite recursion

    merge(A,left,mid,right);
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    mergeSort(arr, 0, n-1);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}