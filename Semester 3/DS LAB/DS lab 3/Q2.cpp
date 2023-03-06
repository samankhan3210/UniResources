#include <iostream>
#include <vector>
using namespace std; 

int main()
{
    int a=0, b=0; 
    vector<vector<int> > jagArr; 
    for (int i=0; i<10; i++)
    {
        vector<int> t; 
        cout<<"Enter the row size: "<<endl; 
        cin>>b; 
        for(int j=0; j<b; j++)
        {
            cout<<"Enter element "<<j+1<<" : "<<endl; 
            cin>> a; 
            t.push_back(a); 
        }
    jagArr.push_back(t); 
    }
    for(int i=0; i<10; i++)
    {
        b=jagArr[i].size(); 
        for(int j=0; j<b; j++)
        {
            cout<<jagArr[i][j]<<"\t"; 
        }
        cout<<endl; 
    }
    

}