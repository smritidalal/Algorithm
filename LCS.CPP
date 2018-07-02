//WAP to determine the Largest Common Subsequence(LCS) of two given sequences.............

#include<iostream.h>
#include<conio.h>


class LCS
{
      int c[20][20];
      char b[20][20];
      int row,col;

      public:
      LCS(int r=0,int c=0);

      void get_input();
      void LCS_length(char* x,char* y,int m,int n);
      void print_LCS(char* x,int i,int j);

};


LCS::LCS(int r,int c)
{
     int i;
     row=r;
     col=c;
}



void LCS::get_input()
{
     int m,n,i;
     char* x;
     char* y;

     cout<<"Enter the size of first sequence :: ";
     cin>>m;

     if(m!=0)
     {
	 x=new char[m];

	 cout<<"\n\nNow,enter the elements for the first sequence :: ";
	 for(i=1;i<=m;i++)
	 cin>>x[i];


	 cout<<"\n\n\nEnter the size of second sequence :: ";
	 cin>>n;


	 if(n!=0)
	 {
	      y=new char[n];

	      cout<<"\n\nNow,enter the elements for the second sequence :: ";
	      for(i=1;i<=n;i++)
	      cin>>y[i];


		   LCS_length(x,y,m,n);


			cout<<"\n\n\nThe LCS of the two given sequences is :: \n\t";
			print_LCS(x,m,n);

	 }
      else
	 {
	     cout<<"\n\n\t               !!!!!!!!ERROR!!!!!!!!!!";
	     cout<<"\n\n\t...........You have entered an empty sequence..........";
	 }
     }
  else
     {
	 cout<<"\n\n\t               !!!!!!!!ERROR!!!!!!!!!!";
	 cout<<"\n\n\t...........You have entered an empty sequence..........";
     }

}


void LCS::LCS_length(char* x,char* y,int m,int n)
{
      int i,j;

      row=m;
      col=n;


	     for(i=1;i<=m;i++)
	     c[i][0]=0;

	     for(j=0;j<=n;j++)
	     c[0][j]=0;

	     for(i=1;i<=m;i++)
	     {
		 for(j=1;j<=n;j++)
		 {
		     if(x[i]==y[j])
		     {
			c[i][j]=c[i-1][j-1]+1;
			b[i][j]='/';
		     }
		  else
		     if(c[i-1][j]>=c[i][j-1])
		     {
			c[i][j]=c[i-1][j];
			b[i][j]='|';
		     }
		  else
		     {
			c[i][j]=c[i][j-1];
			b[i][j]='-';
		     }
		 }
	     }

}



void LCS::print_LCS(char* x,int i,int j)
{
     if(i==0||j==0)
     return;

     if(b[i][j]=='/')
     {
	 print_LCS(x,i-1,j-1);
	 cout<<x[i]<<"  ";
     }
  else
     if(b[i][j]=='|')
     print_LCS(x,i-1,j);
  else
     print_LCS(x,i,j-1);
}


void main()
{
     clrscr();

     LCS l1;
     char ch='y';

     cout<<"\n\t\t  <<<<<<<<<<<<<<<<<LARGEST COMMON SUBSEQUENCE>>>>>>>>>>>>>>>>>>>>";

     do
     {
	 l1.get_input();

	    cout<<"\n\nTo continue,press y otherwise no :: ";
	    cin>>ch;

      }while(ch=='y'||ch=='Y');



     getch();
}