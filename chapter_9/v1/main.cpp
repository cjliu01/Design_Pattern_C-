#include<iostream>
#include<string>

using namespace std;

class Resume
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
private:
    string name;
    string sex;
    string age;
    string timeArea;
    string company;
};

int main()
{
    Resume resume1("����");
    resume1.setPersonalInfo("��", "29");
    resume1.setWorkExperience("1998-2000", "XX��˾");

    Resume resume2("����");
    resume2.setPersonalInfo("��", "29");
    resume2.setWorkExperience("1998-2000", "XX��˾");
    
    Resume resume3("����");
    resume3.setPersonalInfo("��", "29");
    resume3.setWorkExperience("1998-2000", "XX��˾");
    
    resume1.display();
    resume2.display();
    resume3.display();
    return 0;
}