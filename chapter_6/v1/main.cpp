#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(const string& name): name(name) {}

    void wearTShirts() { cout << "��T��"; }
    void wearBigTrouser() { cout << "���"; }
    void wearSneakers() { cout << "��Ь"; }
    void wearSuit() { cout << "��װ"; }
    void wearTie() { cout << "���"; }
    void wearLeatherShoes() { cout << "ƤЬ"; }
    void show() { cout << "װ���" << name << endl; }

private:
    string name;
};


int main()
{
    Person xc("С��");
    cout << "��һ��װ��: ";
    xc.wearTShirts();
    xc.wearBigTrouser();
    xc.wearSneakers();
    xc.show();

    cout << "�ڶ���װ��: ";
    xc.wearSuit();
    xc.wearTie();
    xc.wearLeatherShoes();
    xc.show();

    return 0;
}