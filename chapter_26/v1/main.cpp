#include<iostream>
#include<string>

using namespace std;
class WebSite
{
public:
    WebSite(const string& name): name(name) {}
    void use() { cout << "��վ����: " << name << endl; }
private:
    string name;
};

int main()
{
    WebSite fx(string("��Ʒչʾ"));
    fx.use();
    WebSite fy(string("��Ʒչʾ"));
    fy.use();
    WebSite fz(string("��Ʒչʾ"));
    fz.use();

    WebSite fl(string("����"));
    fl.use();
    WebSite fm(string("����"));
    fm.use();
    WebSite fn(string("����"));
    fn.use();

    return 0;
}