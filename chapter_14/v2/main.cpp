#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Observer;

class Secretary
{
public:
    Secretary(const string& name): name(name) {}
    void attach(Observer &observer);
    void detach(Observer &observer);
    void notifyEmployee();
    string getAction() { return action; } 
    void setAction(const string &value) { action = value; }
    string name;
private:
    vector<Observer *> observers;
    string action;
};

class Observer
{
public:
    Observer(const string& name, Secretary& secretary): name(name), sub(secretary) {}
    virtual void update() = 0;
    bool operator==(const Observer& rhs) { return (this->name == rhs.name) && (this->sub.name == rhs.sub.name); }
    bool operator!=(const Observer& rhs) { return !(*this == rhs); }
    virtual ~Observer() = default;
protected:
    string name;
    Secretary &sub;
};

class StockObserver: public Observer
{
public:
    StockObserver(const string& name, Secretary& sub): Observer(name, sub) {}
    void update() override { cout << sub.name << ":" << sub.getAction() << "! " << name << ",��رչ�Ʊ����,�Ͻ�������" << endl; }
};

class NBAObserver: public Observer
{
public:
    NBAObserver(const string& name, Secretary& sub): Observer(name, sub) {}
    void update() override { cout << sub.name << ":" << sub.getAction() << "! " << name << ",��ر�NBAֱ��,�Ͻ�������" << endl; }
};

void Secretary::attach(Observer &observer)
{
    observers.push_back(&observer);
}

void Secretary::detach(Observer &observer)
{
    auto it = find(observers.begin(), observers.end(), &observer);
    if (it != observers.end())
        observers.erase(it);
    else
        cout << "δ�ҵ��ù۲���" << endl;
}

void Secretary::notifyEmployee()
{
    for (int i = 0; i < observers.size(); ++i)
        observers[i]->update();
}

int main()
{
    Secretary secretary1(string("ͯ�ӆ�"));

    StockObserver employee1(string("κ���"), secretary1);
    NBAObserver employee2(string("�׹ܲ�"), secretary1);

    secretary1.attach(employee1);
    secretary1.attach(employee2);

    secretary1.setAction(string("�ϰ������"));
    secretary1.notifyEmployee();
    return 0;
}