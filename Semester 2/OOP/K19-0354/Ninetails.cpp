// 19K-0354 Saman Khan
// OOP assignment#2
#include<iostream>
#include<string.h>
using namespace std;

class Gift
{
    string CatID;
    int price, tax;
    bool TaxApplicable;
    protected:
    static int PT;  //to keep updating indivdual perfume tax which will be simultaniously added into the total tax
    static int CCT; //to keep updating indivdual chocolate cake tax which will be simultaniously added into the total tax
    //didn't create any for flower tax b/c tax is not applicable on flowers
    static int TotalTax; //to store the changing/updating total tax
    static int FS; //to keep updating indivdual flowers stock which will be simultaniously added into the total stock
    static int PS; //to keep updating indivdual perfume stock which will be simultaniously added into the total stock
    static int CCS; //to keep updating indivdual chocolate stock which will be simultaniously added into the total stock
    static int TotalStock; //to store the changing/updating total stock
    static int FR; //to keep updating indivdual flowers revenue which will be simultaniously added into the (total) revenue
    static int PR; //to keep updating indivdual perfume revenue which will be simultaniously added into the (total) revenue
    static int CCR; //to keep updating indivdual chocolate cake revenue which will be simultaniously added into the (total) revenue
    static int Revenue; //to store the changing/updating (total) revenue
    public:
    Gift(){}  //default constructor
    Gift(string CD, int P, bool TA)  //constructor
    {
        CatID=CD;
        price=P;
        TaxApplicable=TA;
    }
    void setCatID(string CD) //setter to input category ID
    {
        CatID=CD;
    }
    string getCatID() //getter which returns category ID
    {
        return CatID;
    }
    void setPrice(int P) //setter to input price of a single item
    {
        price=P;
    }
    int getPrice() //getter which returns price
    {
        return price;
    }
    // void setTax(int T) 
    // {
    //     tax=T;
    // }
    // int getTax()
    // {
    //     return tax;
    // }
    void setTaxApplicable(bool TA)  //setter to set whether the tax on the gift is applicable or not
    {
        TaxApplicable=TA;
    }
    int getTaxApplicable() //getter which returns gift's tax applicable
    {
        return TaxApplicable;
    }
    static void setFS(int fs) //setter to set the flowers stock in this case it is initialised with 100 but it will keep updating as the flowers are bought
    {
        FS=fs;
    }
    static int getFS() //getter which returns the updated flowers stock
    {
        return FS;
    }
    static void setPS(int ps) //setter to set the perfume stock in this case it is initialised with 50 but it will keep updating as the perfumes are bought
    {
        PS=ps;
    }
    static int getPS() //getter which returns the updated perfumes stock
    {
        return PS;
    }
    static void setCCS(int ccs) //setter to set the chocolate cake stock in this case it is initialised with 50 but it will keep updating as the cakes are bought
    {
        CCS=ccs;
    }
    static int getCCS() //getter which returns the updated cakes stock
    {
        return CCS;
    }
    static void setTotalStock(int ts) //add flowers, perfume and cake stocks in total stock
    {
        TotalStock=ts;
        ts=getFS()+getPS()+getCCS();
    }
    static void showTotalStock() //display total stock
    {
        cout<<"Total Stock : Rs. "<<TotalStock<<endl;
    }
    static void setFR(int fr) //to set the flowers revenue as the flowers are bought and it will keep updating it
    {
        FR=fr;
    }
    static int getFR() //returns the updated flowers revenue
    {
        return FR;
    }
    static void setPR(int pr) //to set the perfume revenue as the perfumes are bought and it will keep updating it
    {
        PR=pr;
    }
    static int getPR() //returns the updated perfume revenue
    {
        return PR;
    }
    static void setCCR(int ccr) //to set the chocolate cake revenue as the cakes are bought and it will keep updating it
    {
        CCR=ccr;
    }
    static int getCCR() //returns the updated chocolate cake revenue
    {
        return CCR;
    }
    static void setRevenue(int r) //adds flowers, perfume and cake revenue in total revenue
    {
        Revenue=r;
        r=getRevenue()+getFR()+getPR()+getCCR();
    }
    static int getRevenue() //returns the updated total revenue
    {
        return Revenue;
    }
    static void setPT(int pt) //to set the perfume tax as the perfumes are bought and it will keep updating it 
    {
        PT=pt;
    }
    static int getPT() //returns the updated perfume tax
    {
        return PT;
    }
    static void setCCT(int cct) //to set the chocolate cake tax as the cakes are bought and it will keep updating it
    {
        CCT=cct;
    }
    static int getCCT() //returns the updated chocolate cake tax
    {
        return CCT;
    }
    void setTotalTax(int TT) //adds perfume and cake tax in total tax
    {
        TotalTax=TT;
        TT=TT+getPT()+getCCT();
    }
    static int getTotalTax() //returns the updated total tax
    {
        return TotalTax;
    }
    virtual void bill()=0; //virtual function which will be used to calculate bill of each gift items class 
};
int Gift::FS=100;
int Gift::PS=50;
int Gift::CCS=50;
int Gift::TotalStock=200;
int Gift::FR=0;
int Gift::PR=0;
int Gift::CCR=0;
int Gift::Revenue=0;
int Gift::PT=0;
int Gift::CCT=0;
int Gift::TotalTax=0;

