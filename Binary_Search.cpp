//Given a list of N elements, which is sorted in ascending order, you are required to search an element x in the list. The list is stored using array data structure. 
//If the search is successful, the output should be the index at which the element occurs, otherwise returns -1 to indicate that the element is not present in the list.
//Assume that the elements of the list are all distinct. Write a program to perform the desired task

#include<iostream>

using namespace std;

template<typename T>
int bin_search(T arr[],int n,T x){
    int mid=n/2,low=0,high=n-1;

    while(high>=low){
	mid = (high+low)/2;
	if(arr[mid]==x)
	    return mid;
	else if(arr[mid]>x)
	    high = mid-1;
	else
	    low = mid+1;
	}
    return -1;
}

int main(){
    int *arr;
    int n;
    int x;
    cout << "Enter size: ";
    cin >> n;
    arr = new int[n];
    cout << "Enter sorted array--" << endl;
    for(int i=0;i<n;i++){
	cout << "Enter element " << i+1 << ": ";
	cin >> arr[i];
    }
    cout << "Enter element you want to search: " ;
    cin >> x;
    int index = bin_search(arr,n,x);
    string s = index==-1 ? "Not Found!!" : "Found at index " ;
    cout << s << ": " << index << endl;
    return 0;
}
