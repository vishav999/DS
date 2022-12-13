//linear search
#include <iostream>
using namespace std;

class Lsearch
{
public:
int n;
int *A;
 
 /*public: 
 	Lsearch(int size)
	 {
	 	 n=size;
	 	 
		 }	*/
		 
	void getdata()
		{
			cout<< " Enter the size of array "<< endl;
			cin>> n;
			
			
			 A = new int[n];
			 for(int i =0 ; i<n; i++)
			   {
			 	cout<< " Enter the elements of array " <<endl;
			 	cin>> A[i];
			   }
			 
		}
			 
			 void display( )
			 {
			 	
			 	cout <<" List :"<<endl;
			 	for(int i=0;i<n; i++)
			 	{
			 	
			 		cout<< A[i] << " ";
			 		
				 }
				 cout<<endl;
			 }
			
			int LinearSearch(int x)
            {
                cout<< " enter the element you want to search "<< endl;
                cin>>x;
                    
                for (int i = 0; i<n ;i++)
                {
                    if( A[i]==x)
                    {
                        return (i);
                    }
                }
                return -1;
            }
			 
			 	 
};

int main(){
	 Lsearch ls;
	 int x;
	 ls.getdata();
	 ls.display();
	 
	 x = ls.LinearSearch(x);
     cout << "Index: " << x;
	 
	 
	return 0;
}