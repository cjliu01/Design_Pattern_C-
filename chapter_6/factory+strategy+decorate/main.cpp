#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Scale
{
public:
    virtual double acceptCash(double price, int num) = 0;
};

class CashSuper: public Scale
{
public:
    void decorate(Scale *component) { this->component = component; }
    double acceptCash(double price, int num) 
    {
        double result = 0;
        if (this->component != 0)
            result = this->component->acceptCash(price, num);
        return result;
    }
protected:
    Scale *component = 0;
};  

class CashNormal: public Scale
{
public:
    double acceptCash(double price, int num) { return price * num;}
};

class CashRebate: public CashSuper
{
public: 
    CashRebate(double moneyRebate): moneyRebate(moneyRebate) {}
    double acceptCash(double price, int num)
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
    double acceptCash(double price, int num)
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
    Scale *cs = 0;
    Scale *cn = 0;
    CashSuper *cr1 = 0;
    CashSuper *cr2 = 0;
public:
    CashContext(int cashType)
    {
        switch(cashType)
        {
            case 1: cs = new CashNormal; break;
            case 2: cn = new CashNormal; cr2 = new CashRebate(0.8); cr2->decorate(cn); cs = cr2; break;
            case 3: cn = new CashNormal; cr2 = new CashRebate(0.7); cr2->decorate(cn); cs = cr2; break; 
            case 4: cn = new CashNormal; cr2 = new CashReturn(300, 100); cr2->decorate(cn); cs = cr2; break;  
            case 5: 
                {
                    cn = new CashNormal;
                    cr1 = new CashRebate(0.8);
                    cr2 = new CashReturn(300, 100);

                    cr1->decorate(cn);
                    cr2->decorate(cr1);
                    this->cs = cr2;
                    break;
                }
            case 6:
                {
                    cn = new CashNormal;
                    cr1 = new CashReturn(200, 50);
                    cr2 = new CashRebate(0.7);

                    cr1->decorate(cn);
                    cr2->decorate(cr1);
                    this->cs = cr2;
                    break;
                }
        }
    }
    ~CashContext() 
    { 
        delete cn;
        delete cr1;
        delete cr2;
        if (cs != cn && cs != cr1 && cs != cr2) 
            delete cs;  //��ֹ�ظ�ɾ��
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
                << "�ϼ�: " << totalPrice << "Ԫ" << endl;
            cout << "�ܼ�: " << total << "Ԫ" << endl;
        }
    } while (price > 0 && num > 0);
    return  0;
}