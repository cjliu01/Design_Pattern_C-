#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Change
{
public:
    virtual string changeThing(const string &thing) = 0;
    virtual ~Change() = default;
};

class Animal
{
public:
    Animal(): name("����") {}
    Animal(const string &name): name(name) {} 
    void setShoutNum(int num) { this->shoutNum = num; }
    int getShoutNum() { return this->shoutNum; }
    string shout() 
    {
        string result;
        for (int i = 0; i < this->shoutNum; i++)
            result += getShoutSound();
        return "�ҵ����ֽ�" + this->name + " " + result; 
    }
    virtual ~Animal() = default;

protected:
    string name;
    int shoutNum = 3;
    virtual string getShoutSound() = 0;

};

class Cat: public Animal
{
public:
    Cat(): Animal() {}
    Cat(const string &name): Animal(name) {}
    
protected:
    string getShoutSound() override { return string("��"); }
};

class Dog: public Animal
{
public:
    Dog(): Animal() {}
    Dog(const string &name): Animal(name) {}
protected:
    string getShoutSound() override { return string("��"); } 
};

class Sheep: public Animal
{
public:
    Sheep(): Animal() {}
    Sheep(const string &name): Animal(name) {}
protected:
    string getShoutSound() override { return string("��"); } 
};

class Cattle: public Animal
{
public:
    Cattle(): Animal() {}
    Cattle(const string &name): Animal(name) {}
protected:
    string getShoutSound() override { return string("��"); } 
};

class Monkey: public Animal
{
public:
    Monkey(): Animal() {}
    Monkey(const string &name): Animal(name) {}
protected:
    string getShoutSound() override { return string("߾"); } 
};

class MachineCat: public Cat, public Change
{
public:
    MachineCat(): Cat(), Change() {}
    MachineCat(const string &name): Cat(name), Change() {}
    string changeThing(const string& thing) override
    {
        return shout() + string(", �������ܵĿڴ�, �ҿɱ��") + thing;
    }

};

class StoneMonkey: public Monkey, public Change
{
public:
    StoneMonkey(): Monkey(), Change() {}
    StoneMonkey(const string &name): Monkey(name), Change() {}
    string changeThing(const string& thing) override
    {
        return shout() + string(", �������ܵĿڴ�, �ҿɱ��") + thing;
    }
protected:
    string getShoutSound() override { return string("��������Ҳ"); } 
};

int main()
{
    Dog dog1(string("��ë"));
    Cattle cattle(string("С��"));
    Cat cat1(string("С��"));
    Sheep sheep(string("����"));
    Cat cat2(string("����"));
    MachineCat machineCat(string("����"));
    StoneMonkey stoneMonkey(string("�����"));
    vector<Animal*> animals = { &dog1, &cattle, &cat1, &cat2, &sheep, &machineCat, &stoneMonkey };

    for (int i = 0; i < animals.size(); i++)
        cout << animals[i]->shout() << endl;
    cout << machineCat.changeThing(string("���ָ����Ķ���! ")) << endl;
    cout << stoneMonkey.changeThing(string("�𹿰�! "));
    return 0;
}
