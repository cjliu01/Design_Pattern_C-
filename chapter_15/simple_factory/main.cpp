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

class IUser
{
public:
    virtual void insert(User& user) = 0;
    virtual User getUser(int id) = 0;
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

class IDepartment
{
public:
    virtual void insert(Department& department) = 0;
    virtual Department getDepartment(int id) = 0;   
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


class DataAccess
{
public:
    static string db;
    DataAccess(): user(0), department(0) {}
    ~DataAccess() 
    {
        delete user;
        delete department;
    }

    IUser* createUser()
    {
        if (db == string("Sqlserver"))
            user = new SqlserverUser();
        else if (db == string("Access"))
            user = new AccessUser();
        return user;
    }

    IDepartment* createDepartment()
    {
        if (db == string("Sqlserver"))
            department = new SqlserverDepartment();
        else if (db == string("Access"))
            department = new AccessDepartment();
        return department;
    }
private:
    IUser* user;
    IDepartment* department;
};
string DataAccess::db("Access");

int main()
{
    User user;
    Department department;
    
    DataAccess da;
    IUser* iu = da.createUser();
    
    iu->insert(user);
    iu->getUser(1);
    IDepartment* idept = da.createDepartment();

    idept->insert(department);
    idept->getDepartment(2);
    return 0;
}