class NineTails
{
    string contactNo, address, email;
    public:
    NineTails()
    {}
    NineTails(string CN, string A, string E)
    {
        contactNo=CN;
        address=A;
        email=E;
    }
    void setContactNo() //setter for contact number
    {
        string CN;
        cout<<"Enter your contact number : ";
        cin>>CN;
        contactNo=CN;
    } 
    string getContactNo() //getter which returns contact number
    {
        return contactNo;
    }
    void setAddress(string A) //setter for address
    {
        address=A;
    } 
    string getAddress() //getter which returns address 
    {
        return address;
    }
    void setEmail(string E) //setter for email
    {
        email=E;
    } 
    string getEmail()  //getter which returns email 
    {
        return email;
    }
    void display() //display function which prints contact number, address, and email
    {
        cout<<"Contact Number : "<<getContactNo()<<endl;
        cout<<"Address : "<<getAddress()<<endl;
        cout<<"Email : "<<getEmail()<<endl;
    }
    void RevenueAndTax() //this function prints total revenue and tax from gift class as the revenue and total tax funtions are static
    {
        cout<<"Total Revenue : Rs. "<<Gift::getRevenue()<<endl;
        cout<<"Total Tax : Rs. "<<Gift::getTotalTax()<<endl;
    }
    friend class TaxationDept; //friend class beacuse we need to print the tax and revenue of the company without any inheritane between the nine tail's class and taxation department's class
};

class Flowers: public Gift //public inheritance because flower is a gift
{
    string floralType;
    int numberOfFlowers;
    public:
    Flowers()
    {}
    Flowers(string FT,int NoF, string CD, int P, bool TA)
    {
        floralType=FT;
        numberOfFlowers=NoF;
        setCatID("FL1");
        setPrice(50);
        setTaxApplicable(false);
    }    
    void setFloralType() //setter to take input for floral type of flower
    {
        string FT;
        cout<<"Enter the type of flower you wanna buy (ROSE, TULIP, or DAISY) : ";
        cin>>FT;
        floralType=FT;
    }
    string getFloralType() //getter which returns the floral type
    {
        return floralType;
    }
    void setNumberOfFlowers() //setter to take input for number of flowers that user wanna buy
    {
        int NoF;
        cout<<"Enter the number of flowers you wanna buy : ";
        cin>>NoF;
        numberOfFlowers=NoF;
    }
    int getNumberOfFlowers() //getter which returns the number of flowers bought by user
    {
        return numberOfFlowers;
    }
    void bill() //using function over riding for bill which prints the bill of flowers 
    {
        cout<<"Type of flowers bought : "<<getFloralType()<<endl;
        cout<<"Number of flowers bought : "<<getNumberOfFlowers()<<endl;
        cout<<"Price of a single Flower : Rs. "<<getPrice()<<endl;
        cout<<"Price of "<<getNumberOfFlowers()<<" flowers : Rs. "<<(getPrice()*getNumberOfFlowers())<<endl;
    }
    void NewFStock() //function which updates indivdual flowers stock and total stock
    {
        setFS(getFS()-getNumberOfFlowers());
        setTotalStock(getFS()+getPS()+getCCS());
    }
    void showNewFStock() //function which prints indivdual flowers stock
    {
        cout<<"Flowers Left : "<<getFS()<<endl;
    }
    void calculateFRevenue() //function which updates indivdual flowers revenue amd total revenue
    {
        setFR(getFR()+(getNumberOfFlowers()*getPrice()));
        setRevenue(getRevenue()+getFR()+getPR()+getCCR());
    }
    void showcalculateFRevenue() //function which prints indivdual flowers revenue
    { 
        cout<<"Flowers Revenue : Rs. "<<getFR()<<endl;
    }
    Flowers(const Flowers &F) //copy constructor 
    {
        setCatID("FL1");
        setPrice(50);
        setTaxApplicable(false);
        floralType=F.floralType;
        numberOfFlowers=F.numberOfFlowers;
        //since we are not calling any stock or revenue function of flower class then the stock and reveue won't change
        cout<<"Object copied successfully! "<<endl;
    }
};

