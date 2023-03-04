#include <iostream>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <vector>

using namespace std;

bool gameOver;
string name;
const int width = 22;
const int height = 22;
char mat [width][height];
char fo[4]={'A','M','P','O'};
enum eDirection{ STOP = 0, LEFT,RIGHT,UP,DOWN};
eDirection dir;
class board;
int score;

void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void intial() 
{
	const int width=25;
	const int height=35;
	for(int i=0;i<height+2;i++)
	{
		gotoxy(i,0);
		cout<<'*';
	}
	for(int i=0;i<width+2;i++)
	{
		gotoxy(height+2,i);
		cout<<'*';
	}
	for(int i=0;i<height+2;i++)
	{
		gotoxy(i,width+2);
		cout<<'*';
	}
	for(int i=0;i<width+2;i++)
	{
		gotoxy(0,i);
		cout<<'*';
	}
}

void load()
{
    int row,col,r,c,q;
    gotoxy(16,10);
    printf("loading...");
    gotoxy(10,11);
    for(r=1;r<=20;r++)
	{
    	Sleep(200);			//to display the character slowly
    	printf("%c",177);
	}
    getch();
}

class food
{
	public:
		int frutiX,frutiY,fn=0;
		char fv=0;
		food(){}
		food(int y)
		{
			frutiX=rand()%width;
			frutiY=rand()%height;
			fn=rand()%4;
			fv=fo[fn];
		}
	friend class snake;
};

class snake
{
	public:
		int x,y,tailX[50],tailY[50],nTail;
		snake(){}
		snake(int y)
		{
			x=rand()%width;
			y=rand()%height;
			dir=STOP;
			tailX[0]=x;
			tailY[0]=y;
			nTail=1;
		}
		
		void input()
		{
			if(_kbhit())
			{
				switch(_getch())
				{
					case 'A':
					case 'a':
						dir=LEFT;
						break;
					case 'D':
					case 'd':
						dir=RIGHT;
						break;
					case 'W':
					case 'w':
						dir=UP;
						break;
					case 'S':
					case 's':
						dir=DOWN;
							break;
					case 'X':
					case 'x':
						gameOver=true;
						break; 
				}
			}
		}
		
		void movement(food &f)
		{
			int prevX = tailX[0];
			int prevY = tailY[0];
			int prev2X,prev2Y;
			tailX[0]=x;
			tailY[0]=y;
			for(int i=1;i<nTail;i++)
			{
				prev2X=tailX[i];
				prev2Y=tailY[i];
				tailX[i]=prevX;
				tailY[i]=prevY;
				prevX=prev2X;
				prevY=prev2Y;
			}
			switch(dir)
			{
				case LEFT:
					x--;
					break;
				case RIGHT:
					x++;
					break;
				case UP:
					y--;
					break;
				case DOWN:
					y++;
					break;
				default:
					break; 
			}
			if(x>=width) 
				x = 0;
			else if(x<0)
				x=width-1;
			if(y>=height) 
				y = 0;
			else if(y<0)
				y=height-1;
			for(int i=1;i<nTail;i++)
			{
				if(tailX[i]==x && tailY[i]==y)
				gameOver=true;
			}
			if(x==f.frutiX && y==f.frutiY)
			{
				score+=(f.fn+1)*10;
				f.frutiX=rand()%width;
				f.frutiY=rand()%height;
				if(f.frutiY==0)
				f.frutiY=f.frutiY+1;
				f.fn=rand()%3;
				f.fv=fo[f.fn];
				nTail++;
			}
		}
		friend class food;
};

class board
{
	public:
		board()
		{
			gameOver=false;
			score=0;
		}
		
		void Draw(snake s1,food f1)
		{
			system("CLS");				//system clear
			for(int i=0;i<width;i++)
			{
				for(int j=0;j<height;j++)
				mat[i][j]=' ';
			}	
			for(int i=0;i<width;i++)
			{
				for(int j=0;j<height;j++)
				{
			 		if(i==s1.y && j==s1.x)
			 			mat[i][j]='H';
			 		else if(i==f1.frutiY && j==f1.frutiX)
			 			mat[i][j]=fo[f1.fn];
			 		else
			 		{
			 			int h=0;
			 			for(int k=0;k<s1.nTail;k++)
						{
			 				if(s1.tailX[k]==j && s1.tailY[k]==i && s1.nTail>(k+1))
			 					mat[i][j+h++]='#';
							else if(s1.tailX[k]==j && s1.tailY[k]==i && s1.nTail>(k))
								mat[i][j+h]='T';
						}
			 		}
				 }
			}
			for(int i=0;i<width+2;i++)
			 	cout<<'*';
			cout<<endl;
			for(int i=0;i<width;i++)
			{
				for(int j=0;j<height;j++)
				{
					if(j==0 && i==0)
			 			cout<<'*';
					else if(j==0 && i!=0)
			 			cout<<'*';
					cout<<mat[i][j];
					if(j==width-1)
			 			cout<<'*';
				}
				cout<<endl;	
			}		
			for(int i=0;i<height+2;i++)
				cout<<'*';
			cout<<endl<<"Name :"<<name<<" Score :"<<score<<endl;
		}
		friend class food;
};

int main() {
	intial();
	char c;
	start:
	gotoxy(15,8);
	cout<<"Snake game";
	gotoxy(13,9);
	cout<<"Name : ";
	getline(cin,name);
	gotoxy(11,10);
	cout<<"Difficutity(L/M/H) :";
	cin>>c;
	int diff;
	switch(c)
	{
		case 'L':
		case 'l':
			diff=125;
			break;
		case 'M':
		case 'm':
			diff=115;
			break;
		case 'H':
		case 'h':
			diff=100;
			break;
		default:
			diff=125;
	}
	system("CLS");
	intial();
	load();
	board b;
	food f(0);
	snake s(0);
	while(!gameOver)
	{
		b.Draw(s,f);
		s.input();
		s.movement(f);
		if(score>=50)
			diff=25;
		if(score>=100)
			diff =10;
		Sleep(diff);
	}
	cout<<"Do you want to play again ? (Y/N)";
	cin>>c;
	if(c=='Y' || c=='y')
	{
		system("CLS");
		goto start;
	}
	return 0;
}
