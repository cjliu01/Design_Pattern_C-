#include<iostream>
#include<string>
using namespace std;

class Request
{
public:
    string getRequestType() { return requestType; }
    void setRequestType(const string& requestType) { this->requestType = requestType; }
    string getRequestContent() { return requestContent; }
    void setRequestContent(const string& requestContent) { this->requestContent = requestContent; }
    int getNumber() { return number; }
    void setNumber(int number) { this->number = number; }

private:
    string requestType;
    string requestContent;
    int number;
};

class Manager
{
public:
    Manager(const string& name): name(name) {}
    void getResult(const string& mangerLevel, Request& request)
    {
        if (mangerLevel == string("����"))
        {
            if (request.getRequestType() == string("���") && request.getNumber() <= 2)
                cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "��, ����׼" << endl;
            else
                cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "��, ����Ȩ����" << endl; 
        }     
        else if (mangerLevel == string("�ܼ�"))
        {
            if (request.getRequestType() == string("���") && request.getNumber() <= 5)
                cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "��, ����׼" << endl;
            else
                cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "��, ����Ȩ����" << endl; 
        }
        else if (mangerLevel == string("�ܾ���"))
        {
            if (request.getRequestType() == string("���"))
                cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "��, ����׼" << endl;
            else if (request.getRequestType() == string("��н") && request.getNumber() <= 5000)
                cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "Ԫ, ����׼" << endl; 
            else if (request.getRequestType() == string("��н") && request.getNumber() > 5000)
                cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "Ԫ, ��˵��" << endl; 
        }
    }
protected:
    string name;
};

int main()
{
    Manager manager(string("����"));
    Manager director(string("�ڽ�"));
    Manager generalManager(string("�Ӿ���"));

    Request request;
    request.setRequestType(string("��н"));
    request.setRequestContent(string("С�������н"));
    request.setNumber(10000);

    manager.getResult(string("����"), request);
    director.getResult(string("�ܼ�"), request);
    generalManager.getResult(string("�ܾ���"), request);

    Request request2;
    request2.setRequestType(string("���"));
    request2.setRequestContent(string("С�����"));
    request2.setNumber(3);

    manager.getResult(string("����"), request2);
    director.getResult(string("�ܼ�"), request2);
    generalManager.getResult(string("�ܾ���"), request2);
    return 0;
}