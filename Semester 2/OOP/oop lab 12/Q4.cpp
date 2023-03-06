#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Participant
{
    string ID, name;
    int score;
    public:
    Participant(string id, string n, int s)
    {
        ID=id;
        name=n;
        score=s;
    }
    Participant()
    {}
    void Input()
    {
        ofstream in("Question4.bin",ios::app);
		in.write((char*)this,sizeof(*this));
		in.close();
    }
    void display()
    {
        cout<<"ID : "<<ID<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Score : "<<score<<endl;
    }
    void Output(string x)
	{
		ifstream s;
		s.open("Question4.bin");
		while(!s.eof())
		{
			s.read((char*)this,sizeof(*this));
			if(ID==x)
			{
				display();
				break;
			}
		}
		s.close();
	}
    void Max()
	{
		Participant m("","",0);
		ifstream r;
		r.open("Question4.bin");
		while(!r.eof())
		{
			r.read((char*)this,sizeof(*this));
			if(this->score>m.score)
			{
				m=*this;
			}
		}
        cout<<"Data of the highest scorer is : "<<endl;
		m.display();
	}
};

int main()
{
    string n1,n2,n3, id1, id2, id3, ids;
    int s1, s2, s3;
    cout<<"Enter the ID, name and score of participant 1 : ";
    cin>>id1>>n1>>s1;
    Participant p1(id1,n1,s1);
    cout<<"Enter the ID, name and score of participant 2 : ";
    cin>>id2>>n2>>s2;
    Participant p2(id2,n2,s2);
    cout<<"Enter the ID, name and score of participant 3 : ";
    cin>>id3>>n3>>s3;
    Participant p3(id3,n3,s3);
    p1.Input();
    p2.Input();
    p3.Input();
    cout<<"Enter the ID of the participant you want displayed :";
    cin>>ids;
    Participant p4;
    p4.Output(ids);
    p4.Max();
}