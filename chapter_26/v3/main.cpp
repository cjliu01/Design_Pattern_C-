#include <iostream>
#include <memory>
#include <string>
#include <map>

using namespace std;

class User
{
public:
    User(const string& value): name(value) {} 
    string getName() const { return name; } 
private:
    string name;
};

class WebSite
{
public:
    virtual void use(const User& user) = 0;
    virtual ~WebSite() = default;
};

class ConcreteWebSite: public WebSite
{
public:
    ConcreteWebSite(const string& name): name(name) {}
    void use(const User& user) { cout << "��վ����: " << name << "�û�: " << user.getName() << endl; }
private:
    string name;
};

class WebSiteFactory
{
public:
    shared_ptr<WebSite> getWebSiteCategory(const string& key) 
    { 
        auto it = flyweights.find(key);
        if (it == flyweights.end())
            flyweights[key] = make_shared<ConcreteWebSite>(key); 
        return flyweights[key];   
    }
    int getWebSiteCount() { return flyweights.size(); }

private:
    map<string, shared_ptr<WebSite>> flyweights;
};

int main()
{
    WebSiteFactory f;
    shared_ptr<WebSite> fx = f.getWebSiteCategory(string("��Ʒչʾ"));
    fx->use(User(string("С��")));
    shared_ptr<WebSite> fy = f.getWebSiteCategory(string("��Ʒչʾ"));
    fy->use(User(string("����")));
    shared_ptr<WebSite> fz = f.getWebSiteCategory(string("��Ʒչʾ"));
    fz->use(User(string("����")));

    shared_ptr<WebSite> fl = f.getWebSiteCategory(string("����"));
    fl->use(User(string("����ͯ")));
    shared_ptr<WebSite> fm = f.getWebSiteCategory(string("����"));
    fm->use(User(string("�ҹ�����")));
    shared_ptr<WebSite> fn = f.getWebSiteCategory(string("����"));
    fn->use(User(string("�Ϻ�����")));

    cout << "��վ��������Ϊ:" << f.getWebSiteCount() << endl;
    return 0;
}