class Perfume: public Gift //public inheritance because perfume is a gift
{
    string brand;
    int numberOfPerfumes;
    public:
    Perfume()
    {}
    Perfume(string B, int NoP, string CD, int P, bool TA)
    {
        brand=B;
        numberOfPerfumes=NoP;
        setCatID("PF1");
        setTaxApplicable(true);        
    }
    void setBrand() //setter to take input for brand of perfume that user wanna buy
    {
        string B;
        cout<<"Enter the brand of perfumes you wanna buy (GUCCI, VERSACE, or CHANEL): ";
        cin>>B;
        brand=B;
        if(B=="GUCCI"||B=="gucci") //these conditions are required in order to set the price because each brand has different prices 
        {
            setPrice(1200);
        }
        else if(B=="VERSACE"||B=="versace")
        {
            setPrice(1100);
        }
        else if(B=="CHANEL"||B=="chanel")
        {
            setPrice(950);
        }
        else
        {
            cout<<"INVALID BRAND NAME";
        }
    }
    string getBrand() //getter which returns the brand of perfume bought
    {
        return brand;
    }
    void setNumberOfPerfumes() //setter to take input for number of perfumes that user wanna buy
    {
        int NoP;
        cout<<"Enter the number of "<<getBrand()<<" perfumes you wanna buy : ";
        cin>>NoP;
        numberOfPerfumes=NoP;
    }
    int getNumberOfPerfumes() //getter which returns the number of perfumes bought by the user
    {
        return numberOfPerfumes;
    }
    void bill() //using function over riding for bill which prints the bill of perfume 
    {
        cout<<"Brand of Perfume : "<<getBrand()<<endl;
        cout<<"Number of perfumes bought : "<<getNumberOfPerfumes()<<endl;
        cout<<"Price of a single perfume : Rs. "<<getPrice()<<endl;
        cout<<"Price of "<<getNumberOfPerfumes()<<" perfumes : Rs. "<<(getPrice()*getNumberOfPerfumes())<<endl;
    }
    void NewPStock() //function which updates indivdual perfume stock and total stock
    {
        setPS(getPS()-getNumberOfPerfumes());
        setTotalStock(getFS()+getPS()+getCCS());
    }
    void showNewPStock() //function which prints indivdual perfume stock
    {
        cout<<"Perfumes Left : "<<getPS()<<endl;
    }
    void calculatePRevenue() //function which updates indivdual perfume revenue amd total revenue
    {
        setPR(getPR()+(getNumberOfPerfumes()*getPrice()));
        setRevenue(getFR()+getPR()+getCCR());
    }
    void showcalculatePRevenue() //function which prints indivdual perfume revenue
    {
        cout<<"Perfume Revenue : Rs. "<<getPR()<<endl;
    }
    void CalcPTax() //function which updates indivdual perfume tax amd total tax
    {
        setPT(getPT()+(getNumberOfPerfumes()*(getPrice()*0.07)));
        setTotalTax(getTotalTax()+getPT());
    }
};

