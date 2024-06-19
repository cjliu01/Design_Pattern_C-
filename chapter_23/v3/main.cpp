#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

class Barbecuer
{
public:
    void bakeMutton() { cout << "�����⴮��" << endl; }
    void bakeChickenWing() { cout << "�����ᣡ" << endl; }
};

class Command
{
public:
    virtual void excuteCommand() = 0;
    virtual string getCommandName() = 0;
    Command(const Barbecuer& receiver): receiver(receiver) {}
protected:
    Barbecuer receiver;
};

class BakeMuttonCommand: public Command
{
public:
    BakeMuttonCommand(const Barbecuer& receiver): Command(receiver) {}
    void excuteCommand() { receiver.bakeMutton(); }
    string getCommandName() { return string("BakeMutton"); }
};

class BakeChickenWingCommand: public Command
{
public:
    BakeChickenWingCommand(const Barbecuer& receiver): Command(receiver) {}
    void excuteCommand() { receiver.bakeChickenWing();}
    string getCommandName() { return string("BakeChickenWing"); }
};

class Waiter
{
public:
    Waiter() {}
    void setOrder(Command* command) 
    { 
        if (command->getCommandName() == string("BakeChickenWing"))
            cout << "����Ա: ����û����, ������տ�." << endl;
        else
        {
            orders.push_back(command);
            cout << "���Ӷ���: " << command->getCommandName() << " ʱ��: " << getNowTime() << endl; 
        }
    }
    void cancelOrder(Command* command)
    {
        for (int i = 0; i < orders.size(); ++i)
        {
            if (orders[i] == command)
            {
                orders.erase(orders.begin() + i);
                cout << "ȡ������: " << command->getCommandName() << " ʱ��: " << getNowTime() << endl; 
                break;
            }
        }
    }
    void notifyCommand() 
    {
        for (int i = 0; i < orders.size(); ++i)
            orders[i]->excuteCommand();
    }
private:
    vector<Command*> orders;
    string getNowTime() 
    {
        time_t now = std::time(nullptr);    
        tm* local_time = std::localtime(&now);   
        ostringstream oss;  
        oss << put_time(local_time, "%Y-%m-%d %H:%M:%S"); // ��ʽ��Ϊ"��-��-�� ʱ:��:��"  
        return oss.str(); 
    }
};

int main()
{
    Barbecuer boy;
    BakeChickenWingCommand bakeChickenWingCommand1(boy);
    BakeMuttonCommand bakeMuttonCommand1(boy);
    Waiter girl;

    cout << "����Ӫҵ, �˿͵��" << endl;
    girl.setOrder(&bakeMuttonCommand1);
    girl.setOrder(&bakeMuttonCommand1);
    girl.setOrder(&bakeMuttonCommand1);
    girl.setOrder(&bakeMuttonCommand1); 
    girl.setOrder(&bakeMuttonCommand1);

    girl.cancelOrder(&bakeMuttonCommand1);
    girl.setOrder(&bakeChickenWingCommand1);

    cout << "������, ֪ͨ�����ղ�" << endl;
    girl.notifyCommand();
    return 0;
}