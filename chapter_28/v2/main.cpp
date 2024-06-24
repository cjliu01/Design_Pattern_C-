#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Action;
class Person
{
public:
    virtual void accept(Action* visitor) = 0;
    virtual string getClassName() = 0;
};

class Man: public Person
{
public:
    void accept(Action* visitor);
    string getClassName() { return string("Man"); }
};

class Woman: public Person
{
public:
    void accept(Action* visitor);
    string getClassName() { return string("Woman");}
};

class Action
{
public:
    virtual void getManConclusion(Man &man) = 0;
    virtual void getWomanConclusion(Woman &woman) = 0;
    virtual string getClassName() = 0;
};

void Man::accept(Action* visitor) 
{
    visitor->getManConclusion(*this);
}

void Woman::accept(Action* visitor) 
{
    visitor->getWomanConclusion(*this);
}

class Success: public Action
{
public:
    void getManConclusion(Man &man) { cout << man.getClassName() << " " << getClassName() << "ʱ����������һ��ΰ���Ů�ˡ�" << endl; }
    void getWomanConclusion(Woman &woman) { cout << woman.getClassName() << " " << getClassName() << "ʱ����������һ�����ɹ������ˡ�" << endl; }
    string getClassName() { return string("�ɹ�"); }
};

class Failing: public Action
{
public:
    void getManConclusion(Man &man) { cout << man.getClassName() << " " << getClassName() << "ʱ����ͷ�Ⱦƣ�˭Ҳ����Ȱ��" << endl; }
    void getWomanConclusion(Woman &woman) { cout << woman.getClassName() << " " << getClassName() << "ʱ������������˭ҲȰ���ˡ�" << endl; }
    string getClassName() { return string("ʧ��"); }
};

class Amativeness: public Action
{
public:
    void getManConclusion(Man &man) { cout << man.getClassName() << " " << getClassName() << "ʱ�����²���ҲҪװ����" << endl; }
    void getWomanConclusion(Woman &woman) { cout << woman.getClassName() << " " << getClassName() << "ʱ�����¶�Ҳװ��������" << endl; }
    string getClassName() { return string("����"); }
};

class Marriage: public Action
{
public:
    void getManConclusion(Man &man) { cout << man.getClassName() << " " << getClassName() << "ʱ���п�����������Ϸ�ս�ʱ��'����ͽ��'ң���ڡ�" << endl; }
    void getWomanConclusion(Woman &woman) { cout << woman.getClassName() << " " << getClassName() << "ʱ����οԻ�����鳤��·�������������ձ�ƽ����" << endl; }
    string getClassName() { return string("���"); }
};

class ObjectStructure
{
public:
    void attach(Person *element) { elements.push_back(element); }
    void detach(Person *element) 
    {
        for (int i = 0; i < elements.size(); ++i)
        {
            if (elements[i] == element)
            {
                delete elements[i];
                elements.erase(i + elements.begin());
                break;
            }
        }
    }

    void display(Action *vistor)
    {
        for (int i = 0; i < elements.size(); ++i)
            elements[i]->accept(vistor);
    }
    ~ObjectStructure()
    {
        for (int i = 0; i < elements.size(); ++i)
            delete elements[i];
    }

private:
    vector<Person *> elements;

};

int main()
{
    ObjectStructure o;
    o.attach(new Man());
    o.attach(new Woman());

    Success v1;
    o.display(&v1);

    Failing v2;
    o.display(&v2);

    Amativeness v3;
    o.display(&v3);

    Marriage v4;
    o.display(&v4);
    return 0;
}