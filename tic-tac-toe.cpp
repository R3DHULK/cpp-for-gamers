#include<iostream>
#include<windows.h>
using namespace std;

class print;
class fill1;
class win1;
int flag=0;

class body
{
    protected:
	    char mat[5][11];
	public:		
	body()
	{
	    for(int i=0;i<5;i++)
	    {
	    	for(int j=0;j<11;j++)
	    	{
	    		if(i==1 || i==3)
	    			mat[i][j]='-';
	    		else if(j==3 || j==7)
	    			mat[i][j]='|';
	    		else
	    			mat[i][j]=' ';
			}
		}
	}
	friend class print;
	friend class fill1;
	friend class win1;
};

class fill1
{
	public:
	void filldat(body &ob11,int a,int b)
	{
		if(a==1)
		{
			if(b==1)
				ob11.mat[0][1]='0';
			if(b==2)
				ob11.mat[0][5]='0';
			if(b==3)
				ob11.mat[0][9]='0';
			if(b==4)
				ob11.mat[2][1]='0';
			if(b==5)
				ob11.mat[2][5]='0';
			if(b==6)
				ob11.mat[2][9]='0';
			if(b==7)
				ob11.mat[4][1]='0';
			if(b==8)
				ob11.mat[4][5]='0';
			if(b==9)
				ob11.mat[4][9]='0';
	    }
	    else if(a==2)
	    {
		    if(b==1)
				ob11.mat[0][1]='x';
			if(b==2)
				ob11.mat[0][5]='x';
			if(b==3)
				ob11.mat[0][9]='x';
			if(b==4)
				ob11.mat[2][1]='x';
			if(b==5)
				ob11.mat[2][5]='x';
			if(b==6)
				ob11.mat[2][9]='x';
			if(b==7)
				ob11.mat[4][1]='x';
			if(b==8)
				ob11.mat[4][5]='x';
			if(b==9)
				ob11.mat[4][9]='x';
		}
	}  	
};

class win1
{
	public:
	void check1(body &ob12)
	{
		if(ob12.mat[0][1]=='0' && ob12.mat[2][1]=='0')
		{
			if(ob12.mat[4][1]=='0')
			flag=1;
		}
		if(ob12.mat[0][1]=='0' && ob12.mat[0][5]=='0')
		{
			if(ob12.mat[0][9]=='0')
				flag=1;
		}
		if(ob12.mat[0][1]=='0' && ob12.mat[2][5]=='0')
		{
			if(ob12.mat[4][9]=='0')
				flag=1;
		}
		if(ob12.mat[0][5]=='0' && ob12.mat[2][5]=='0')
		{
			if(ob12.mat[4][5]=='0')
				flag=1;
		}
		if(ob12.mat[0][9]=='0' && ob12.mat[2][9]=='0')
		{
			if(ob12.mat[4][9]=='0')
				flag=1;
		}
		if(ob12.mat[0][9]=='0' && ob12.mat[2][5]=='0')
		{
			if(ob12.mat[4][1]=='0')
				flag=1;
		}
		if(ob12.mat[2][1]=='0' && ob12.mat[2][5]=='0')
		{
			if(ob12.mat[2][9]=='0')
				flag=1;
		}
		if(ob12.mat[4][1]=='0' && ob12.mat[4][5]=='0')
		{
			if(ob12.mat[4][9]=='0')
				flag=1;
		}
		
		//second player
		if(ob12.mat[0][1]=='x' && ob12.mat[2][1]=='x')
		{
			if(ob12.mat[4][1]=='x')
				flag=2;
		}
		if(ob12.mat[0][1]=='x' && ob12.mat[0][5]=='x')
		{
			if(ob12.mat[0][9]=='x')
				flag=2;
		}
		if(ob12.mat[0][1]=='x' && ob12.mat[2][5]=='x')
		{
			if(ob12.mat[4][9]=='x')
				flag=2;
		}
		if(ob12.mat[0][5]=='x' && ob12.mat[2][5]=='x')
		{
			if(ob12.mat[4][5]=='x')
				flag=2;
		}
		if(ob12.mat[0][9]=='x' && ob12.mat[2][9]=='x')
		{
			if(ob12.mat[4][9]=='x')
				flag=2;
		}
		if(ob12.mat[0][9]=='x' && ob12.mat[2][5]=='x')
		{
			if(ob12.mat[4][1]=='x')
				flag=2;
		}
		if(ob12.mat[2][1]=='x' && ob12.mat[2][5]=='x')
		{
			if(ob12.mat[2][9]=='x')
				flag=2;
		}
		if(ob12.mat[4][1]=='x' && ob12.mat[4][5]=='x')
		{
			if(ob12.mat[4][9]=='x')
				flag=2;
		}
	}
};

class print
{
	public:
	void printdata(body &ob10)
	{
		system("CLS");
		for(int i=0;i<5;i++)
	    {
	    	for(int j=0;j<11;j++)
	    	cout<<ob10.mat[i][j];
			cout<<endl;
		}		
	}
};

int main()
{
	start:
	int no1,no2;
	char choice;
	string name1,name2;
	body ob1;
	fill1 ob5;
	print ob4;
	win1 ob8;
	cout<<"PLAYER 1 ENTER YOUR NAME = ";
	cin>>name1;
	cout<<"PLAYER 2 ENTER YOUR NAME = ";
	cin>>name2;
	ob4.printdata(ob1);
	while(1)
	{
		cout<<"PLAYER "<<name1<<" ENTER CHOICE : ";
		cin>>no1;
		ob5.filldat(ob1,1,no1);
		ob4.printdata(ob1);
		ob8.check1(ob1);
		if(flag==1)
		{
			cout<<"PLAYER "<<name1<<" WON THE GAME"<<endl;
			cout<<"DO YOU WANT TO PLAY AGAIN(y/n) : ";
			cin>>choice;
			if(choice=='y')
				system("CLS");
			goto start;
			break;
		}
		if(flag==2)
		{
			cout<<"PLAYER "<<name2<<" WON THE GAME"<<endl;
			cout<<"DO YOU WANT TO PLAY AGAIN(y/n) : ";
			cin>>choice;
			if(choice=='y')
			{
				system("CLS");
				goto start;
		    }
		    else
		    	cout<<"GAME OVER";
			break;
		}
		cout<<"PLAYER "<<name2<<" ENTER CHOICE : ";
		cin>>no2;
		ob5.filldat(ob1,2,no2);
		ob4.printdata(ob1);
		ob8.check1(ob1);
		if(flag==1)
		{
			cout<<"PLAYER "<<name1<<" WON THE GAME"<<endl;
			cout<<"DO YOU WANT TO PLAY AGAIN(y/n) : ";
			cin>>choice;
			if(choice=='y')
				system("CLS");
			goto start;
			break;
		}
		if(flag==2)
		{
			cout<<"PLAYER "<<name2<<" WON THE GAME"<<endl;
			cout<<"DO YOU WANT TO PLAY AGAIN(y/n) : ";
			cin>>choice;
			if(choice=='y')
				system("CLS");
			goto start;
			break;
		}
	}
	return 0;
}
