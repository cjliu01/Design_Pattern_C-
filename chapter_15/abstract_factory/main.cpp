#include <iostream>
#include <string>
#include <memory>

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
    virtual ~IUser() = default;
};

class SqlserverUser: public IUser
{
public:
    void insert(User& user) { cout << "在SQL Server中给User表增加一条记录" << endl; }
    User getUser(int id) 
    { 
        cout << "在SQL Server中根据用户id得到User表一条记录" << endl; 
        return User();
    }
};

class AccessUser: public IUser
{
public:
    void insert(User& user) { cout << "在Access中给User表增加一条记录" << endl; }
    User getUser(int id)
    {
        cout << "在Access中根据用户id得到User表一条记录" << endl;
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
    virtual ~IDepartment() = default;
};

class SqlserverDepartment: public IDepartment
{
public:
    void insert(Department& department) { cout << "在SQL Server中给Department表增加一条记录" << endl; }
    Department getDepartment(int id)
    {
        cout << "在SQL Server中根据部门id得到Department表一条记录" << endl;
        return Department();
    }
};

class AccessDepartment: public IDepartment
{
public:
    void insert(Department& department) { cout << "在Access中给Department表增加一条记录" << endl; }
    Department getDepartment(int id)
    {
        cout << "在Access中根据部门id得到Department表一条记录" << endl;
        return Department();
    }
};

class Factory
{
public:
    virtual shared_ptr<IUser> createUser() = 0;
    virtual shared_ptr<IDepartment> createDepartment() = 0;
protected:
    shared_ptr<IUser> user;
    shared_ptr<IDepartment> department;
};

class SqlserverFactory: public Factory
{
public:
    shared_ptr<IUser> createUser() 
    { 
        user = make_shared<SqlserverUser>(); 
        return user;    
    }

    shared_ptr<IDepartment> createDepartment()
    {
        department = make_shared<SqlserverDepartment>();
        return department;
    }
};

class AccessFactory: public Factory
{
public:
    shared_ptr<IUser> createUser() 
    { 
        user = make_shared<AccessUser>(); 
        return user;    
    }

    shared_ptr<IDepartment> createDepartment()
    {
        department = make_shared<AccessDepartment>();
        return department;
    }
};

int main()
{
    User user;
    Department department;
    shared_ptr<Factory> factory = make_shared<AccessFactory>();
    shared_ptr<IUser> iu = factory->createUser();
    iu->insert(user);
    iu->getUser(1);

    shared_ptr<IDepartment> idept = factory->createDepartment();
    idept->insert(department);
    idept->getDepartment(2);

    return 0;
}