class ChocolateCake: public Gift //public inheritance because chocolate cake is a gift
{
    int weight;
    string msgOnCake;
    public:
    ChocolateCake()
    {}
    ChocolateCake(int W, string MoC, string CD, int P, bool TA)
    {
        weight=W;
        msgOnCake=MoC;
        setCatID("CK1");
        setPrice(700);
        setTaxApplicable(true); 
    }
    void setWeight() //setter to input the weight of cake that the user wanna buy
    {
        int W;
        cout<<"Enter the weight of cake you wanna buy (in pounds) : ";
        cin>>W;
        weight=W;
        setPrice(700);
    }
    int getWeight() //getter which returns the weight of the cake
    {
        return weight;
    }
    void setMsgOnCake() //setter to input the message on cake that the user want
    {
        string MoC;
        cout<<"Enter the message you'd like on the cake : ";
        cin>>MoC;
        msgOnCake=MoC;
    }
    string getMsgOnCake() //getter which returns the message that the user want on top of the cake
    {
        return msgOnCake;
    }
    void bill() //using function over riding for bill which prints the bill of chocolate cake 
    {
        cout<<"Weight of a cake : "<<getWeight()<<" pounds"<<endl;
        cout<<"Message on cake : "<<getMsgOnCake()<<endl;
        cout<<"Price of a 1 pound cake : Rs. 700"/*<<setPrice(700)*/<<endl;
        cout<<"Price of "<<getWeight()<<" pound cake(s) : Rs. "<<(getPrice()*getWeight())<<endl;
    }
    void NewCCStock() //function which updates individual chocolate stock and total stock
    {
        setCCS(getCCS()-getWeight());
        setTotalStock(getFS()+getPS()+getCCS());
    }
    void showNewCCStock() //function which prints indivdual chocolate cake stock
    {
        cout<<"Cakes Left : "<<getCCS()<<endl;
    }
    void calculateCCRevenue() //function which updates individual chocolate revenue and total revenue
    {
        setCCR(getCCR()+(getWeight()*getPrice()));
        setRevenue(getFR()+getPR()+getCCR());
    }
    void showcalculateCCRevenue()  //function which prints indivdual chocolate cake revenue
    {
        cout<<"Chocolate Cake Revenue : Rs. "<<getCCR()<<endl;
    }
    void CalcCCTax() //function which updates indivdual chocolate cake tax amd total tax
    {
        setCCT(getCCT()+((getWeight()*(getPrice()*0.04))));
        setTotalTax(getTotalTax()+getCCT());
    }
};

class HappyBundle: public Flowers, public Perfume, public ChocolateCake //hierarchical inheritance 
{
    int HBP; //variabel happy bundle price which will be used to store the price of a bundle two gift items
    public:
    HappyBundle()
    {}
    void HBofPandF()
    {
        // Flowers f1("TULIP",3,"FL1",50,false); //hardcoded if don't wanna take any user input
        Flowers f1; //an object of flower class is created
        f1.setCatID("FL1"); // ID is hardcoded
        f1.setFloralType(); //calls setter floral type to ask for floral type
        f1.setNumberOfFlowers(); //ask for number of flowers user wanna buy
        f1.setPrice(50); //sets price as 50 as all flowers are of same price
        // f1.bill(); //calls bill function to print bill of flower class
        // Perfume p1("GUCCI",1,"PF1",1200,true); //hardcoded if don't wanna take any user input
        Perfume p1; //an object of perfume class is created
        p1.setCatID("PF1"); // ID is hardcoded
        p1.setBrand(); //ask for brand of perfume the user wanna buy
        p1.setNumberOfPerfumes(); //ask for number of perfumes user wanna buy
        //p1.bill(); //calls bill function to print bill of perfume class
        HBP=(f1.getNumberOfFlowers()*f1.getPrice())+(p1.getNumberOfPerfumes()*p1.getPrice()); //adds prices of flower and perfume object then stores it into happy bundle price 
        cout<<"Price of first happy bundle is : Rs. "<<HBP<<endl;
    }
    void HBofPandC()
    {
        // ChocolateCake c1(2,"HappyBirtday","CK1",2*700,true); //hardcoded if don't wanna take any user input
        ChocolateCake c1; //an object of chocolate cake class is created
        c1.setCatID("CL1"); // ID is hardcoded
        c1.setWeight(); //ask the user for weight of the cake
        c1.setMsgOnCake(); //ask  user for the message on the cake
        // c1.bill(); //calls bill function to print bill of chocolate cake class
        // Perfume p1("VERSACE",3,"PF1",3*1100,true); //hardcoded if don't wanna take any user input
        Perfume p1; //an object of perfume class is created
        p1.setCatID("PF1"); // ID is hardcoded
        p1.setBrand(); //ask for brand of perfume the user wanna buy
        p1.setNumberOfPerfumes(); //ask for number of perfumes user wanna buy
        // p1.bill(); //calls bill function to print bill of perfume class
        HBP=(p1.getNumberOfPerfumes()*p1.getPrice())+(c1.getWeight()*c1.getPrice()); //adds prices of perfume and chocolate cake object then stores it into happy bundle price 
        cout<<"Price of second happy bundle is : Rs. "<<HBP<<endl;
    }
    void HBofFandC()
    {   
        //Flowers f1("rose",1,"FL1",50,false); //hardcoded if don't wanna take any user input
        Flowers f1; //an object of flower class is created
        f1.setCatID("FL1"); // ID is hardcoded
        f1.setFloralType(); //calls setter floral type to ask for floral type
        f1.setNumberOfFlowers(); //ask for number of flowers user wanna buy
        f1.setPrice(50); //sets price as 50 as all flowers are of same price
        // f1.bill(); //calls bill function to print bill of flower class
        //ChocolateCake c1(5,"HBD","CK1",5*700,true); //hardcoded if don't wanna take any user input
        ChocolateCake c1; //an object of chocolate cake class is created
        c1.setCatID("CL1");  // ID is hardcoded
        c1.setWeight();  //ask the user for weight of the cake
        c1.setMsgOnCake();//ask  user for the message on the cake
        //c1.bill(); //calls bill function to print bill of chocolate cake class
        HBP=(f1.getNumberOfFlowers()*f1.getPrice())+(c1.getWeight()*c1.getPrice()); //adds prices of flower and chocolate cake object then stores it into happy bundle price 
        cout<<"Price of third happy bundle is : Rs. "<<HBP<<endl;
    }
    bool operator > (const HappyBundle& HB) //uses operator loading to compare the prices of two objects of happy bundle
    {
        if(HBP > HB.HBP) //will return true if the condition id true else false because return type is bool
        {
            return true;
        }
        else
        {
            return false;
        }
    }    
};

