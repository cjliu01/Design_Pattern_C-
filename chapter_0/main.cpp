#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Change
{
public:
    virtual string changeThing(const string &thing) = 0;
};

class Animal
{
public:
    Animal() { this->name = string("����"); }
    Animal(const string &name) { this->name = name; }
    void setShoutNum(int num) { this->shoutNum = num; }
    int getShoutNum() { return this->shoutNum; }
    string shout() 
    {
        string result("");
        for (int i = 0; i < this->shoutNum; i++)
            result += getShoutSound();
        return "�ҵ����ֽ�" + this->name + " " + result; 
    }

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
    string getShoutSound() { return string("��"); }
};

class Dog: public Animal
{
public:
    Dog(): Animal() {}
    Dog(const string &name): Animal(name) {}
protected:
    string getShoutSound() { return string("��"); } 
};

class Sheep: public Animal
{
public:
    Sheep(): Animal() {}
    Sheep(const string &name): Animal(name) {}
protected:
    string getShoutSound() { return string("��"); } 
};

class Cattle: public Animal
{
public:
    Cattle(): Animal() {}
    Cattle(const string &name): Animal(name) {}
protected:
    string getShoutSound() { return string("��"); } 
};

class Monkey: public Animal
{
public:
    Monkey(): Animal() {}
    Monkey(const string &name): Animal(name) {}
protected:
    string getShoutSound() { return string("߾"); } 
};

class MachineCat: public Cat, public Change
{
public:
    MachineCat(): Cat(), Change() {}
    MachineCat(const string &name): Cat(name), Change() {}
    string changeThing(const string& thing)
    {
        return shout() + string(", �������ܵĿڴ�, �ҿɱ��") + thing;
    }

};

class StoneMonkey: public Monkey, public Change
{
public:
    StoneMonkey(): Monkey(), Change() {}
    StoneMonkey(const string &name): Monkey(name), Change() {}
    string changeThing(const string& thing)
    {
        return shout() + string(", �������ܵĿڴ�, �ҿɱ��") + thing;
    }
protected:
    string getShoutSound() { return string("��������Ҳ"); } 
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
    vector<Animal*> animals;
    animals.push_back(&dog1);
    animals.push_back(&cattle);
    animals.push_back(&cat1);
    animals.push_back(&cat2);
    animals.push_back(&sheep);
    animals.push_back(&stoneMonkey);

    for (int i = 0; i < animals.size(); i++)
        cout << (*animals[i]).shout() << endl;
    cout << machineCat.changeThing(string("���ָ����Ķ���! ")) << endl;
    cout << stoneMonkey.changeThing(string("�𹿰�! "));
    return 0;
}
