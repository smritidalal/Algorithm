//TO IMPLEMENT RADIX SORT

#include<iostream>
using namespace std;

class node
{
 
public:
	int info;
	node *next;
    node(int p)
	{
		info=p;
		next=NULL;
	}
};

class list
{
	node *head, *tail;

public:

	list()
	{
		head=tail=NULL;
	}

	void insertintohead(int p)
	{
		node *n=new node(p);

		if(head==NULL)
		{
			head=tail=n;
		}
		else
		{
			tail->next=n;
			tail=n;
		}
	}

	int deletefromhead()
	{
		int x=head->info;
		node* temp;

		if(head==tail)
		{
			delete head;
			head=NULL;
		}
		else
		{
			temp=head;
			head=head->next;
			delete temp;
		}

		return x;
	}

	int listempty()
	{
		if(head==NULL)
			return 1;
		else
			return 0;
	}

	void disp();
	
};

void list::disp()
{
	node*temp;
	for(temp=head;temp!=NULL;temp=temp->next)
			cout<<temp->info<<" ";
}

class rsort
{
	int arr[50];
	int size;

public:

	rsort()
	{
		size =0;
	}

	void input();
	void radix_sort();
	void display();
	int nod();

};

void rsort::radix_sort()
{
	list bucket[10];
	int x,y, i,j,k;

	for(j=0;j<nod();j++)
	{
		for(i=0;i<size;i++)
		{
			y=arr[i];
			for(k=0;k<j;k++)
			{
				y=y/10;
			}
			x=y%10;
			bucket[x].insertintohead(arr[i]);
		}

		k=0;
		for(i=0;i<10;)
		{ if(!bucket[i].listempty())
		
			{
				x=bucket[i].deletefromhead();

				arr[k]=x;
				k++;
			}
			else
				i++;
		}

	

	}
}

void rsort::input()
{	
	int i;

	cout<<"\n Enter the number of elements =";
	cin>>size;

	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}
}

void rsort::display()
{

	int i;

	for(i=0;i<size;i++)
	{
		cout<<"  "<<arr[i];
	}
}

int rsort::nod()
{
	int i=0,x;
	x=arr[0];
	while(x!=0)
	{
		x/=10;
		i++;
	}

	return i;
}

void main()
{
	rsort O1;

	int op;
	char ch;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. INPUT";
		cout<<"\n 2. SORT";
		cout<<"\n 3. DISPLAY:";
		cout<<"\n Enter your choice=";
		cin>>op;

		switch(op)
		{
		case 1: cout<<"\n INPUT";
			    O1.input();
				break;
		case 2: cout<<"\n SORTED ARRAY....";
			    O1.radix_sort();
	            O1.display();
				break;
		case 3: cout<<"\n DISPLAY....";
			    O1.display();
		}


		cout<<"\n Do you want to continue?";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');
}



