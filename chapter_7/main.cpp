#include<iostream>
#include<string>

using namespace std;

class GiveGift
{
public:
    virtual void giveDolls() = 0;
    virtual void giveFlowers() = 0;
    virtual void giveChocolate() = 0;
};

class SchoolGril
{
public:
    SchoolGril(const string& name): name(name) {}
    string getName() { return this->name; }
    void setName(const string& name) { this->name = name; }
private:
    string name;
};

class Pursuit: public GiveGift
{
public:
    Pursuit(const SchoolGril& mm): mm(mm) {}
    void giveDolls() { cout << mm.getName() << ",��ã����������ޡ�" << endl; }
    void giveFlowers() { cout << mm.getName() << ",��ã������ʻ���" << endl; }
    void giveChocolate() { cout << mm.getName() << ",��ã������ɿ�����" << endl; }
private:
    SchoolGril mm;
};

class Proxy: public GiveGift
{
public:
    Proxy(const SchoolGril& mm): pursuit(mm) {}
    void giveDolls() { pursuit.giveDolls(); }
    void giveFlowers() { pursuit.giveFlowers(); }
    void giveChocolate() { pursuit.giveChocolate(); }

private:
    Pursuit pursuit;
};

int main()
{
    SchoolGril grilLjj(string("���"));

    Proxy boyDl(grilLjj);
    boyDl.giveDolls();
    boyDl.giveFlowers();
    boyDl.giveChocolate();

    return 0;
}