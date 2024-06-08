#include<iostream>

using namespace std;

class PersonBuilder
{
public:
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildArmLeft() = 0;
    virtual void buildArmRight() = 0;
    virtual void buildLegLeft() = 0;
    virtual void buildLegRight() = 0;
};

class PersonThinBuilder: public PersonBuilder
{
public:
    void buildHead() { cout << "�������˵�ͷ" << endl; }
    void buildBody() { cout << "�������˵�����" << endl; }
    void buildArmLeft() { cout << "�������˵�����" << endl; }
    void buildArmRight() { cout << "�������˵�����" << endl; }
    void buildLegLeft() { cout << "�������˵����" << endl; }
    void buildLegRight() { cout << "�������˵��ҽ�" << endl; }
};

class PersonFatBuilder: public PersonBuilder
{
public:
    void buildHead() { cout << "�������˵�ͷ" << endl; }
    void buildBody() { cout << "�������˵�����" << endl; }
    void buildArmLeft() { cout << "�������˵�����" << endl; }
    void buildArmRight() { cout << "�������˵�����" << endl; }
    void buildLegLeft() { cout << "�������˵����" << endl; }
    void buildLegRight() { cout << "�������˵��ҽ�" << endl; }
};

class PersonDirector
{
public:
    PersonDirector(PersonBuilder& pb): pb(pb) {} 
    void createPerson()
    {
        pb.buildHead();
        pb.buildBody();
        pb.buildArmLeft();
        pb.buildArmRight();
        pb.buildLegLeft();
        pb.buildLegRight();
    }
private:
    PersonBuilder& pb;
};

int main()
{
    PersonThinBuilder gThin;
    PersonFatBuilder gFat;
    
    PersonDirector pdThin(gThin);
    pdThin.createPerson();

    PersonDirector pdFat(gFat);
    pdFat.createPerson();

    return 0;
}
