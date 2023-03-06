//LAB TASKS#03 QUESTION#03
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class Student
{
    string name; //variable for storing student name
    int RN; //variable for storing student roll number
	float score1, score2, score3, score4; //variables for storing student 4 scores
    public:
    void setData(string n, int rn, float s1, float s2, float s3, float s4) //setter 1
    {
        name=n;
        RN=rn;
        score1=s1;
        score2=s2;
        score3=s3;
        score4=s4;
    }
    void percentage() //function 1 for calculating percentage
    {
        float P,sum=0;
        sum=score1+score2+score3+score4;
        P=(sum*100)/400;
        cout<<"Percentage: "<<P<<"%"<<endl;
    }
    void displayData()  //function 2 for displaying output
    {
    	cout<<"Student Name: "<<name<<endl;
    	cout<<"Student Roll Number: "<<RN<<endl;
    	cout<<"Test Scores: "<<fixed<<setprecision(2)<<score1<<"\t";
		cout<<fixed<<setprecision(2)<<score2<<"\t";
		cout<<fixed<<setprecision(2)<<score3<<"\t";
		cout<<fixed<<setprecision(2)<<score4<<endl;
		percentage(); //calling function 1 to display the percentage
	}
};
int main()
{
    Student S; 
    string N; //for storing name 
    int rollno; //for storing roll number 
    float ts1, ts2, ts3, ts4;  //for storing 4 test scores
    cout<<"Enter the student name: ";
    cin>>N;
    cout<<"Enter the student roll number: ";
    cin>>rollno;
    cout<<"Enter test score 1: ";
    cin>>ts1;
    cout<<"Enter test score 2: ";
    cin>>ts2;
    cout<<"Enter test score 3: ";
    cin>>ts3;
    cout<<"Enter test score 4: ";
    cin>>ts4;
    S.setData(N,rollno,ts1,ts2,ts3,ts4); //calling setter function
    S.displayData(); //calling function 2 to display all the data
}

