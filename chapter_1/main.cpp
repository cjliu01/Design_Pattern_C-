#include <iostream>
#include <stdexcept>
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

class OperationFactory
{
public:
    static shared_ptr<Operation> createOperate(char operate)
    {   
        Operation *oper = nullptr;
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
    if (oper != nullptr)
    {
        double result = oper->getResult(numberA, numberB);
        cout << "������=" << result;
    }
    return 0;
}