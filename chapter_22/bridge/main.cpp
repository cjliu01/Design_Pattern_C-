#include <iostream>
#include <memory>

using namespace std;

class HandsetSoft
{
public:
    virtual void run() = 0;
    virtual ~HandsetSoft() = default;
};

class HandsetGame: public HandsetSoft
{
public:
    void run() override { cout << "�ֻ���Ϸ" << endl; }
};

class HandsetAddressList: public HandsetSoft
{
public:
    void run() override { cout << "�ֻ�ͨ��¼" << endl; }
};

class HandsetMusicPlay: public HandsetSoft
{
public:
    void run() override { cout << "���ֲ���" << endl; }
};

class HandsetBrand
{
public:
    void setHandsetSoft(HandsetSoft *s) { soft.reset(s); }
    virtual void run() = 0;
    virtual ~HandsetBrand() = default;
protected:
    shared_ptr<HandsetSoft> soft;
};

class HandsetBrandM: public HandsetBrand
{
public:
    void run() override
    {
        cout << "Ʒ��M" << endl;
        soft->run();
    }
};

class HandsetBrandN: public HandsetBrand
{
public:
    void run() override
    {
        cout << "Ʒ��N" << endl;
        soft->run();
    }
};

class HandsetBrandS: public HandsetBrand
{
public:
    void run() override
    {
        cout << "Ʒ��S" << endl;
        soft->run();
    }
};

int main()
{
    shared_ptr<HandsetBrand> db = make_shared<HandsetBrandN>();
    
    db->setHandsetSoft(new HandsetGame);
    db->run();

    db->setHandsetSoft(new HandsetAddressList);
    db->run();

    return 0;
}