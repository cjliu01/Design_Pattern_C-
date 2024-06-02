#include<iostream>
#include<string>
#include<cmath>

using namespace std;
class Sale
{
public:
    virtual double acceptCash(double price, int num) = 0;
};

class CashSuper: public Sale
{
public:
    void decorate(Sale *component) { this->component = component; }
    double acceptCash(double price, int num) 
    {
        double result = 0;
        if (this->component != 0)
            result = this->component->acceptCash(price, num);
        return result;
    }
protected:
    Sale *component = 0;
};  

class CashNormal: public Sale
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

class Factory
{
public:
    virtual Sale* createSalesMode() = 0;
    // Ϊ���ڴ����
    Sale* cn = 0;
    CashSuper* cr1 = 0;
    CashSuper* cr2 = 0;
};

class CashRebateReturnFactory: public Factory
{
public:
    CashRebateReturnFactory(double moneyRebate, double moneyCondition, double moneyReturn): 
        moneyRebate(moneyRebate), moneyCondition(moneyCondition), moneyReturn(moneyReturn) {}
    Sale* createSalesMode()
    {
        cn = new CashNormal();
        cr1 = new CashReturn(moneyCondition, moneyReturn);
        cr2 = new CashRebate(moneyRebate);

        cr1->decorate(cn);
        cr2->decorate(cr1);
        return cr2;
    }

private:
    double moneyRebate = 1;
    double moneyCondition = 0;
    double moneyReturn = 0;
};

class CashReturnRebateFactory: public Factory
{
public:
    CashReturnRebateFactory(double moneyRebate, double moneyCondition, double moneyReturn):
        moneyCondition(moneyCondition), moneyReturn(moneyReturn), moneyRebate(moneyRebate) {}
    
    Sale* createSalesMode()
    {
        cn = new CashNormal();
        cr1 = new CashRebate(moneyRebate);
        cr2 = new CashReturn(moneyCondition, moneyReturn);
        
        cr1->decorate(cn);
        cr2->decorate(cr1);
        return cr2;
    }

private:
    double moneyRebate = 1;
    double moneyCondition = 0;
    double moneyReturn = 0;
};

class CashContext
{
public:
    CashContext(int CashType)
    {
        switch(CashType)
        {
            case 1:
            fs = new CashRebateReturnFactory(1, 1, 0); break;
            case 2:
            fs = new CashReturnRebateFactory(0.8, 1, 0); break;
            case 3:
            fs = new CashRebateReturnFactory(0.7, 1, 0); break;
            case 4:
            fs = new CashReturnRebateFactory(1, 300, 100); break;
            case 5:
            fs = new CashReturnRebateFactory(0.8, 300, 100); break;
            case 6:
            fs = new CashRebateReturnFactory(0.7, 200, 50); break;
        }
        cs = fs->createSalesMode();
    }
    double getResult(double price, int num)
    {
        return cs->acceptCash(price, num);
    }
    ~CashContext()
    {
        delete fs->cn;
        delete fs->cr1;
        delete fs->cr2;
        if (fs->cr2 != cs)
            delete cs; // �����ظ�ɾ��
        delete fs;
    }
private:
    Sale *cs;
    Factory *fs = 0;
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