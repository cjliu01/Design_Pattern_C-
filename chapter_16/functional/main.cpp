#include<iostream>

using namespace std;
int hour = 0;
bool workFinished = false;

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

int main()
{
    hour = 9;
    writeProgram();
    hour = 10;
    writeProgram();
    hour = 12;
    writeProgram();
    hour = 13;
    writeProgram();
    hour = 14;
    writeProgram();
    hour = 17;
    writeProgram();
    
    workFinished = false;

    writeProgram();
    hour = 19;
    writeProgram();
    hour = 22;
    writeProgram();
    return 0;
}