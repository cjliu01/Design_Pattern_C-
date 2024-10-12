#include <iostream>
#include <memory>

using namespace std;

class HandsetBrand
{
public:
    virtual void run() = 0;  
    virtual ~HandsetBrand() = default;
};

class HandsetBrandN: public HandsetBrand {};

class HandsetBrandM: public HandsetBrand {};

class HansetBrandMGame: public HandsetBrandM
{
public:
    void run() override { cout << "����MƷ���ֻ���Ϸ" << endl; }
};

class HandsetBrandNGame: public HandsetBrandN
{
public:
    void run() override { cout << "����NƷ���ֻ���Ϸ" << endl; }
};

class HandsetBrandMAddressList: public HandsetBrandM
{
public:
    void run() override { cout << "����MƷ���ֻ�ͨѶ¼" << endl; }
};

class HandsetBrandNAddressList: public HandsetBrandN
{
public:
    void run() override { cout << "����NƷ���ֻ�ͨѶ¼" << endl; }
};

int main()
{
    shared_ptr<HandsetBrand> db = make_shared<HandsetBrandMAddressList>();
    db->run();

    db.reset(new HansetBrandMGame());
    db->run();

    db.reset(new HandsetBrandNAddressList());
    db->run();

    db.reset(new HandsetBrandNGame());
    db->run();

    return 0;
}