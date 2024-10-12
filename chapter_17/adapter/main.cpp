#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Player
{
public:
    Player(const string& name): name(name) {}
    virtual void attack() = 0;
    virtual void defence() = 0;
    virtual ~Player() = default;
protected:
    string name;
};

class Forwards: public Player
{
public:
    Forwards(const string& name): Player(name) {}
    void attack() override { cout << "ǰ�� " << name << " ���� " << endl; }
    void defence() override { cout << "ǰ�� " << name << " ���� " << endl; }
};

class Center: public Player
{
public:
    Center(const string& name): Player(name) {}
    void attack() override { cout << "�з� " << name << " ���� " << endl; }
    void defence() override { cout << "�з� " << name << " ���� " << endl; }
};

class Guards: public Player
{
public:
    Guards(const string& name): Player(name) {}
    void attack() override { cout << "���� " << name << " ���� " << endl; }
    void defence() override { cout << "���� " << name << " ���� " << endl; }
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
    void attack() override { foreignCenter.jingong(); }
    void defence() override { foreignCenter.fangshou(); }

private:
    ForeignCenter foreignCenter;
};

int main()
{
    shared_ptr<Player> forwards = make_shared<Forwards>("�͵ٶ�");
    forwards->attack();
    shared_ptr<Player> guards = make_shared<Guards>("��˸��׵�");
    guards->defence(); 
    shared_ptr<Player> center = make_shared<Translator>("Ҧ��");

    center->attack();
    center->defence();

    return 0;
}