#include<iostream>

using namespace std;

class Work
{
public:
    Work(int h=0, bool w=false): hour(h), workFinished(w) {}
    int getHour() { return hour; }
    void setHour(int h) { hour = h; }
    bool getWorkFinished() { return workFinished; }
    void setWorkFinished(bool w) { workFinished = w; }
    void writeProgram()
    {
        if (hour < 12) 
            cout << "��ǰʱ��" << hour << "�㣬���繤��������ٱ�" << endl;
        else if (hour < 13)
            cout << "��ǰʱ��" << hour << "�㣬���ˣ��緹������������" << endl;
        else if (hour < 17)
            cout << "��ǰʱ��" << hour << "�㣬����״̬����������Ŭ��" << endl;
        else    
        {
            if (workFinished)
                cout << "��ǰʱ��" << hour << "�㣬�°�ؼ���" << endl;
            else
            {
                if (hour < 21)
                    cout << "��ǰʱ��: " << hour << "�㣬�Ӱ�Ŷ��ƣ��֮��" << endl;
                else      
                    cout << "��ǰʱ��: " << hour << "�㣬�����ˣ�˯���ˡ�" << endl;
            }
        }
    }

private:
    int hour;
    bool workFinished;
};

int main()
{
    Work emergencyProjects;
    emergencyProjects.setHour(9);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(10);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(12);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(13);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(14);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(17);

    emergencyProjects.setWorkFinished(false);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(19);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(22);
    emergencyProjects.writeProgram();
    
    return 0;
}