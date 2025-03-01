#include <iostream>

using namespace std;

class Stock1
{
public:
    void sell() { cout << "Stock1 sell" << endl; }
    void buy() { cout << "Stock1 buy" << endl; }
};

class Stock2
{
public:
    void sell() { cout << "Stock2 sell" << endl; }
    void buy() { cout << "Stock2 buy" << endl; }
};

class NationalDebt1
{
public:
    void sell() { cout << "NationalDebt1 sell" << endl; }
    void buy() { cout << "NationalDebt1 buy" << endl; }
};

class Realty1
{
public:
    void sell() { cout << "Realty1 sell" << endl; }
    void buy() { cout << "Realty1 buy" << endl; }
};

int main()
{
    Stock1 stock1;
    Stock2 stock2;
    NationalDebt1 nd1;
    Realty1 realty1;

    stock1.buy();
    stock2.buy();
    nd1.buy();
    realty1.buy();

    stock1.sell();
    stock2.sell();
    nd1.sell();
    realty1.sell();
    
    return 0;
}