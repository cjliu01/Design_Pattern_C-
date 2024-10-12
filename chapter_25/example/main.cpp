#include <iostream>

using namespace std;

class UnitedNations;
class Country
{
public:
    Country(UnitedNations* unitedNations=nullptr): unitedNations(unitedNations) {}
    virtual string getClassName() = 0;
    virtual ~Country() = default;
protected:
    UnitedNations* unitedNations;
};

class UnitedNations
{
public:
    virtual void declare(const string& message, Country& country) = 0;
    virtual ~UnitedNations() = default;
};

class USA: public Country
{
public:
    USA(UnitedNations* unitedNations): Country(unitedNations) {}

    void declare(const string& message) { unitedNations->declare(message, *this);}
    void getMessage(const string& message) { cout << "������öԷ���Ϣ" << message << endl; }

    string getClassName() override { return string("USA"); }
};

class Iraq: public Country
{
public:
    Iraq(UnitedNations* unitedNations): Country(unitedNations) {}

    void declare(const string& message) { unitedNations->declare(message, *this); }
    void getMessage(const string& message) { cout << "�����˻�öԷ���Ϣ" << message << endl; }

    string getClassName() override { return string("Iraq"); }
};

class UnitedNationsSecurityCouncil: public UnitedNations
{
public:
    UnitedNationsSecurityCouncil(): countryUSA(nullptr), countryIraq(nullptr) {}
    void setUSA(USA& value) { countryUSA = value; }
    void setIraq(Iraq& value) { countryIraq = value; }

    void declare(const string& message, Country& country) override
    {
        if (country.getClassName() == countryUSA.getClassName())
            countryIraq.getMessage(message);
        else
            countryUSA.getMessage(message);
    }
private:
    USA countryUSA;
    Iraq countryIraq;
};

int main()
{
    UnitedNationsSecurityCouncil UNSC;
    USA c1(&UNSC);
    Iraq c2(&UNSC);

    UNSC.setUSA(c1);
    UNSC.setIraq(c2);

    c1.declare(string("��׼���ƺ�����,�����Ҫ����ս��!"));
    c2.declare(string("����û�к�����,Ҳ�������ԡ�"));

    return 0;
}