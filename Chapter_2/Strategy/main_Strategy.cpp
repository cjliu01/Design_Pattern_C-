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

class CashContext
{
public:
    CashContext(int cashType)
    {
        switch(cashType)
        {
            case 1: cs = make_shared<CashNormal>(); break;
            case 2: cs = make_shared<CashRebate>(0.8); break;
            case 3: cs = make_shared<CashRebate>(0.7); break;
            case 4: cs = make_shared<CashReturn>(300, 100); break; 
        }
    }

    double getResult(double price, int num) { return cs->acceptCash(price, num); }

private:
    shared_ptr<CashSuper> cs;
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
            CashContext cc(discount);
            totalPrice = cc.getResult(price, num);
            total += totalPrice;

            cout << "����: " << price << "Ԫ ����: " << num 
                << "�ϼ�: " << totalPrice << "Ԫ" << endl;
            cout << "�ܼ�: " << total << "Ԫ" << endl;
        }
    } while (price > 0 && num > 0);
    return  0;
}