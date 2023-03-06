#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    char ch;
    ifstream of("oldfile.txt");
    ofstream nf("newfile.txt");
    while(!of.eof())
    {
        of>>ch;
        if(ch==' ')
        {
            nf<<" ";
        }
        else
        {
            nf<<ch;
        }
    }
    of.close();
    nf.close();
    ifstream nf2("newfile.txt");
    nf2.seekg(0);
    while(!nf2.eof())
    {
        nf2>>ch;
        if(ch==' ')
        {
            cout<<" ";
        }
        else
        {
            cout<<ch;
        }
    }
    nf2.close();
}