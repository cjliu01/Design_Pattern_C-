#include <iostream>
#include <cmath>
#include <memory>

using namespace std;

class CashSuper
{
public:
    virtual double acceptCash(double price, int num) = 0;
    virtual ~CashSuper() = default;
};

class CashNormal: public CashSuper
{
public:
    double acceptCash(double price, int num) override { return price * num; }
};

class CashRebate: public CashSuper
{
public:
    CashRebate(double MoneyRebate): moneyRebate(MoneyRebate) {}
    double acceptCash(double price, int num) override { return price * num * moneyRebate; }

private:
    double moneyRebate;
};

class CashReturn: public CashSuper
{
public:
    CashReturn(double moneyCondition, double moneyReturn): moneyCondition(moneyCondition), moneyReturn(moneyReturn) {}
    double acceptCash(double price, int num) override
    {
        double result = price * num;
        if (moneyCondition > 0 && result >= moneyCondition) 
            result -= floor(result / moneyCondition) * moneyReturn;
        return result; 
    }

private:
    double moneyCondition;
    double moneyReturn;
};

class CashFactory
{
public:
    static shared_ptr<CashSuper> createCashAccept(int cashType)
    {
        CashSuper* cs = nullptr;
        switch(cashType)
        {
            case 1: cs = new CashNormal(); break;
            case 2: cs = new CashRebate(0.8); break;
            case 3: cs = new CashRebate(0.7); break;
            case 4: cs = new CashReturn(300, 100); break;
        }
        return shared_ptr<CashSuper>(cs);
    }
};

int main()
{
    double price = 0;
    int discount = 0;
    int num = 0;
    double totalPrice = 0;
    double total = 0;
    do
    {
        cout << "��������Ʒ����ģʽ 1.ԭ�� 2.���� 3.���� 4.��300��100:";
        cin >> discount;
        cout << "��������Ʒ����: ";
        cin >> price;
        cout << "��������Ʒ����: ";
        cin >> num;
        if (price > 0 && num > 0)
        {
            shared_ptr<CashSuper> cs = CashFactory::createCashAccept(discount);
            totalPrice = cs->acceptCash(price, num);
            total += totalPrice;

            cout << "����: " << price << "Ԫ ����: " << num 
                << " �ϼ�: " << totalPrice << "Ԫ" << endl;
            cout << "�ܼ�: " << total << "Ԫ" << endl;
        }
    } while (price > 0 && num > 0);
    return  0;
}