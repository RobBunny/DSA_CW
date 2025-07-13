#include <iostream>
using namespace std;

void merge(int arr[], int l, int r) {
    int mid = (l+r)/2;
    int a = mid-l+1;
    int b = r-mid;
    int k = l;

    int first[a], second[b];
    for(int i=0; i<a; i++) first[i] = arr[k++];
    for(int i=0; i<b; i++) second[i] = arr[k++];

    int i=0;
    int j=0;
    k=l;

    while(i<a && j<b) {
        if(first[i] <= second[j]) {
            arr[k++] = first[i++];
        } else {
            arr[k++] = second[j++];
        }
    }
    while(i<a) arr[k++] = first[i++];
    while(j<b) arr[k++] = second[j++];
}

void mergesort(int arr[], int l, int r) {
    if(l==r) return;
    int mid = (l+r)/2;
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    merge(arr, l, r);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    mergesort(arr, 0, n-1);
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}