class TaxationDept
{
    NineTails n1; //object of nine tails created because texation department is a friend of ninetails
    public:
    TaxationDept()
    {}
    void Display() //function to display total revenue and tax
    {
        n1.RevenueAndTax(); //calling revenue and tax function to print total revenue and tax
    }
};

int main()
{
    int x; 
    cout<<"\t\t\t\t\tWELCOME TO NINETAILS DELIVERY SERVICE"<<endl;
    NineTails N; //an object of ninetails class is created
    N.setContactNo(); //calling setter of contact number 
    N.setEmail("K190354@nu.edu.pk"); //email is hardcoded
    N.setAddress("St-4, Sector 17-D, National Highway 5, Karachi"); //address is hardcoded
    N.display(); //calling display function of ninetails class
    do //do-while loop to keep asking the user for choice as long as the user wants  
    {
        cout<<endl;
        cout<<"\t\t\t\t\tWELCOME TO NINETAILS DELIVERY SERVICE"<<endl;
        cout<<"1. Buy Flowers"<<endl;
        cout<<"2. Buy Perfume"<<endl;
        cout<<"3. Buy Cake"<<endl;
        cout<<"4. Compare HappyBudles"<<endl;
        cout<<"5. Show Stock and Revenue of Individual Gift Item"<<endl;
        cout<<"6. Show Total Tax, Revenue and Stock"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<endl;
        cout<<"Enter Your Choice : ";
        cin>>x;
        cout<<endl;
        if(x==1) //conditions to take to the said option
        {
            Flowers F;  //an object of flower class is created
            F.setCatID("FL1"); //ID is hardcoded
            F.setTaxApplicable(false); //tax applicable is set to 0 
            F.setFloralType(); //calls setter floral type to ask for floral type
            F.setPrice(50); //since the price per flowers is same so price is hardcoded
            F.setNumberOfFlowers(); //ask for number of flowers user wanna buy
            F.bill(); //calls bill function to print bill of flower class
            F.NewFStock(); //calling flower stock funtion to update indivdual flowers stock
            F.calculateFRevenue(); //calling flower revenue funtion to update indivdual flowers revenue
            Flowers Fo=F;  //copy constructor called to copy object 1 into object 2
        }
        else if(x==2)
        {
            Gift* G= new Perfume; //created pointer variable of gift class 
            G->setCatID("PF1"); //gift pointer is pointing towards category ID setter which is hard coded
            G->setTaxApplicable(true); //gift pointer is pointing towards tax applicable setter which is hard coded
            Perfume P; //an object of perfume class is created
            P.setBrand(); //ask for brand of perfume the user wanna buy
            P.setNumberOfPerfumes(); //ask for number of perfumes user wanna buy
            P.bill(); //calls bill function to print bill of perfume class
            P.NewPStock(); //calling perfume stock funtion to update indivdual perfume stock
            P.calculatePRevenue(); //calling perfume revenue funtion to update indivdual perfume revenue
            P.CalcPTax(); //calling perfume tax funtion to update indivdual perfume tax so it updates the total tax
            // Gift* G= new Perfume("GUCCI",2,"PF1",1200*2,true); //I tried making accessing the bill function through pointer  variable by hardcoding the values 
            // G->bill(); //but the bill funtion was not printing any value (price or brand) 
        }
        else if(x==3)
        {
            ChocolateCake C;  //an object of chocolate cake class is created
            C.setCatID("CK1"); //ID is hardcoded
            C.setTaxApplicable(true); //calling tax applicable setter which is hard coded
            C.setWeight();//ask the user for weight of the cake
            C.setPrice(700); //since the price per pond cake is same so price is hardcoded
            C.setMsgOnCake(); //ask  user for the message on the cake
            C.bill(); //calls bill function to print bill of perfume class
            C.NewCCStock(); //calling chocolate cake stock funtion to update indivdual chocolate cake stock
            C.calculateCCRevenue(); //calling chocolate cake revenue funtion to update indivdual chocolate cake revenue
            C.CalcCCTax(); //calling chocolate cake tax funtion to update indivdual chocolate cake tax so it updates the total tax
        }
        else if(x==4)
        {
            HappyBundle HB1; //object 1 of happy bundle class is created
            HappyBundle HB2; //object 2 of happy bundle class is created
            HappyBundle HB3; //object 3 of happy bundle class is created
            cout<<"\t\t\t\t\tFOR HAPPY BUNDLE 1 OF PERFUME AND FLOWERS"<<endl;
            HB1.HBofPandF(); //object 1 calls happy undle of flower and perfume
            cout<<endl<<"\t\t\t\t\tFOR HAPPY BUNDLE 2 OF PERFUME AND CAKE"<<endl;
            HB2.HBofPandC(); //object 1 calls happy undle of chocolate cake and perfume
            cout<<"\t\t\t\t\tFOR HAPPY BUNDLE 3 OF FLOWERS AND CAKE"<<endl;
            HB3.HBofFandC(); //object 1 calls happy undle of flower and chocolate cake
            cout<<"\t\t\t\tCOMPARING THE HAPPY BUNDLES"<<endl;
            cout<<"1. Comparison of Happy Bundle 1 with Happy Bundle 2 : "<<endl<<endl;
            if(HB1>HB2) //calls operator overloading function for object 1 and 2
                {
                    cout<<"First Happy Bundle gives more profit than the second one"<<endl;
                }
                else
                {
                    cout<<"Second Happy Bundle gives more profit than the first one"<<endl;
                }
            cout<<endl<<"2. Comparison of Happy Bundle 1 with Happy Bundle 3 : "<<endl<<endl;
            
                if(HB1>HB3) //calls operator overloading function for object 1 and 3
                {
                    cout<<"First Happy Bundle gives more profit than the third one"<<endl;
                }
                else
                {
                    cout<<"Third Happy Bundle gives more profit than the first one"<<endl;
                }
            cout<<endl<<"4. Comparison of Happy Bundle 2 with Happy Bundle 3 : "<<endl<<endl;
            if(HB2>HB3) //calls operator overloading function for object 2 and 3
                {
                    cout<<"Second Happy Bundle gives more profit than the third one"<<endl;
                }
                else
                {
                    cout<<"Third Happy Bundle gives more profit than the second one"<<endl;
                }
        }
        else if(x==5)
        {
            cout<<"\t\t\t\t\tIndividual Revenue of Each Gift Item"<<endl;
            Flowers fl; //an object of flower class is created
            fl.showcalculateFRevenue(); //and it calls revenue function of class flower to print the individual revenue of flower
            Perfume pf; //an object of perfume class is created
            pf.showcalculatePRevenue(); //and it calls revenue function of class perfume to print the individual revenue of perfume
            ChocolateCake ck; //an object of chocolate cake class is created
            ck.showcalculateCCRevenue(); //and it calls revenue function of class chocolate cake to print the individual revenue of chocolate cake
            cout<<"\t\t\t\t\tIndividual Stock of Each Gift Item"<<endl;
            fl.showNewFStock(); //flower class object calls it's stock function to print the individual stock of flower
            pf.showNewPStock(); //perfume class object calls it's stock function to print the individual stock of perfume
            ck.showNewCCStock(); //chocolate cake class it's stock function to print the individual stock of chocolate cake
        }
        else if(x==6)
        {
            TaxationDept T; //an object of texation department class is created
            T.Display(); //calling display function to print total stock and revenue 
            Gift::showTotalStock(); //using scope resolution operator to print total stock beacause this function is static
        }
        else if(x==7)
       {
            break; //get out of the loop and end the program
       }
    }
    while(x>=1||x<7); //while codition, the loop will work as long as the condition is fulfilled
}