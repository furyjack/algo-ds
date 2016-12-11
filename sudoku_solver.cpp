#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int arr[9][9]={0};

struct pos
{
	int x;
	int y;

};


bool isvalid(pos p,int num)
{
	// search row
	
	for(int i=0;i<9;i++)
	{
		if(i==p.y)
			continue;
		if(arr[p.x][i]==num)
		{
			return false;
		}
	}

	//search column
		for(int i=0;i<9;i++)
	{
		if(i==p.x)
			continue;
		if(arr[i][p.y]==num)
		{
			return false;
		}
	}


   //search box

		int brow=p.x/3;
		int bcol=p.y/3;

		brow*=3;
		bcol*=3;

		for(int i=brow;i<brow+3;i++)
		{
			for(int j=bcol;j<bcol+3;j++)
			{
				if(i==p.x && j==p.y)
					continue;

				if(arr[i][j]==num)
					return false;

			}
		}


return true;

}
void printarr()
{
	cout<<"\n";
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
		
			cout<<arr[i][j]<<" ";
		}


		cout<<"\n";

	}


}

bool fillpos(pos p,int si=0)
{
	int num=-1;
	for(int i=si+1;i<=9;i++)
	{
		if(isvalid(p,i))
		{
			num=i;
			break;
		}
	}

	if(num==-1)
		return false;

	arr[p.x][p.y]=num;
	printarr();
	pos ngp;
	ngp.x=-1;
	ngp.y=-1;
	//find next good postion
	int col=p.y+1;
	int row=p.x;
	while(row<9)
	{
		for(int i=col;i<9;i++)
		{
			if(arr[row][i]==0)
			{
				ngp.x=row;
				ngp.y=i;
				break;
			}
		}
		if(ngp.x!=-1)
			break;
		col=0;
		row++;

	}

	if(ngp.x==-1)
		return true;
	bool wasgood=fillpos(ngp);
	if(wasgood)
		return true;
	else
	{
		arr[p.x][p.y]=0;
		fillpos(p,num);
	}


}

bool checkifvalid()
{

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
		if(arr[i][j]!=0)
		{
			pos p;
			p.x=i;
			p.y=j;
			if(!isvalid(p,arr[i][j]))
				return false;

		}

		}


		

	}

	return true;

}


int main() {
	
 /*   int goodpos;
	cout<<"enter how many positions you want to enter\n";
	cin>>goodpos;
	cout<<"enter like this x-cor y-cor num \n";
	for(int i=0;i<goodpos;i++)
	{
		int x,y,num;
		cin>>x>>y>>num;
		arr[x-1][y-1]=num;

	}

	*/

    arr[0][2]=5;
	arr[0][8]=6;
	arr[1][0]=2;
	arr[1][4]=9;
	arr[1][5]=8;
	arr[1][7]=4;
	
	arr[2][1]=3;
	arr[2][4]=1;
	arr[2][5]=5;
	
	arr[3][2]=8;
	arr[3][3]=9;
	arr[3][7]=2;
	arr[3][8]=4;
	arr[4][4]=8;
	
	arr[5][0]=9;
	arr[5][1]=1;
	arr[5][5]=2;
	arr[5][6]=6;
	arr[6][3]=2;
	arr[6][4]=3;
	arr[6][7]=9;
	
	arr[7][1]=2;
	arr[7][3]=4;
	arr[7][4]=5;
	arr[7][8]=1;
	arr[8][0]=4;
	arr[8][6]=3;

	if(!checkifvalid())
	{
		cout<<"wrong problem\n";
		cin.get();
		return 0;
	}
	else
	{
		cout<<"starting processing\nenter any key to continue\n";
		cin.get();
	}


	pos ngp;
	ngp.x=-1;
	ngp.y=-1;

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(arr[i][j]==0)
			{
				ngp.x=i;
				ngp.y=j;
				break;
			}


		}
			if(ngp.x!=-1)
			break;


	}
		if(ngp.x!=-1)
			{
				if(fillpos(ngp))
					cout<<"\n\nSolved";
		}

		else
			cout<<"unsovalble";


	
	
	
	cin.get();
	cin.get();
    return 0;
}
