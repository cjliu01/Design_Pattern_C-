#include<iostream>

using namespace std;

class Singleton
{
private:
    Singleton() {} ;
    static Singleton *instance;
public:
    static Singleton* getInstance()
    {
        if (instance == nullptr)
            instance = new Singleton;
        return instance;
    }
    ~Singleton() { delete instance; }
};
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if (s1 == s2)
        cout << "������������ͬ��ʵ��." << endl;
    return 0;
}