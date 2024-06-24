#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Person
{
public:
    string getAction() { return action; }
    void setAction(const string& action) { this->action = action; }
    virtual void getConclusion() = 0;
    virtual string getClassName() = 0;
protected:
    string name;
    string action;
};

class Man: public Person
{
public:
    void getConclusion() 
    {
        if (action == string("�ɹ�"))
            cout << getClassName() << action << "ʱ����������һ��ΰ���Ů��" << endl;
        else if (action == string("ʧ��"))
            cout << getClassName() << action << "ʱ����ͷ�Ⱦƣ�˭Ҳ����Ȱ��" << endl;
        else if (action == string("����"))
            cout << getClassName() << action << "ʱ�����²���ҲҪװ����" << endl;
    }
    string getClassName() { return string("����"); }
};

class Woman: public Person
{
public:
    void getConclusion() 
    {
        if (action == string("�ɹ�"))
            cout << getClassName() << action << "ʱ����������һ�����ɹ������ˡ�" << endl;
        else if (action == string("ʧ��"))
            cout << getClassName() << action << "ʱ������������˭ҲȰ���ˡ�" << endl;
        else if (action == string("����"))
            cout << getClassName() << action << "ʱ�����¶�Ҳװ��������" << endl;
    }
    string getClassName() { return string("Ů��"); }
};

int main()
{
    vector<Person *> persons;
    Person *man1 = new Man();
    man1->setAction(string("�ɹ�"));
    persons.push_back(man1);

    Person* woman1 = new Woman();
    woman1->setAction(string("�ɹ�"));
    persons.push_back(woman1);

    Person* man2 = new Man();
    man2->setAction(string("ʧ��"));
    persons.push_back(man2);

    Person* woman2 = new Woman();
    woman2->setAction(string("ʧ��"));
    persons.push_back(woman2);

    Person* man3 = new Man();
    man3->setAction(string("����"));
    persons.push_back(man3);

    Person* woman3 = new Woman();
    woman3->setAction(string("����"));
    persons.push_back(woman3);

    for (int i = 0; i < persons.size(); ++i)
    {
        persons[i]->getConclusion();
        delete persons[i];
    }
    return 0;
}