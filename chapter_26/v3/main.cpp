#include<iostream>
#include<string>
#include<map>

using namespace std;

class User
{
public:
    User(const string& value): name(value) {} 
    string getName() { return name; } 
private:
    string name;
};

class WebSite
{
public:
    virtual void use(User user) = 0;
};

class ConcreteWebSite: public WebSite
{
public:
    ConcreteWebSite(const string& name): name(name) {}
    void use(User user) { cout << "��վ����: " << name << "�û�: " << user.getName() << endl; }
private:
    string name;
};

class WebSiteFactory
{
public:
    WebSite* getWebSiteCategory(const string& key) 
    { 
        map<string, WebSite*>::iterator it = flyweights.find(key);
        if (it == flyweights.end())
            flyweights[key] = new ConcreteWebSite(key); 
        return flyweights[key];   
    }
    ~WebSiteFactory() 
    {
        for (map<string, WebSite*>::iterator it = flyweights.begin(); it != flyweights.end(); ++it)
            delete it->second;
    }
    int getWebSiteCount() { return flyweights.size(); }
private:
    map<string, WebSite*> flyweights;
};

int main()
{
    WebSiteFactory f;
    WebSite* fx = f.getWebSiteCategory(string("��Ʒչʾ"));
    fx->use(User(string("С��")));
    WebSite* fy = f.getWebSiteCategory(string("��Ʒչʾ"));
    fy->use(User(string("����")));
    WebSite* fz = f.getWebSiteCategory(string("��Ʒչʾ"));
    fz->use(User(string("����")));

    WebSite* fl = f.getWebSiteCategory(string("����"));
    fl->use(User(string("����ͯ")));
    WebSite* fm = f.getWebSiteCategory(string("����"));
    fm->use(User(string("�ҹ�����")));
    WebSite* fn = f.getWebSiteCategory(string("����"));
    fn->use(User(string("�Ϻ�����")));

    cout << "��վ��������Ϊ:" << f.getWebSiteCount() << endl;
    return 0;
}