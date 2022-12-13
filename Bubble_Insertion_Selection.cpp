#include<iostream>
using namespace std;

template<typename T>class sort{
    T*arr;
    int size;
    public:
    sort(int size=0){
        this->size=size;
        arr=new T[size];
        
    }
    void set(){
        cout<<"Enter the elements"<<endl;
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
    }
    void get(){
        cout<<"Elements of the array are :-"<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void bubblesort(){
        for(int i=0;i<size-1;i++){
            for(int j=0;j<size-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }

    void selectionsort(){
        
        for(int i=0;i<size-1;i++){
            int pos=i;
            int temp=arr[i];
            for(int j=i+1;j<size;j++){
                if(temp>arr[j]){
                   temp=arr[j];
                   pos=j;
                }
            }
            swap(arr[i],arr[pos]);
        }
    }
    void insertionsort(){
        for(int i=1;i<size;i++){
            int temp=arr[i];
            int j;
            for(j=i;j>0 && arr[j-1]>temp;j--){
                arr[j]=arr[j-1];
            }
            arr[j]=temp;
        }
    }
};
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    sort<int>ar(size);
    ar.set();
    ar.get();
    cout<<"select the sorting algorithm : "<<endl;
     cout<<"1. Bubble Sort "<<endl<<"2. Insertion Sort"<<endl<<"3.Selection Sort"<<endl;
     int n;
     cin>>n;
     switch(n){
        case 1:
        ar.bubblesort();
        break;
        case 2:
        ar.insertionsort();
        break;
        case 3:
        ar.selectionsort();
        break;
        default:
        cout<<"enter a correct choice!!"<<endl;
     }
     return 0;
}