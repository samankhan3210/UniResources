#include<iostream>
using namespace std;

class Maze
{
    char a[50][50];
    int row, col;
    public:
    Maze(char a[][7],int row, int col)
    {
        this->row=row;
        this->col=col;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                this->a[i][j]=a[i][j];
            }
        }
    }
    void printPaths(char temp[][7],int count)
    {
        for(int i=0; i<count; i++)
        {
            for(int j=0; j<count; j++)
            {
                if(temp[i][j]=='1')
                {
                    cout<<i<<" "<<j<<"\t";
                }
            }
        }
        cout<<"Cost="<<count;
    }
    void solveMaze(int i, int j, char temp[][7], int count)
    {
        if(a[i][j]=='e')
        {
            temp[i][j]='1';
            count++;
            printPaths(temp, count);
            return;
        }
        if((i<row && i>=0) || (j<col && j>=0))
        {
            if(a[i][j]=='s')
            {
                temp[i][j]='1';
                count++;
            }
			if(!temp[i+1][j])
            {
                solveMaze(i+1,j,temp,count++);
            }
            if(!temp[i-1][j])
            {
                solveMaze(i-1,j,temp,count++);
            }
            if(!temp[i][j+1])
            {
                solveMaze(i,j+1,temp,count++);
            }
            if(!temp[i][j-1])
            {
                solveMaze(i,j-1,temp,count++);
            }
		}
        temp[i][j]='0';
    }
};

int main()
{ 
    char arr[4][7]={{'s','0','0','0','0','0','1'},{'0','1','1','0','0','1','0'},{'0','1','1','0','0','1','0'},{'0','0','0','e','0','0','0'}};
    Maze ob(arr,4,7);
    char dummy[4][7]={0};
    ob.solveMaze(0,0,dummy,0);
}