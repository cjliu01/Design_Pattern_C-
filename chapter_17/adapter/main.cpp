#include<iostream>
#include<string>
using namespace std;

class Player
{
public:
    Player(const string& name): name(name) {}
    virtual void attack() = 0;
    virtual void defence() = 0;
protected:
    string name;
};

class Forwards: public Player
{
public:
    Forwards(const string& name): Player(name) {}
    void attack() { cout << "ǰ�� " << name << " ���� " << endl; }
    void defence() { cout << "ǰ�� " << name << " ���� " << endl; }
};

class Center: public Player
{
public:
    Center(const string& name): Player(name) {}
    void attack() { cout << "�з� " << name << " ���� " << endl; }
    void defence() { cout << "�з� " << name << " ���� " << endl; }
};

class Guards: public Player
{
public:
    Guards(const string& name): Player(name) {}
    void attack() { cout << "���� " << name << " ���� " << endl; }
    void defence() { cout << "���� " << name << " ���� " << endl; }
};

class ForeignCenter
{
public:
    string getName() { return name; }
    void setName(const string& name) { this->name = name; }
    void jingong() { cout << "�⼮�з� " << name << " ���� " << endl; }
    void fangshou() { cout << "�⼮�з� " << name << " ���� " << endl; }
private: 
    string name;
};

class Translator: public Player
{
public:
    Translator(const string& name): Player(name) { foreignCenter.setName(name); }
    void attack() { foreignCenter.jingong(); }
    void defence() { foreignCenter.fangshou(); }

private:
    ForeignCenter foreignCenter;
};

int main()
{
    Player* forwards = new Forwards(string("�͵ٶ�"));
    forwards->attack();
    Player* guards = new Guards(string("��˸��׵�"));
    guards->defence(); 
    Player* center = new Translator(string("Ҧ��"));

    center->attack();
    center->defence();

    delete forwards;
    delete guards;
    delete center;
    return 0;
}