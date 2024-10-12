#include <iostream>
#include <memory>

using namespace std;

class Target
{
public:
    virtual void request() { cout << "��ͨ����!" << endl; }
    virtual ~Target() = default;
};

class Adaptee
{
public:
    void specificRequest() { cout << "��������!" << endl; }
};

class Adapter: public Target
{
public:
    virtual void request() override { adaptee.specificRequest(); }
private:
    Adaptee adaptee;
};

int main()
{
    shared_ptr<Target> target = make_shared<Adapter>();
    target->request();

    return 0;
}