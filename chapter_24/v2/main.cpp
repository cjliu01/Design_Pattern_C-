#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Request
{
public:
    string getRequestType() const { return requestType; }
    void setRequestType(const string& requestType) { this->requestType = requestType; }
    string getRequestContent() const { return requestContent; }
    void setRequestContent(const string& requestContent) { this->requestContent = requestContent; }
    int getNumber() const { return number; }
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
    void setSuperior(shared_ptr<Manager> s) { superior = s; }
    virtual void requestApplications(const Request& request) = 0;
    virtual ~Manager() = default;
protected:
    string name;
    shared_ptr<Manager> superior;
};

class CommonManager: public Manager
{
public:
    CommonManager(const string& name): Manager(name) {}
    void requestApplications(const Request& request) override
    {
        if (request.getRequestType() == string("���") && request.getNumber() <= 2)
            cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "��, ����׼" << endl;
        else if (superior != nullptr)
            superior->requestApplications(request);
    }
};

class Director: public Manager
{
public:
    Director(const string& name): Manager(name) {}
    void requestApplications(const Request& request) override
    {
            if (request.getRequestType() == string("���") && request.getNumber() <= 5)
                cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "��, ����׼" << endl;
            else if (superior != nullptr)
                superior->requestApplications(request);
    }
};

class GeneralManager: public Manager
{
public:
    GeneralManager(const string& name): Manager(name) {}
    void requestApplications(const Request& request) override
    {
        if (request.getRequestType() == string("���"))
            cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "��, ����׼" << endl;
        else if (request.getRequestType() == string("��н") && request.getNumber() <= 5000)
            cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "Ԫ, ����׼" << endl; 
        else if (request.getRequestType() == string("��н") && request.getNumber() > 5000)
            cout << name << ":" << request.getRequestContent() << " ����:" << request.getNumber() << "Ԫ, ��˵��" << endl; 
    }
};


int main()
{
    shared_ptr<Manager> manager = make_shared<CommonManager>("����");
    shared_ptr<Director> director = make_shared<Director>("�ڽ�");
    shared_ptr<Manager> generalManager = make_shared<GeneralManager>("�Ӿ���");
    manager->setSuperior(director);
    director->setSuperior(generalManager);

    Request request;
    request.setRequestType(string("���"));
    request.setRequestContent(string("С�����"));
    request.setNumber(1);
    manager->requestApplications(request);

    Request request2;
    request2.setRequestType(string("���"));
    request2.setRequestContent(string("С�����"));
    request2.setNumber(4);
    manager->requestApplications(request2);

    Request request3;
    request3.setRequestType(string("��н"));
    request3.setRequestContent(string("С�������н"));
    request3.setNumber(5000);
    manager->requestApplications(request3);

    Request request4;
    request4.setRequestType(string("��н"));
    request4.setRequestContent(string("С�������н"));
    request4.setNumber(10000);
    manager->requestApplications(request4);


    return 0;
}