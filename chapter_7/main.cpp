#include <iostream>
#include <string>

using namespace std;

class GiveGift
{
public:
    virtual void giveDolls() = 0;
    virtual void giveFlowers() = 0;
    virtual void giveChocolate() = 0;
    virtual ~GiveGift() = default;
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
    void giveDolls() override { cout << mm.getName() << ",��ã����������ޡ�" << endl; }
    void giveFlowers() override { cout << mm.getName() << ",��ã������ʻ���" << endl; }
    void giveChocolate() override { cout << mm.getName() << ",��ã������ɿ�����" << endl; }
private:
    SchoolGril mm;
};

class Proxy: public GiveGift
{
public:
    Proxy(const SchoolGril& mm): pursuit(mm) {}
    void giveDolls() override { pursuit.giveDolls(); }
    void giveFlowers() override { pursuit.giveFlowers(); }
    void giveChocolate() override { pursuit.giveChocolate(); }

private:
    Pursuit pursuit;
};

int main()
{
    SchoolGril grilLjj("���");

    Proxy boyDl(grilLjj);
    boyDl.giveDolls();
    boyDl.giveFlowers();
    boyDl.giveChocolate();

    return 0;
}