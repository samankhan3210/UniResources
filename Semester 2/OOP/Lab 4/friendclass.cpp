#include<iostream>
using namespace std;
class Employee
{
    int empID;
    friend class HR;
};
class HR
{
    Employee e;
    public:
    HR()
    {
        e.empID=616;
        cout<<e.empID;
    }
};
int main()
{
     HR ob;
}