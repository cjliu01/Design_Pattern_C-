#include<iostream>
#include<stdexcept>

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

class OperationFactory
{
public:
    static Operation* createOperate(char operate)
    {   
        Operation* oper = 0;
        switch(operate)
        {
            case '+': oper = new Add(); break;
            case '-': oper = new Sub(); break;
            case '*': oper = new Mul(); break;
            case '/': oper = new Div(); break;
        }
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