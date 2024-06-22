#include<iostream>
#include<string>
#include<map>

using namespace std;

class WebSite
{
public:
    virtual void use() = 0;
};

class ConcreteWebSite: public WebSite
{
public:
    ConcreteWebSite(const string& name): name(name) {}
    void use() { cout << "��վ����: " << name << endl; }
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
    fx->use();
    WebSite* fy = f.getWebSiteCategory(string("��Ʒչʾ"));
    fy->use();
    WebSite* fz = f.getWebSiteCategory(string("��Ʒչʾ"));
    fz->use();

    WebSite* fl = f.getWebSiteCategory(string("����"));
    fl->use();
    WebSite* fm = f.getWebSiteCategory(string("����"));
    fm->use();
    WebSite* fn = f.getWebSiteCategory(string("����"));
    fn->use();

    cout << "��վ��������Ϊ:" << f.getWebSiteCount() << endl;
    return 0;
}