#include <iostream>
#include <string>
#include <cmath>
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

class Pow: public Operation
{
public:
    double getResult(double numberA, double numberB) override
    {
        return pow(numberA, numberB);
    }
};

class Log: public Operation
{
public:
    double getResult(double numberA, double numberB) override
    {
        if (numberA <= 0 || numberB <= 0)
        {
            cerr << "log��������Ϊ����" << endl;
            throw runtime_error("log��������Ϊ����");
        }
        return log(numberB) / log(numberA);
    }
};

class Factory
{
public:
    virtual shared_ptr<Operation> createOperation(char operate) = 0;
    virtual ~Factory() = default;
};

class BasicFactory: public Factory
{
public:
    shared_ptr<Operation> createOperation(char operate)
    {
        Operation* oper = nullptr;
        switch(operate)
        {
            case '+': oper = new Add(); break;
            case '-': oper = new Sub(); break;
            case '*': oper = new Mul(); break;
            case '/': oper = new Div(); break;
        }
        return shared_ptr<Operation>(oper);
    }
};

class AdvancedFactory: public Factory
{
public:
    shared_ptr<Operation> createOperation(char operate)
    {
        Operation* oper = nullptr;
        switch(operate)
        {
            case 'p': oper = new Pow(); break;
            case 'l': oper = new Log(); break;
        }
        return shared_ptr<Operation>(oper);
    }
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
            case '+':
            case '-':
            case '*':
            case '/':
                factory = new BasicFactory();
            case 'p':
            case 'l':
                factory = new AdvancedFactory();
        }
        oper = factory->createOperation(operate);
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
    cout << "�����������(+, -, *, /, p, l):";
    cin >> operation;
    shared_ptr<Operation> oper = OperationFactory::createOperate(operation);
    if (oper != nullptr)
    {
        double result = oper->getResult(numberA, numberB);
        cout << "������=" << result;
    }
    return 0;
}