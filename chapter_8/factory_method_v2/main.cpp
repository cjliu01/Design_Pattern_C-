#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Operation
{
public:
    virtual double getResult(double numberA, double numberB) = 0;
};

class Add: public Operation
{
public:
    double getResult(double numberA, double numberB) { return numberA + numberB; }
};

class Sub: public Operation
{
public:
    double getResult(double numberA, double numberB) { return numberA - numberB; }
};

class Mul: public Operation
{
public:
    double getResult(double numberA, double numberB) { return numberA * numberB; }
};

class Div: public Operation
{
public:
    double getResult(double numberA, double numberB) 
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
    double getResult(double numberA, double numberB)
    {
        return pow(numberA, numberB);
    }
};

class Log: public Operation
{
public:
    double getResult(double numberA, double numberB)
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
    virtual Operation* createOperation(char operate) = 0;
};

class BasicFactory: public Factory
{
public:
    Operation* createOperation(char operate)
    {
        Operation* operation = 0;
        switch(operate)
        {
            case '+': operation = new Add(); break;
            case '-': operation = new Sub(); break;
            case '*': operation = new Mul(); break;
            case '/': operation = new Div(); break;
        }
        return operation;
    }

};

class AdvancedFactory: public Factory
{
public:
    Operation* createOperation(char operate)
    {
        Operation* oper = 0;
        switch(operate)
        {
            case 'p': oper = new Pow(); break;
            case 'l': oper = new Log(); break;
        }
        return oper;
    }
};

class OperationFactory
{
public:
    static Operation* createOperate(char operate)
    {
        Operation *oper = 0;
        Factory *factory = 0;
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
    Operation *oper = OperationFactory::createOperate(operation);
    if (oper != 0)
    {
        double result = oper->getResult(numberA, numberB);
        cout << "������=" << result;
        delete oper;
        oper = 0;
    }
    return 0;
}