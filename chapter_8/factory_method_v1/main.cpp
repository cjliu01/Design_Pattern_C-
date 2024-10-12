#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Operation
{
public:
    virtual double getResult(double numberA, double numberB) = 0;
    virtual ~Operation() = default;
};

class Add: public Operation
{
public:
    double getResult(double numberA, double numberB) override { return numberA + numberB; }
};

class Sub: public Operation
{
public:
    double getResult(double numberA, double numberB) override { return numberA - numberB; }
};

class Mul: public Operation
{
public:
    double getResult(double numberA, double numberB) override { return numberA * numberB; }
};

class Div: public Operation
{
public:
    double getResult(double numberA, double numberB) override 
    {
        if (numberB == 0)
        {
            cerr << "��������Ϊ0" << endl;
            throw runtime_error("��������Ϊ0");
        }
        return numberA / numberB;
    }
};

class Factory
{
public:
    virtual Operation* createOperation() = 0;
    virtual ~Factory() = default;
};

class AddFactory: public Factory
{
public: 
    Operation* createOperation() override { return new Add(); }
};

class SubFactory: public Factory
{
public:
    Operation* createOperation() override { return new Sub(); }
};

class MulFactory: public Factory
{
public:
    Operation* createOperation() override { return new Mul(); }
};

class DivFactory: public Factory
{
public:
    Operation* createOperation() override { return new Div(); }
};

class OperationFactory
{
public:
    static shared_ptr<Operation> createOperate(char operate)
    {
        shared_ptr<Operation> oper;
        Factory *factory = nullptr;
        switch(operate)
        {
            case '+': factory = new AddFactory(); break;
            case '-': factory = new SubFactory(); break;
            case '*': factory = new MulFactory(); break;
            case '/': factory = new DivFactory(); break;
        }
        oper.reset(factory->createOperation());
        delete factory;
        return oper;
    }
    
};


int main()
{
    double numberA, numberB;
    char operation;
    cout << "����������A ";
    cin >> numberA;
    cout << "����������B ";
    cin >> numberB;
    cout << "�����������(+, -, *, /):";
    cin >> operation;
    shared_ptr<Operation> oper = OperationFactory::createOperate(operation);
    if (oper != 0)
    {
        double result = oper->getResult(numberA, numberB);
        cout << "������=" << result;
    }
    return 0;
}