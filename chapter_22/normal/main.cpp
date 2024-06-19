#include<iostream>

using namespace std;

class HandsetBrand
{
public:
    virtual void run() = 0;  
};

class HandsetBrandN: public HandsetBrand {};

class HandsetBrandM: public HandsetBrand {};

class HansetBrandMGame: public HandsetBrandM
{
public:
    void run() { cout << "����MƷ���ֻ���Ϸ" << endl; }
};

class HandsetBrandNGame: public HandsetBrandN
{
public:
    void run() { cout << "����NƷ���ֻ���Ϸ" << endl; }
};

class HandsetBrandMAddressList: public HandsetBrandM
{
public:
    void run() { cout << "����MƷ���ֻ�ͨѶ¼" << endl; }
};

class HandsetBrandNAddressList: public HandsetBrandN
{
public:
    void run() { cout << "����NƷ���ֻ�ͨѶ¼" << endl; }
};

int main()
{
    HandsetBrand *db = nullptr;
    db = new HandsetBrandMAddressList();
    db->run();

    db = new HansetBrandMGame();
    db->run();

    db = new HandsetBrandNAddressList();
    db->run();

    db = new HandsetBrandNGame();
    db->run();

    delete db;
    return 0;
}