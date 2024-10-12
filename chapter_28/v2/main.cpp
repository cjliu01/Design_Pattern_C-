#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Action;
class Person
{
public:
    virtual void accept(Action* visitor) = 0;
    virtual string getClassName() = 0;
    virtual ~Person() = default;
};

class Man: public Person
{
public:
    void accept(Action* visitor) override;
    string getClassName() override { return string("Man"); }
};

class Woman: public Person
{
public:
    void accept(Action* visitor) override;
    string getClassName() override { return string("Woman");}
};

class Action
{
public:
    virtual void getManConclusion(Man &man) = 0;
    virtual void getWomanConclusion(Woman &woman) = 0;
    virtual string getClassName() = 0;
    virtual ~Action() = default;
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
    void getManConclusion(Man &man) override { cout << man.getClassName() << " " << getClassName() << "ʱ����������һ��ΰ���Ů�ˡ�" << endl; }
    void getWomanConclusion(Woman &woman) override { cout << woman.getClassName() << " " << getClassName() << "ʱ����������һ�����ɹ������ˡ�" << endl; }
    string getClassName() override { return string("�ɹ�"); }
};

class Failing: public Action
{
public:
    void getManConclusion(Man &man) override { cout << man.getClassName() << " " << getClassName() << "ʱ����ͷ�Ⱦƣ�˭Ҳ����Ȱ��" << endl; }
    void getWomanConclusion(Woman &woman) override { cout << woman.getClassName() << " " << getClassName() << "ʱ������������˭ҲȰ���ˡ�" << endl; }
    string getClassName() override { return string("ʧ��"); }
};

class Amativeness: public Action
{
public:
    void getManConclusion(Man &man) override { cout << man.getClassName() << " " << getClassName() << "ʱ�����²���ҲҪװ����" << endl; }
    void getWomanConclusion(Woman &woman) override { cout << woman.getClassName() << " " << getClassName() << "ʱ�����¶�Ҳװ��������" << endl; }
    string getClassName() override { return string("����"); }
};

class Marriage: public Action
{
public:
    void getManConclusion(Man &man) override { cout << man.getClassName() << " " << getClassName() << "ʱ���п�����������Ϸ�ս�ʱ��'����ͽ��'ң���ڡ�" << endl; }
    void getWomanConclusion(Woman &woman) override { cout << woman.getClassName() << " " << getClassName() << "ʱ����οԻ�����鳤��·�������������ձ�ƽ����" << endl; }
    string getClassName() override { return string("���"); }
};

class ObjectStructure
{
public:
    void attach(shared_ptr<Person> element) { elements.push_back(element); }
    void detach(shared_ptr<Person> element) 
    {
        auto it = find(elements.begin(), elements.end(), element);
        if (it != elements.end())
            elements.erase(it);
        else
            cout << "not found" << endl;
    }

    void display(Action *vistor)
    {
        for (int i = 0; i < elements.size(); ++i)
            elements[i]->accept(vistor);
    }

private:
    vector<shared_ptr<Person>> elements;

};

int main()
{
    ObjectStructure o;
    o.attach(make_shared<Man>());
    o.attach(make_shared<Woman>());

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