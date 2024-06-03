#include<iostream>
#include<string>

using namespace std;

class Prototype
{
public:
    virtual Prototype* clone() = 0;
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
        this->timeArea = timeArea;
        this->company = company;
    }
    void display()
    {
        cout << name << " " << sex << " " << age << endl;
        cout << "��������" << timeArea << " " << company << endl;
    }
    Prototype* clone() 
    {
        return new Resume(*this);
    }
private:
    string name;
    string sex;
    string age;
    string timeArea;
    string company;
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