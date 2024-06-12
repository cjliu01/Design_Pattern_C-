#include<iostream>
#include<string>

using namespace std;

class User
{
public:
    void setId(int value) { _id = value; }
    int getId() { return _id; }

    string getName() { return _name; }
    void setName(const string& value) { _name = value; }

private:
    int _id;
    string _name;
};

class IUser
{
public:
    virtual void insert(User& user) = 0;
    virtual User getUser(int id) = 0;
};

class SqlserverUser: public IUser
{
public:
    void insert(User& user) { cout << "��SQL Server�и�User������һ����¼" << endl; }
    User getUser(int id) 
    { 
        cout << "��SQL Server�и����û�id�õ�User��һ����¼" << endl; 
        return User();
    }
};

class AccessUser: public IUser
{
public:
    void insert(User& user) { cout << "��Access�и�User������һ����¼" << endl; }
    User getUser(int id)
    {
        cout << "��Access�и����û�id�õ�User��һ����¼" << endl;
        return User();
    }
};

class Department
{
public:
    int getId() { return _id; }
    void setId(int value) { _id = value; }

    string getName() { return _name; }
    void setName(const string& value) { _name = value; }

private: 
    int _id;
    string _name;
};

class IDepartment
{
public:
    virtual void insert(Department& department) = 0;
    virtual Department getDepartment(int id) = 0;   
};

class SqlserverDepartment: public IDepartment
{
public:
    void insert(Department& department) { cout << "��SQL Server�и�Department������һ����¼" << endl; }
    Department getDepartment(int id)
    {
        cout << "��SQL Server�и��ݲ���id�õ�Department��һ����¼" << endl;
        return Department();
    }
};

class AccessDepartment: public IDepartment
{
public:
    void insert(Department& department) { cout << "��Access�и�Department������һ����¼" << endl; }
    Department getDepartment(int id)
    {
        cout << "��Access�и��ݲ���id�õ�Department��һ����¼" << endl;
        return Department();
    }
};

class Factory
{
public:
    Factory(): user(0), department(0) {}
    virtual IUser* createUser() = 0;
    virtual IDepartment* createDepartment() = 0;
    ~Factory() 
    { 
        delete user;
        delete department;
    }
protected:
    IUser* user;
    IDepartment* department;
};

class SqlserverFactory: public Factory
{
public:
    IUser* createUser() 
    { 
        user = new SqlserverUser(); 
        return user;    
    }

    IDepartment* createDepartment()
    {
        department = new SqlserverDepartment();
        return department;
    }
};

class AccessFactory: public Factory
{
public:
    IUser* createUser() 
    { 
        user = new AccessUser(); 
        return user;    
    }

    IDepartment* createDepartment()
    {
        department = new AccessDepartment();
        return department;
    }
};

int main()
{
    User user;
    Department department;
    Factory* factory = new SqlserverFactory();
    IUser* iu = factory->createUser();
    iu->insert(user);
    iu->getUser(1);

    IDepartment* idept = factory->createDepartment();
    idept->insert(department);
    idept->getDepartment(2);

    delete factory;
    return 0;
}