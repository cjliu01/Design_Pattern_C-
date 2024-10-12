#include <iostream>
#include <string>
#include <cmath>
#include <memory>

using namespace std;

class Scale
{
public:
    virtual double acceptCash(double price, int num) = 0;
    virtual ~Scale() = default;
};

class CashSuper: public Scale
{
public:
    void decorate(Scale *c) { component.reset(c); }
    double acceptCash(double price, int num) override
    {
        double result = 0;
        if (this->component != nullptr)
            result = this->component->acceptCash(price, num);
        return result;
    }
protected:
    shared_ptr<Scale> component;
};  

class CashNormal: public Scale
{
public:
    double acceptCash(double price, int num) override { return price * num; }
};

class CashRebate: public CashSuper
{
public: 
    CashRebate(double moneyRebate): moneyRebate(moneyRebate) {}
    double acceptCash(double price, int num) override
    {
        double result = price * num * moneyRebate;
        return CashSuper::acceptCash(result, 1);
    }
private:
    double moneyRebate = 1;
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
        return CashSuper::acceptCash(result, 1);
    }
private:
    double moneyCondition = 0;
    double moneyReturn = 0;
};

class CashContext
{
private:
    shared_ptr<Scale> cs;
    CashSuper *cr1 = nullptr;
    CashSuper *cr2 = nullptr;
public: 
    CashContext(int cashType)
    {
        switch(cashType)
        {
            case 1: cs = make_shared<CashNormal>(); break;
            case 2: cr2 = new CashRebate(0.8); cr2->decorate(new CashNormal); cs.reset(cr2); break;
            case 3: cr2 = new CashRebate(0.7); cr2->decorate(new CashNormal); cs.reset(cr2); break; 
            case 4: cr2 = new CashReturn(300, 100); cr2->decorate(new CashNormal); cs.reset(cr2); break;  
            case 5: 
                {
                    cr1 = new CashRebate(0.8);
                    cr2 = new CashReturn(300, 100);
                    cr1->decorate(new CashNormal);
                    cr2->decorate(cr1);
                    cs.reset(cr2);
                    break;
                }
            case 6:
                {
                    cr1 = new CashReturn(200, 50);
                    cr2 = new CashRebate(0.7);
                    cr1->decorate(new CashNormal);
                    cr2->decorate(cr1);
                    cs.reset(cr2);
                    break;
                }
        }
    }
    double getResult(double price, int num) { return cs->acceptCash(price, num); }
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
        cout << "��������Ʒ����ģʽ 1.ԭ�� 2.���� 3.���� 4.��300��100 5.��300��100����� 6.���ۺ���200��50: ";
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
                << " �ϼ�: " << totalPrice << "Ԫ" << endl;
            cout << "�ܼ�: " << total << "Ԫ" << endl;
        }
    } while (price > 0 && num > 0);
    return  0;
}