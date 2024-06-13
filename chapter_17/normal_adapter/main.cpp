#include<iostream>

using namespace std;

class Target
{
public:
    virtual void request() { cout << "��ͨ����!" << endl; }
};

class Adaptee
{
public:
    void specificRequest() { cout << "��������!" << endl; }
};

class Adapter: public Target
{
public:
    virtual void request() { adaptee.specificRequest(); }
private:
    Adaptee adaptee;
};

int main()
{
    Target* target = new Adapter;
    target->request();
    delete target;

    return 0;
}