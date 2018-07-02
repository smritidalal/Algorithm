//WAP to implement Huffman Coding....................

#include<iostream.h>
#include<iomanip.h>
#include<math.h>
#include<conio.h>

int ct=0;
class node
{
public:
char C;
int freq;
node *left,*right;
node *par;
node(char ch=0,int f=0,node *l=0,node *r=0,node *p=0)
{
C=ch;
freq=f;
left=l;
right=r;
par=p;
}
};

class array
{
public:
int heapsize;
int size1;
int length;
node *b[20];
node *a[20];
node *root;
array()
{
root=0;
}
int left(int i)
{
return 2*i;
}
int right(int i)
{
return 2*i+1;
}

void insert();
void buildheap();
void minheapify(int i);
void inorder();
void inorder(node *);
void heap_insert(node *);
void decrease(int);
node* extractmin();
void minimum();
void huffmann();
void display();
void display1(node *);
};

void array::insert()
{
char c1;
cout<<"\n Enter length of array :";
cin>>length;
cout<<endl;
for(int i=1;i<=length;i++)
{
cout<<"\n Enter the element :";
a[i]=new node();
cin>>c1;
a[i]->C=c1;
cout<<"\n Enter the frequency of the element : ";
cin>>a[i]->freq;
b[i]=a[i];
cout<<endl;
}
buildheap();
heapsize=length;
}

void array::buildheap()
{
heapsize=length;
for(int i=(floor(length/2));i>=1;i--)
{
minheapify(i);
}
}

void array::minheapify(int i)
{
int l,r,smallest;
node *temp;
l=left(i);
r=right(i);
if(l<=heapsize && a[l]->freq <a[i]->freq)
{
smallest=l;
ct++;
}
else
{
smallest=i;
ct++;
}
if(r<=heapsize && a[r]->freq <a[smallest]->freq)
{
smallest=r;
ct++;
}
if(smallest!=i)
{
temp=a[i];
a[i]=a[smallest];
a[smallest]=temp;
minheapify(smallest);
}
}

void array::inorder()
{
inorder(root);
}

void array::inorder(node *x)
{
if(x!=0)
{
inorder(x->left);
cout<<x->freq<<" ";
inorder(x->right);
}
}

void array::heap_insert(node *k)
{
heapsize=heapsize+1;
a[heapsize]=k;
decrease(heapsize);
}

void array::minimum()
{
cout<<a[1];
}

node* array::extractmin()
{
node *min;
if(heapsize<1)
return 0;
min=a[1];
a[1]=a[heapsize];
heapsize=heapsize-1;
minheapify(1);
return min;
}
void array::decrease(int i)
{
node* temp;
int p=(floor(i/2));
while(i>1 && a[p]->freq >a[i]->freq)
{
temp=a[p];
a[p]=a[i];
a[i]=temp;
i=p;
}
}

void array::display()
{
for(int i=1;i<=length;i++)
{
cout<<endl<<"Huffman Code for :"<<b[i]->C<<" ";
display1(b[i]);
}
}

void array::display1(node *t)
{
if(t!=root)
{
if(t==t->par->left)
{
display1(t->par);
cout<<"0";
}
else
{
display1(t->par);
cout<<"1";
}
}
}

void array::huffmann()
{
for(int i=1;i<=length-1;i++)
{
node *z=new node();
node *x=extractmin();
node *y=extractmin();
x->par=z;
y->par=z;
z->left=x;
z->right=y;
z->freq=(x->freq)+(y->freq);
heap_insert(z);
}
root=extractmin();
}

void main()
{
clrscr();
char ch='y';
do
{
array o1;
o1.insert();
o1.huffmann();
cout<<" The original array is : "<<endl;
o1.display();
cout<<endl;
cout<<"\n The Inorder traversal is : "<<endl;
o1.inorder();
cout<<"\ndo u want to continue::";
cin>>ch;
}while(ch=='y');
getch();
}

