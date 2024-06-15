#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Company
{
public:
    Company(const string& name): name(name) {}
    virtual void add(Company* c) = 0;
    virtual void remove(Company* c) = 0;
    virtual void display(int depth) = 0;

    virtual void lineOfDuty() = 0; 
protected:
    string name;
};

class ConcreteCompany: public Company
{
public:
    ConcreteCompany(const string& name): Company(name) {} 
    void add(Company *c) { childen.push_back(c); }
    void remove(Company *c) 
    {
        for (vector<Company *>::iterator it = childen.begin(); it != childen.end(); ++it)
        {
            if (*it == c)
            {
                delete c;    
                childen.erase(it);
            }
        }
    } 
    void display(int depth)
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
        for (int i = 0; i < childen.size(); ++i)
            childen[i]->display(depth + 2);
    } 
    void lineOfDuty() 
    {
        for (int i = 0; i < childen.size(); ++i)
            childen[i]->lineOfDuty();
    }
    ~ConcreteCompany() 
    {
        for (int i = 0; i < childen.size(); ++i)
            delete childen[i];
    }

private:
    vector<Company *> childen;
};

class HRDepartment: public Company
{
public:
    HRDepartment(const string& name): Company(name) {}
    void add(Company *c) { ; }
    void remove(Company *c) { ; }
    void display(int depth) 
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
    }
    void lineOfDuty()
    {
        cout << name << " Ա����Ƹ��ѵ����" << endl;
    }
};


class FinanceDepartment: public Company
{
public:
    FinanceDepartment(const string& name): Company(name) {}
    void add(Company *c) { ; }
    void remove(Company * c) { ; }
    void display(int depth)
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
    }
    void lineOfDuty()
    {
        cout << name << " ��˾������֧����" << endl;
    }
};


int main()
{
    ConcreteCompany root(string("�����ܹ�˾"));
    root.add(new HRDepartment(string("�ܹ�˾������Դ��")));
    root.add(new FinanceDepartment(string("�ܹ�˾����")));

    ConcreteCompany *comp = new ConcreteCompany(string("�Ϻ������ֹ�˾"));
    comp->add(new HRDepartment(string("�����ֹ�˾������Դ��")));
    comp->add(new FinanceDepartment(string("�����ֹ�˾����")));
    root.add(comp);

    ConcreteCompany *comp2 = new ConcreteCompany(string("�Ͼ����´�"));
    comp2->add(new HRDepartment(string("�Ͼ����´�������Դ��")));
    comp2->add(new FinanceDepartment(string("�Ͼ����´���Դ��")));
    comp->add(comp2);

    ConcreteCompany *comp3 = new ConcreteCompany(string("���ݰ��´�"));
    comp3->add(new HRDepartment(string("���ݰ��´�������Դ��")));
    comp3->add(new FinanceDepartment(string("���ݰ��´�����")));
    comp->add(comp3);

    cout << "�ṹͼ: " << endl;
    root.display(1);
    cout << "ְ��: " << endl;
    root.lineOfDuty();

    return 0;
}