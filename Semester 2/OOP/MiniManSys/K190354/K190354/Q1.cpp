#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    string s;
    //writing in the file
    ofstream ofs("Question1.txt");
    cout<<"Enter any string : ";
    cin>>s;
    ofs<<s;
    ofs.close();
    //reading from the file
    int i, sl;
    ifstream ifs("Question1.txt");
    char *c=new char[50];
    ifs.read(c,50);
    sl=ifs.gcount();
    cout<<"Length of the string is : "<<sl<<endl;
    cout<<"String : ";
    for(i=0; i<sl; i++)
    {
        cout<<c[i];
    }   
    ifs.close();
}