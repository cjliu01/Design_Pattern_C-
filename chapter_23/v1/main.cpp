#include <iostream>

using namespace std;

class Barbecuer
{
public:
    void bakeMutton() { cout << "�����⴮��" << endl; }
    void bakeChickenWing() { cout << "�����ᣡ" << endl; }
};

int main()
{
    Barbecuer boy;

    boy.bakeMutton();
    boy.bakeMutton();
    boy.bakeMutton();
    boy.bakeChickenWing();
    boy.bakeMutton();
    boy.bakeMutton();
    boy.bakeChickenWing();
    return 0;
}