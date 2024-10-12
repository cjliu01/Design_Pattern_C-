#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    string getAction() const { return action; }
    void setAction(const string& action) { this->action = action; }
    virtual void getConclusion() = 0;
    virtual string getClassName() = 0;
    virtual ~Person() = default;
    
protected:
    string name;
    string action;
};

class Man: public Person
{
public:
    void getConclusion() override
    {
        if (action == string("�ɹ�"))
            cout << getClassName() << action << "ʱ����������һ��ΰ���Ů��" << endl;
        else if (action == string("ʧ��"))
            cout << getClassName() << action << "ʱ����ͷ�Ⱦƣ�˭Ҳ����Ȱ��" << endl;
        else if (action == string("����"))
            cout << getClassName() << action << "ʱ�����²���ҲҪװ����" << endl;
    }
    string getClassName() override { return string("����"); }
};

class Woman: public Person
{
public:
    void getConclusion() override
    {
        if (action == string("�ɹ�"))
            cout << getClassName() << action << "ʱ����������һ�����ɹ������ˡ�" << endl;
        else if (action == string("ʧ��"))
            cout << getClassName() << action << "ʱ������������˭ҲȰ���ˡ�" << endl;
        else if (action == string("����"))
            cout << getClassName() << action << "ʱ�����¶�Ҳװ��������" << endl;
    }
    string getClassName() override { return string("Ů��"); }
};

int main()
{
    vector<shared_ptr<Person>> persons;
    shared_ptr<Person> man1 = make_shared<Man>();
    man1->setAction(string("�ɹ�"));
    persons.push_back(man1);

    shared_ptr<Person> woman1 = make_shared<Woman>();
    woman1->setAction(string("�ɹ�"));
    persons.push_back(woman1);

    shared_ptr<Person> man2 = make_shared<Man>();
    man2->setAction(string("ʧ��"));
    persons.push_back(man2);

    shared_ptr<Person> woman2 = make_shared<Woman>();
    woman2->setAction(string("ʧ��"));
    persons.push_back(woman2);

    shared_ptr<Person> man3 = make_shared<Man>();
    man3->setAction(string("����"));
    persons.push_back(man3);

    shared_ptr<Person> woman3 = make_shared<Woman>();
    woman3->setAction(string("����"));
    persons.push_back(woman3);

    for (auto person: persons)
        person->getConclusion();
    return 0;
}