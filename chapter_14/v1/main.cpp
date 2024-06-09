#include<iostream>
#include<string>
#include<vector>

using namespace std;

class StockObserver;

class Secretary
{
public:
    Secretary(const string& name): name(name) {}
    string getAction() { return action; }
    void setAction(const string& value) { action = value; }
    void attach(StockObserver& observer);
    void notifyEmployee();

    string name;
private:
    vector<StockObserver *> observers;
    string action;

};

class StockObserver
{
public:
    StockObserver(const string& name, Secretary& secretary): name(name), sub(secretary) {}
    void update() { cout << sub.name << ": " << sub.getAction() << "!" << name << ",��رչ�Ʊ����,�Ͽ칤����" << endl; }
private:
    string name;
    Secretary &sub;
};

void Secretary::attach(StockObserver& observer) { observers.push_back(&observer); }
void Secretary::notifyEmployee() 
{
    for (int i = 0; i < observers.size(); ++i)
        observers[i]->update();
}


int main()
{
    Secretary secretary1(string("ͯ�ӆ�"));

    StockObserver employee1(string("κ���"), secretary1);
    StockObserver employee2(string("�׹ܲ�"), secretary1);

    secretary1.attach(employee1);
    secretary1.attach(employee2);

    secretary1.setAction(string("�ϰ������"));
    secretary1.notifyEmployee();
    return 0;
}