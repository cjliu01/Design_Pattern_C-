#include <iostream>

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
    virtual ~PersonBuilder() = default;
};

class PersonThinBuilder: public PersonBuilder
{
public:
    void buildHead() override { cout << "�������˵�ͷ" << endl; }
    void buildBody() override { cout << "�������˵�����" << endl; }
    void buildArmLeft() override { cout << "�������˵�����" << endl; }
    void buildArmRight() override { cout << "�������˵�����" << endl; }
    void buildLegLeft() override { cout << "�������˵����" << endl; }
    void buildLegRight() override { cout << "�������˵��ҽ�" << endl; }
};

class PersonFatBuilder: public PersonBuilder
{
public:
    void buildHead() override { cout << "�������˵�ͷ" << endl; }
    void buildBody() override { cout << "�������˵�����" << endl; }
    void buildArmLeft() override { cout << "�������˵�����" << endl; }
    void buildArmRight() override { cout << "�������˵�����" << endl; }
    void buildLegLeft() override { cout << "�������˵����" << endl; }
    void buildLegRight() override { cout << "�������˵��ҽ�" << endl; }
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
