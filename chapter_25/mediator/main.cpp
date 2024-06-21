#include<iostream>
#include<string>
#include<typeinfo>

using namespace std;

class Colleague;
class Mediator
{
public:
    virtual void send(const string& message, Colleague& colleague) = 0;
};

class Colleague
{
public:
    Colleague(Mediator* mediator=nullptr): mediator(mediator) {}
    virtual string getClassName() = 0;
protected:
    Mediator* mediator;
};

class ConcreteColleague1: public Colleague
{
public:
    ConcreteColleague1(Mediator* mediator): Colleague(mediator) {}
    void send(const string& message) { mediator->send(message, *this); }
    void notify(const string& message) { cout << "ͬ��1�õ���Ϣ: " << message << endl; }
    string getClassName() { return string("ConcreteColleague1"); }

};

class ConcreteColleague2: public Colleague
{
public:
    ConcreteColleague2(Mediator* mediator): Colleague(mediator) {}
    void send(const string& message) { mediator->send(message, *this); }
    void notify(const string& message) { cout << "ͬ��2�õ���Ϣ: " << message << endl; }
    string getClassName() { return string("ConcreteColleague2"); }


};

class ConcreteMediator: public Mediator
{
public:
    ConcreteMediator(): colleague1(nullptr), colleague2(nullptr) {} 
    void setColleague1(ConcreteColleague1& value) { colleague1 = value; }
    void setColleague2(ConcreteColleague2& value) { colleague2 = value; }
    void send(const string& message, Colleague& colleague)
    {
        if (colleague.getClassName() == colleague1.getClassName())
            colleague2.notify(message);
        else 
            colleague1.notify(message);
    }
protected:
    ConcreteColleague1 colleague1;
    ConcreteColleague2 colleague2;
};

int main()
{
    ConcreteMediator mediator;
    ConcreteColleague1 c1(&mediator);
    ConcreteColleague2 c2(&mediator);
    
    mediator.setColleague1(c1);
    mediator.setColleague2(c2);

    c1.send(string("�Թ�������?"));
    c2.send(string("û����,��������?"));
    c1.send(string("��!"));

    return 0;
}