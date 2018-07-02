#include<iostream.h>
#include<conio.h>

class adjlistnode
{
   public:
   int key,d,f;
   adjlistnode *next, *p;
   char color;
   adjlistnode()
   {
     key=0;
     d=999;
     f=999;
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
   int time;
   public:
   graph(int x)
   {
      time=0;
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
   void DFS();
   void DFS_visit(adjlistnode *);
   void reflect_changes(adjlistnode *);
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

	  cout<<"\n\n Do u want to insert more edges :: ";
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
       temp->f=u->f;
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

void graph::DFS()
{
  for(int i=0;i<v;i++)
  {
     adjlistnode *u=a[i].head;
     u->color='W';
     u->p=0;
     reflect_changes(u);
  }
  for(int j=0;j<v;j++)
  {
     adjlistnode *u=a[j].head;
     if(u->color=='W')
     {
       DFS_visit(u);
     }
  }
}

void graph::DFS_visit(adjlistnode * u)
{
   for(int i=0;i<v;i++)
   {
     adjlistnode *temp=a[i].head;
     if(temp->key==u->key)
     {
       u=temp;
     }
   }
   time=time+1;
   u->d=time;
   u->color='G';
   reflect_changes(u);

   adjlistnode *s=u->next;
   while(s!=0)
   {
      if(s->color=='W')
      {
	 s->p=u;
	 reflect_changes(s);
	 DFS_visit(s);
      }
      s=s->next;
   }
   u->color='B';
   time=time+1;
   u->f=time;
   reflect_changes(u);
   cout<<"\n "<<u->key<<" :: Finish time = "<<u->f<<endl;

}

void main()
{
   clrscr();
   int v;
   cout<<"\n Enter the no. of vertices :: ";
   cin>>v;

   graph o1(v);
   o1.insert();
   o1.display();
   o1.DFS();
   getch();
}