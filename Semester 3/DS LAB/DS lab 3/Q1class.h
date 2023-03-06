#ifndef Q1CLASS_H
#define Q1CLASS_H
using namespace std; 

class DSA
{
    protected:
    int size;
    int *data;
    public:
    DSA();
    DSA(int x);
    DSA(const DSA & dsa);
    ~DSA();
    void resize(int res);
    DSA &operator =(const DSA & dsa);
    int getsize() const;
    virtual void insertion(int val, int index);
    virtual void searching(int val);
};
class OrderedDSA: public DSA
{
	public:
    OrderedDSA(int x);
    void insertion(int val);  
    void searching(int val);  
};
class UnorderedDSA: public DSA
{
	public:
    UnorderedDSA(int x); 
    void insertion(int val, int index); 
    void searching(int val); 
};

#endif