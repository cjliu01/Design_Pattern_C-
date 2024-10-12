#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Observer;

class Subject
{
public:
    string name;
    Subject(const string& name): name(name) {}
    void attach(Observer& observer);
    void detach(Observer& observer);
    void notifyEmployee();
    string getAction() { return action; }
    void setAction(const string& value) { this->action = value; }
    virtual ~Subject() = default;
private:
    vector<Observer *> observers;
    string action;
};

class Boss: public Subject
{
public:
    Boss(const string& name): Subject(name) {}
    //using Subject::Subject;
};


class Secretary: public Subject
{
public:
    Secretary(const string& name): Subject(name) {}
};

class Observer
{
public:
    Observer(const string& name, Subject& sub): name(name), sub(sub) {}
    bool operator==(const Observer& rhs) { return (this->name == rhs.name) && (this->sub.name == rhs.sub.name); }
    bool operator!=(const Observer& rhs) { return !(*this == rhs); }
    virtual void update() = 0;
    virtual ~Observer() = default;
protected:
    string name;
    Subject &sub;
};

void Subject::attach(Observer& observer)
{
    observers.push_back(&observer);
}

void Subject::detach(Observer& observer)
{
    auto it = find(observers.begin(), observers.end(), &observer);
    if (it != observers.end())
        observers.erase(it);
    else
        cout << "δ�ҵ��ù۲���" << endl;
}

void Subject::notifyEmployee()
{
    for (int i = 0; i < observers.size(); ++i)
    {
        observers[i]->update();
    }
}

class StockObserver: public Observer
{
public:
    StockObserver(const string& name, Subject& sub): Observer(name, sub) {}
    void update() override { cout << sub.name << ":" << sub.getAction() << "! " << name << ",��رչ�Ʊ����,�Ͻ�������" << endl; }
};

class NBAObserver: public Observer
{
public:
    NBAObserver(const string& name, Subject& sub): Observer(name, sub) {}
    void update() override { cout << sub.name << ":" << sub.getAction() << "! " << name << ",��ر�NBAֱ��,�Ͻ�������" << endl; }
};

int main()
{
    Boss boss(string("������"));

    StockObserver employee1(string("κ���"), boss);
    StockObserver employee2(string("�׹ܲ�"), boss);
    NBAObserver employee3(string("������"), boss);

    boss.attach(employee1);
    boss.attach(employee2);
    boss.attach(employee3);

    boss.detach(employee2);

    boss.setAction(string("�Һ�����������"));
    boss.notifyEmployee();

    return 0;
}
