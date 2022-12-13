#include<iostream>

using namespace std;	//required header

template<class T>	//method to print array with template
void printArr(T arr[],int s){
    for(int i=0;i<s;i++){
	cout << arr[i] << " " ;
    }
    cout << endl;
}

template<typename T>	//method to enter elements of array
void EnterArr(T arr[],int s){
    for(int i=0;i<s;i++){
    cout << "Enter element " << i+1 << " : ";
    cin >> arr[i];
    }
}

template<class T>
void BubbleSort(T arr[],int s){   //bubble sort function

    int i=0;
    bool swapped = false;
    for(;i<s-1;i++){                //loop
	swapped = false;
        for(int j=0;j<s-i-1;j++){   //loop
            if(arr[j]>arr[j+1]){    //swaping if next number is greater
                swap(arr[j],arr[j+1]);
		swapped = true;
            }
        }
	if(!swapped)	//if swapped i.e array is sorted, break loop
	    break;
    }
}

template<typename T>
void SelectionSort(T arr[],int s){	//Selection sort function

   for(int i=0;i<s;i++){		//Loop for all index
	int minN = i;			//initialize min number index with current index

	for(int j=i+1;j<s;j++){		//Loop to find smallest number after current index
	    if(arr[j]<arr[minN]){	//if smaller number is found in loop make it's index min
		minN = j;
	    }
	}
	swap(arr[minN],arr[i]);		//swap current index with smallest number found after it
   }
}

template<typename T>
void InsertionSort(T arr[],int s){	//function for insertion sort
    int i,j;			//declare variables i,j for loop and key for storing current num
    T key;

    for(i=1;i<s;i++){			//Loop from 2nd number
	j = i-1;			//check number backwards hence new loop starts from 1 back
	key = arr[i];			//store current number

	for(;j>=0 && arr[j]>key;j--){	//check if numbers before is more than current then shift those number forward
	    arr[j+1] = arr[j];
	}
	arr[j+1] = key;			//replace current number in last replaced position
    }
}


int main(){		//main driver func
    int *arr;		//declarations
    int size,c=0,pass=0;
SMENU:
    cout << "Enter size of array: ";	//size input
    cin >> size;

    arr = new int[size];		//dynamic memory allocation for array

    EnterArr(arr,size);
    cout << "Entered array: ";
    printArr(arr,size);
MENU:
    cout << "\nChoose Algorithm:\n\t 1. Bubble Sort  2. Selection Sort  3.Insertion Sort\n\t: ";
    cin >> c;
    if(c==1)
	BubbleSort(arr,size);
    else if (c==2)
	SelectionSort(arr,size);
    else if(c==3)
	InsertionSort(arr,size);
    else{
	cout << "\n\tWrong input.. try again..";
	goto MENU;
    }
    cout << "\nSorted Array : ";
    printArr(arr,size);
    cout << "\nNow What? 1. New Array 0. Exit\n\t:";
    cin >> c;
    if(c==1)
	goto SMENU;
    else{
	cout << "\n\tExiting...";
	return 0;
    }
}
