#include<iostream>
#include<string>

using namespace std;

class Prototype
{
public:
    virtual Prototype* clone() = 0;
};

class WorkExperience
{
public:
    string getTimeArea() { return timeArea;}
    string getCompany() { return company; }
    void setTimeArea(const string& value) { this->timeArea = value; }
    void setCompany(const string& value) { this->company = value; }

private:
    string timeArea;
    string company;
};

class Resume: public Prototype
{
public:
    Resume(const string& name): name(name) {} 
    void setPersonalInfo(const string& sex, const string& age)
    {
        this->sex = sex;
        this->age = age;
    }
    void setWorkExperience(const string& timeArea, const string& company)
    {
        work.setTimeArea(timeArea);
        work.setCompany(company);
    }
    void display()
    {
        cout << name << " " << sex << " " << age << endl;
        cout << "��������" << work.getTimeArea() << " " << work.getCompany() << endl;
    }
    Prototype* clone() 
    {
        return new Resume(*this);
    }
private:
    string name;
    string sex;
    string age;
    WorkExperience work;
};

int main()
{
    Resume resume1(string("����"));
    resume1.setPersonalInfo(string("��"), string("29"));
    resume1.setWorkExperience(string("1998-2000"), string("XX��˾"));

    Resume *resume2 = static_cast<Resume* >(resume1.clone());
    resume2->setWorkExperience(string("1998-2006"), string("YY��˾"));
    
    Resume *resume3 = static_cast<Resume* >(resume1.clone());
    resume3->setPersonalInfo(string("��"), string("24"));
    
    resume1.display();
    resume2->display();
    resume3->display();
    delete resume2;
    delete resume3;
    return 0;
}