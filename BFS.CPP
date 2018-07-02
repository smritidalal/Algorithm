#include<iostream.h>
#include<conio.h>


class adjlistnode
{
   public:
   int key,d;
   adjlistnode *next, *p;
   char color;
   adjlistnode()
   {
     key=0;
     d=999;
     p=0;
     next=0;
     color='W';

   }
};

class adjlist
{
   public:
   adjlistnode *head;
   adjlist()
   {
     head=0;
   }
   void addtotail(int);
};


class node
{
	public:
		adjlistnode* info;
		node *nxt;
		node()
		{

			info=0;
			nxt=0;
		}
};


class queue
{
	node *front ,*rear;
  int top;
	public:
		queue()
		{
			top=-1;
			front=rear=0;
		}
		int isempty();
		void enqueue(adjlistnode *);
		adjlistnode * dequeue();
		void display();

};

int queue::isempty()
{
	if(front==0)
		return 1;
	else
		return 0;
}

void queue::enqueue(adjlistnode *x)
{
       node *temp=new node();
       temp->info=x;
	if(isempty())
	{
		rear=front=temp;
	}
	else
	{
		rear->nxt=temp;
		rear=temp;
	}
}

adjlistnode * queue::dequeue()
{
	node *temp;
	adjlistnode *x=front->info;
	if(front==rear)
	{
		delete front;
		front=rear=0;
	}
	else
	{
		temp=front;
		front=front->nxt;
		delete temp;
	}
	return x;
}


void adjlist::addtotail(int x)
{
     adjlistnode *temp=new adjlistnode();
     temp->key=x;
     adjlistnode *temp1=head;
     while(temp1->next!=0)
     {
	temp1=temp1->next;
     }
    temp1->next=temp;
    temp->p=head;
}

class graph
{
   int v;
   adjlist *a;
   public:
   graph(int x)
   {
      v=x;
      a=new adjlist[v];
       for (int i=0;i<v;++i)
			{

		a[i].head = new adjlistnode();
				a[i].head->key=i+1;
			}
  }
   void insert();
   void display();
   adjlistnode * search(int);
   void reflect_changes(adjlistnode *);
   void BFS(int);
   void print_path(int ,int);
   void print_path_recur(adjlistnode *,adjlistnode *);
};

void graph::insert()
{
    int z,x;
    char ch,ch1;

    for(int i=0;i<v;i++)
    {
       adjlistnode *temp=a[i].head;
       cout<<"\n Do u want to enter the edge of "<<temp->key<<" :: ";
       cin>>ch1;
       while(ch1=='Y' || ch1=='y')
       {
	 do
	 {
	  cout<<"\n Enter the edge of "<<temp->key<<" :: ";
	  cin>>x;
	  a[i].addtotail(x);

	  cout<<"\n Do u want to insert more edges :: ";
	  cin>>ch;
	 } while(ch=='Y' || ch=='y');
	 ch1='n';
       }
    }

}

void graph::reflect_changes(adjlistnode *u)
{
  for(int i=0;i<v;i++)
  {
    adjlistnode *temp=a[i].head;
    while(temp!=0)
    {
      if(temp->key==u->key)
      {
       temp->color=u->color;
       temp->d=u->d;
       temp->p=u->p;
      }
      temp=temp->next;
    }
  }
}

void graph::display()
{
    adjlistnode *temp;
    for(int i=0;i<v;i++)
    {
      cout<<"\n\n Vertex "<<a[i].head->key<<" : ";
      temp=a[i].head;
      while(temp->next!=0)
      {
	cout<<temp->key<<"->";
		  temp=temp->next;
      }
      cout<<temp->key<<endl;
    }
}

adjlistnode* graph::search(int x)
{
  for(int i=0;i<v;i++)
   {
     adjlistnode *temp=a[i].head;
     if(temp->key==x)
       return temp;
   }

}

void graph::BFS(int x)
{
  adjlistnode *u;
  adjlistnode *s=search(x);
  for(int i=0;i<v;i++)
  {
    u=a[i].head;
    while(u!=0)
    {
      u->color='W';
      u->d=999;
      u->p=0;
      u=u->next;
    }
  }
  s->color='G';
  s->d=0;
  s->p=0;
  reflect_changes(s);
  queue Q;
  Q.enqueue(s);
  while(!Q.isempty())
  {
    adjlistnode *temp=Q.dequeue();
    u=search(temp->key);
    adjlistnode *r=u->next;
    while(r!=0)
    {
      if(r->color=='W')
      {
	r->color='G';
	r->d=u->d+1;
	r->p=u;
	reflect_changes(r);
	Q.enqueue(r);
      }
      r=r->next;
    }
    u->color='B';
    reflect_changes(u);
  }
}

void graph::print_path(int x,int y)
{
  adjlistnode *s=search(x);
  adjlistnode *u=search(y);
  print_path_recur(s,u);
}

void graph::print_path_recur(adjlistnode *s,adjlistnode *u)
{
   if(s->key==u->key)
   {
     cout<<" "<<s->key;
   }
   else if(u->p==0)
   {
     cout<<"\n No path from "<<s->key<<" to "<<u->key<<" exists...";
   }
   else
   {
     print_path_recur(s,u->p);
     cout<<"->"<<u->key;
   }
}

void main()
{
   clrscr();
   int v,x,y,z;
   char ch,ch1;
   cout<<"\n Enter the no. of vertices :: ";
   cin>>v;

   graph o1(v);
   o1.insert();
   o1.display();
   cout<<"\n Enter the source vertex:: ";
   cin>>z;
   o1.BFS(z);
   o1.display();
   cout<<"\n Do u want to know the path... ";
   cin>>ch;
   if(ch=='y' || ch=='Y')
   {
     do
     {
       cout<<"\n Enter the starting vertex:: ";
       cin>>x;
       cout<<"\n Enter the end vertex:: ";
       cin>>y;
       o1.print_path(x,y);
       cout<<"\n Do u want to continue...";
       cin>>ch1;
     } while(ch1=='y' || ch1=='Y');
   }

   getch();
}