#include<iostream>

using namespace std;

class TestPaperA
{
public:
    void testQuestion1()
    {
        cout << "����õ����������˹������������콣��������������������[]\n" << 
            "a.��ī���� b.����� c.���ٺϽ�� d.̼����ά" << endl;
        cout << "��: b" << endl;
    }
    void testQuestion2()
    {
        cout << "�������Ӣ��½��˫�������黨�����[]\n" << 
            "a.ʹ����ֲ�ﲻ�ٺ��� b.ʹһ����ϡ������� c.�ƻ����Ǹ�����Ȧ����̬ƽ�� d.��ɸõ���ɳĮ��" << endl;
        cout << "��: a" << endl;
    }
    void testQuestion3()
    {
        cout << "�������ʹ��ɽʦͽ���ҹ�����Ż�²�ֹ��������Ǵ�򣬻�����ǿ�ʲôҩ[]\n" << 
            "a.��˾ƥ�� b.ţ�ƽⶾƬ c.������ d.�����Ǻȴ�������ţ�� e.����ȫ����" << endl;
        cout << "��: c" << endl;
    }
};

class TestPaperB
{
public:
    void testQuestion1()
    {
        cout << "����õ����������˹������������콣��������������������[]\n" << 
            "a.��ī���� b.����� c.���ٺϽ�� d.̼����ά" << endl;
        cout << "��: d" << endl;
    }
    void testQuestion2()
    {
        cout << "�������Ӣ��½��˫�������黨�����[]\n" << 
            "a.ʹ����ֲ�ﲻ�ٺ��� b.ʹһ����ϡ������� c.�ƻ����Ǹ�����Ȧ����̬ƽ�� d.��ɸõ���ɳĮ��" << endl;
        cout << "��: b" << endl;
    }
    void testQuestion3()
    {
        cout << "�������ʹ��ɽʦͽ���ҹ�����Ż�²�ֹ��������Ǵ�򣬻�����ǿ�ʲôҩ[]\n" << 
            "a.��˾ƥ�� b.ţ�ƽⶾƬ c.������ d.�����Ǻȴ�������ţ�� e.����ȫ����" << endl;
        cout << "��: a" << endl;
    }
};

int main()
{
    cout << "ѧ���׳����Ծ�: " << endl;
    TestPaperA studentA;
    studentA.testQuestion1();
    studentA.testQuestion2();
    studentA.testQuestion3();

    TestPaperB studentB;
    studentB.testQuestion1();
    studentB.testQuestion2();
    studentB.testQuestion3();

    return 0;
}