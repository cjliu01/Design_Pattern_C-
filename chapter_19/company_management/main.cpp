#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Company
{
public:
    Company(const string& name): name(name) {}
    virtual void add(shared_ptr<Company> c) = 0;
    virtual void remove(shared_ptr<Company> c) = 0;
    virtual void display(int depth) = 0;
    virtual void lineOfDuty() = 0; 
    virtual ~Company() = default;
protected:
    string name;
};

class ConcreteCompany: public Company
{
public:
    ConcreteCompany(const string& name): Company(name) {} 
    void add(shared_ptr<Company> c) override { childen.push_back(c); }
    void remove(shared_ptr<Company> c) override
    {
        auto it = find(childen.begin(), childen.end(), c);
        if (it != childen.end())
            childen.erase(it);
        else
            cout << "not found" << endl;   
    } 

    void display(int depth) override
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
        for (int i = 0; i < childen.size(); ++i)
            childen[i]->display(depth + 2);
    } 

    void lineOfDuty() override
    {
        for (int i = 0; i < childen.size(); ++i)
            childen[i]->lineOfDuty();
    }
private:
    vector<shared_ptr<Company>> childen;
};

class HRDepartment: public Company
{
public:
    HRDepartment(const string& name): Company(name) {}
    void add(shared_ptr<Company> c) override { ; }
    void remove(shared_ptr<Company> c) override { ; }
    void display(int depth) override
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
    }
    void lineOfDuty() override
    {
        cout << name << " Ա����Ƹ��ѵ����" << endl;
    }
};


class FinanceDepartment: public Company
{
public:
    FinanceDepartment(const string& name): Company(name) {}
    void add(shared_ptr<Company> c) override { ; }
    void remove(shared_ptr<Company> c) override { ; }
    void display(int depth) override
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
    }
    void lineOfDuty() override
    {
        cout << name << " ��˾������֧����" << endl;
    }
};


int main()
{
    ConcreteCompany root("�����ܹ�˾");
    root.add(make_shared<HRDepartment>("�ܹ�˾������Դ��"));
    root.add(make_shared<FinanceDepartment>("�ܹ�˾����"));

    shared_ptr<Company> comp = make_shared<ConcreteCompany>("�Ϻ������ֹ�˾");
    comp->add(make_shared<HRDepartment>("�����ֹ�˾������Դ��"));
    comp->add(make_shared<FinanceDepartment>("�����ֹ�˾����"));
    root.add(comp);

    shared_ptr<Company> comp2 = make_shared<ConcreteCompany>("�Ͼ����´�");
    comp2->add(make_shared<HRDepartment>("�Ͼ����´�������Դ��"));
    comp2->add(make_shared<FinanceDepartment>("�Ͼ����´���Դ��"));
    comp->add(comp2);

    shared_ptr<Company> comp3 = make_shared<ConcreteCompany>("���ݰ��´�");
    comp3->add(make_shared<HRDepartment>("���ݰ��´�������Դ��"));
    comp3->add(make_shared<FinanceDepartment>("���ݰ��´�����"));
    comp->add(comp3);

    cout << "�ṹͼ: " << endl;
    root.display(1);
    cout << "ְ��: " << endl;
    root.lineOfDuty();

    return 0;
}