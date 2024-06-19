#include<iostream>

using namespace std;

class HandsetSoft
{
public:
    virtual void run() = 0;
};

class HandsetGame: public HandsetSoft
{
public:
    void run() { cout << "�ֻ���Ϸ" << endl; }
};

class HandsetAddressList: public HandsetSoft
{
public:
    void run() { cout << "�ֻ�ͨ��¼" << endl; }
};

class HandsetMusicPlay: public HandsetSoft
{
public:
    void run() { cout << "���ֲ���" << endl; }
};

class HandsetBrand
{
public:
    void setHandsetSoft(HandsetSoft *soft) 
    {
        delete this->soft;
        this->soft = soft; 
    }
    ~HandsetBrand() { delete soft; }
    HandsetBrand(HandsetSoft *soft=nullptr): soft(soft) {} 
    virtual void run() = 0;
protected:
    HandsetSoft *soft;
};

class HandsetBrandM: public HandsetBrand
{
public:
    void run() 
    {
        cout << "Ʒ��M" << endl;
        soft->run();
    }
};

class HandsetBrandN: public HandsetBrand
{
public:
    void run()
    {
        cout << "Ʒ��N" << endl;
        soft->run();
    }
};

class HandsetBrandS: public HandsetBrand
{
public:
    void run()
    {
        cout << "Ʒ��S" << endl;
        soft->run();
    }
};

int main()
{
    HandsetBrand *db = nullptr;
    db = new HandsetBrandN();
    
    db->setHandsetSoft(new HandsetGame);
    db->run();

    db->setHandsetSoft(new HandsetAddressList);
    db->run();

    delete db;
    return 0;
}