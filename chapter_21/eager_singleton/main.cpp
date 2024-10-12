#include <iostream>
#include <memory>

using namespace std;

class Singleton
{
private:
    static unique_ptr<Singleton> instance;
    Singleton() {}
public:
    static Singleton* getInstance()
    {
        return instance.get();
    }
};
unique_ptr<Singleton> Singleton::instance(new Singleton);

int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if (s1 == s2)
        cout << "������������ͬ��ʵ��." << endl;
    return 0;
}