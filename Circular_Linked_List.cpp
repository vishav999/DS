/*
Write a program to implement circularlinked list which supports the following operations:
1. Insert an element x at the beginning of the circular linked list
2. Insert an element x at position in the circular linked list
3. Insert an element at the end of the linked list
4. Insert an element at its correct sorted order
5. Remove an element from the beginning of the circular linked list
6. Remove an element from position in the circular linked list
7. Remove an element from the end of the circular linked list
8. Search for an element x in the circular linked list and return its pointer
9. Concatenate two circular linked lists 
10. Merge two circular linked lists
11. Sort the linked list
12. Reverse the linked list
13. Display the elements of circular linked list
*/
#include<iostream>
using namespace std;

template<class T>
class CNode
{
	public:
		T data;
		CNode* next;
		CNode()
		{
			data=0;
			next=NULL;
		}
		CNode(T d, CNode* ptr)
		{
			data=d;
			next=ptr;
		}	
};

template<class T>
class CircularLinkedList
{
	CNode<T>*cursor;
	public:
		CircularLinkedList()
		{
			cursor=NULL;
		}
		~CircularLinkedList()
		{
			while(!isEmpty())
				removeFront();
		}
		void removeFront()
		{
			if(isEmpty())
				cout<<"The list is empty"<<endl;
			else
			{
				CNode<T>* old=cursor->next;
				if(old==cursor)
					cursor=NULL;
				else
					cursor->next=old->next;
				delete old;
			}
		}
		void removeBack()
		{
			CNode<T>* temp=cursor;
			if(isEmpty())
				cout<<"The list is empty"<<endl;
			else if(cursor->next==temp)
			{		
				{
					delete temp;
					cursor=NULL;
				}
			}
			else
			{
				
				while(cursor->next!=temp)
				{
				advanceCursor();
				}
				cursor->next=temp->next;
				delete temp;
			}
		}
		void removeX(int x)
		{
			if(isEmpty())
				cout<<"The list is empty"<<endl;
			else
			{
				CNode<T>* p=cursor->next;
				do
				{
					
					if(p->next->data==x && p->next!=cursor)
					{
						p->next=p->next->next;
						delete p->next->next;
						
					}
					else if(p->next->data==x && p->next==cursor)
					{
						CNode<T>*temp=cursor;
						cursor=p;
						cursor->next=temp->next;
						delete temp;					
					}
					p=p->next;
				}while(p!=cursor->next);
				if(p->data==x && p->next==cursor)
				{
					delete p;
					cursor=NULL;
				}
		}
		}
		CNode<T>* searchX(T& x)
		{
			if(isEmpty())
			{
				cout<<"The list is empty"<<endl;
			}
			CNode<T>* p=cursor->next;
			do
			{
				if(p->data==x)
				{
					return p;
				}
				p=p->next;				
			}while(p!=cursor->next);
			if(p==cursor->next)
			{
				return NULL;
			}
			return NULL;
		}
		bool isEmpty() const
		{
			return (cursor==NULL);			
		}
		const T& front()
		{
			if(isEmpty())
				cout<<"empty"<<endl;
			else
				return (cursor->next->data);
		}
		const T& back()
		{
				if(isEmpty())
					return -1;
				else
				return (cursor->data);					
		}
		void advanceCursor()	
		{
			cursor=cursor->next;
		}
		void addFront(const T& d)
		{
			CNode<T>* v=new CNode<T>();
			v->data=d;
			if(isEmpty())
			{
				v->next = v;
				cursor = v; 
			}
			else
			{
				v->next = cursor->next;
				cursor->next = v;

			}
		}
		void addBack(const T& d)
		{
			CNode<T>*v=new CNode<T>();
			v->data=d;
			if(isEmpty())
			{
				v->next = v;
				cursor = v; 
			}
			else
			{
				CNode<T>*temp=cursor->next;
				cursor->next=v;
				v->next=temp;
				advanceCursor();
			}			
		}
		void addXatY(T& x, T& y)
		{
			if(isEmpty())
			{
				cout<<"The list is empty"<<endl;
			}
			else
			{
				CNode<T>*v=cursor->next;
				do
				{
					if(v->data==y)
					{
						CNode <T>* temp=new CNode<T>(x,v->next);
						v->next=temp;
						if(v==cursor)
						{
							cursor=v->next;
						}
					}
					v=v->next;
				}while(v!=cursor->next);
			}
		}
		void addXatPos(T& x, int y)
		{
			if (isEmpty())
			{
				cout<<"The list is empty"<<endl;
			}
			else
			{
				CNode<T>*v=cursor->next;
				int index = 0;
				do
				{
					if(index==y)
					{
						CNode <T>* temp=new CNode<T>(x,v->next);
						v->next=temp;
						if(v==cursor)
						{
							cursor=v->next;
						}
					}
					v=v->next;
					index++;
				}while(v!=cursor->next);
			}
		}
		void addOrdered(T el)
		{
			CNode<T> *current = cursor->next;
			CNode<T> *new_node = new CNode<T>();
			new_node->data = el;
			if (current == NULL) 
			{ 
				new_node->next = new_node; 
				cursor->next = new_node; 
			}
			
			else if (current->data >= new_node->data) 
			{
				addFront(el); 
			} 
			
			else
			{ 
				while (current!= cursor->next && current->next->data < new_node->data)
				{
					current = current->next;
				} 
				new_node->next = current->next; 
				current->next = new_node; 
			} 
		}
		void sort()
		{
			CNode<T> *current= cursor->next;
			CNode<T> *temp = NULL;

			int value;
			if (cursor == NULL) 
			{
				cout<<"Your list is empty";
			}
			else
			{
				while (current->next != cursor->next)
				{
					temp = current->next;
					while (temp != cursor->next)
					{
						if (current->data > temp->data)
						{
							value = current->data;
							current->data = temp->data;
							temp->data = value;
						}
						temp = temp->next;
					}
					current = current->next;
				}
			}
			
		}
		void display()
		{
			if(isEmpty())
			{
				cout<<"The list is empty"<<endl;
			}
			else
			{
				CNode<T>*temp=cursor->next;
				cout<<"The circular linked list is: "<<endl;
				do
				{
					cout<<temp->data<<" ";
					temp=temp->next;
				}while(temp!=cursor->next);
			}
		}
		friend void concatenateCl(CircularLinkedList &C, CircularLinkedList &C1)
		{
			if(C.getCursor()==NULL && C1.getCursor()!=NULL)
			{
				C.cursor=C1.cursor;
				C1.cursor=NULL;					
			}
			else if(C.getCursor()!=NULL && C1.getCursor()!=NULL)
			{
				//C1.display();
				CNode<T>* temp=C.cursor->next;
				C.cursor->next=C1.cursor->next;
				C1.cursor->next=temp;
				C.cursor=C1.cursor;
				C1.cursor=NULL;
				//C.display();
				
			}
		}	
		CNode<T>* getCursorNext()
		{
			return cursor->next;
		}
		CNode<T>* getCursor()
		{
			return cursor;
		}
};
template<class T>
void mainMenu(CircularLinkedList<T>C, int datatype)
{
	char ch;
	do
	{
		ch='y';
		int choice;
		cout<<"---------------- MAIN MENU ----------------"<<endl;
		cout<<"1. Insert an element x at the front of the circularly linked list  "<<endl;
		cout<<"2. Insert an element x after an element y in the circularly linked list "<<endl;
		cout<<"3. Insert an element x at position y in the circularly linked list "<<endl;
		cout<<"4. Insert an element x at the back of the circularly linked list  "<<endl;
		cout<<"5. Insert an element x in sorted order in the circularly linked list "<<endl;
		cout<<"6. Remove an element from the front of the circularly linked list"<<endl;
		cout<<"7. Remove the element x from the circularly linked list "<<endl;
		cout<<"8. Remove an element from the back of the circularly linked list"<<endl;
		cout<<"9. Search for an element x in the circularly linked list and return its pointer"<<endl;
		cout<<"10. Concatenate two circularly linked lists"<<endl;
		cout<<"11. Sort the circular linked list"<<endl;
		cout<<"12. Display the circular linked list"<<endl;
		cout<<"Enter your choice (1-9)"<<endl;
		cin>>choice;
		if(choice==1)
		{
			T el;
			cout<<"Enter an element"<<endl;
			cin>>el; 
			C.addFront(el);
		}
		else if(choice==2)
		{
			T x,y;		
			cout<<"Enter an element which you wish to insert"<<endl;
			cin>>x;
			cout<<"Enter the element after which you wish to insert "<<x<<endl;
			cin>>y;
			C.addXatY(x,y);			
		}
		else if(choice==3)
		{
			T x;
			int y;		
			cout<<"Enter an element which you wish to insert"<<endl;
			cin>>x;
			cout<<"Enter the position at which you wish to insert "<<x<<endl;
			cin>>y;
			C.addXatPos(x,y);
		}
		else if(choice==4)
		{
			T x;	
			cout<<"Enter an element which you wish to insert"<<endl;
			cin>>x;		
			C.addBack(x);		
		}
		else if(choice==5)
		{
			T el;
			cout<<"Enter an element"<<endl;
			cin>>el; 
			C.addOrdered(el);
		}
		else if(choice==6)
		{
			C.removeFront();
		}
		else if(choice==7)
		{
			T x;
			cout<<"Enter an element which you wish to delete"<<endl;
			cin>>x;
			C.removeX(x);
		}
		else if(choice==8)
		{
			C.removeBack();
		}
		else if(choice==9)
		{
			CNode<T>*found;
			T x;
			cout<<"Enter an element you wish to search"<<endl;
			cin>>x;
			found=C.searchX(x);
			if(found!=NULL)
				cout<<"element found in the list"<<endl;
			else if(found==NULL)
				cout<<"element not found in the list"<<endl;
		}
		else if(choice==10)
		{
			CircularLinkedList<T>C1;
			//adding values in second list
			C1.addFront(5);
			C1.addFront(4);
			C1.addFront(3);
			concatenateCl(C,C1);		
		}
		else if(choice==11)
		{
			//Sort
			C.sort();
			cout<<"Sorted Linked List\n";
			C.display();
		}
		else if(choice==12)
		{
			C.display();
		}
		cout<<endl<<"Do you wish to continue ?"<<endl;
		cin>>ch;
		cout<<endl;
		cout<<"-----------------------------------------"<<endl;
		if(ch=='y' || ch=='Y')
			continue;
		else
			exit(0);
    }while(ch=='y' || ch=='Y');
}

int main()
{
	int datatype;
	cout<<"What is the datatype of your linkedlist ? "<<endl;
	cout<<"1. int"<<endl;
	cout<<"2. float/double "<<endl;
	cout<<"3. char"<<endl;
	cout<<"4. string"<<endl;
	cin>>datatype;
	if(datatype==1)
	{
		CircularLinkedList<int>C1;
		mainMenu(C1,datatype);
	}
	else if(datatype==2)
	{
		CircularLinkedList<double>C2;
		mainMenu(C2,datatype);
	}
	else if(datatype==3)
	{
		CircularLinkedList<char>C3;
		mainMenu(C3,datatype);
	}
	else if(datatype==4)
	{
		CircularLinkedList<int>C4;
		mainMenu(C4,datatype);
		
	}
}
