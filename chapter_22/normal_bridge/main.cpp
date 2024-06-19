#include<iostream>

using namespace std;

class Implementor
{
public:
    virtual void operation() = 0;
};

class ConcreteImplementorA: public Implementor
{
public:
    void operation() { cout << "����ʵ��A�ķ���ִ��" << endl; }
};

class ConcreteImplementorB: public Implementor
{
public:
    void operation() { cout << "����ʵ��B�ķ���ִ��" << endl; }
};

class Abstraction
{
public:
    void setImplementor(Implementor* implementor) 
    {
        delete this->implementor; 
        this->implementor = implementor; 
    }
    Abstraction(): implementor(nullptr) {} 
    ~Abstraction() { delete implementor; }
    virtual void operation() = 0;
protected:
    Implementor* implementor;
};

class RefinedAbstraction: public Abstraction
{
public:
    void operation() 
    {
        cout << "�����Abstraction" << endl;
        implementor->operation();
    }
};

int main()
{
    Abstraction* ab = new RefinedAbstraction();
    ab->setImplementor(new ConcreteImplementorA());
    ab->operation();

    ab->setImplementor(new ConcreteImplementorB());
    ab->operation();

    delete ab;
    return 0;
}