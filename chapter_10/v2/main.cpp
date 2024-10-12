#include <iostream>

using namespace std;

class TestPaper
{
public:
    void testQuestion1()
    {
        cout << "����õ����������˹������������콣��������������������[]\n" << 
            "a.��ī���� b.����� c.���ٺϽ�� d.̼����ά" << endl;
        cout << "��: " << answer1() << endl;
    }
    void testQuestion2()
    {
        cout << "�������Ӣ��½��˫�������黨�����[]\n" << 
            "a.ʹ����ֲ�ﲻ�ٺ��� b.ʹһ����ϡ������� c.�ƻ����Ǹ�����Ȧ����̬ƽ�� d.��ɸõ���ɳĮ��" << endl;
        cout << "��: " << answer2() << endl;
    }
    void testQuestion3()
    {
        cout << "�������ʹ��ɽʦͽ���ҹ�����Ż�²�ֹ��������Ǵ�򣬻�����ǿ�ʲôҩ[]\n" << 
            "a.��˾ƥ�� b.ţ�ƽⶾƬ c.������ d.�����Ǻȴ�������ţ�� e.����ȫ����" << endl;
        cout << "��: " << answer3() << endl;
    }
    virtual ~TestPaper() = default;

protected:
    virtual string answer1() = 0;
    virtual string answer2() = 0;
    virtual string answer3() = 0;
};

class TestPaperA: public TestPaper
{
protected:
    string answer1() override { return string("b"); }
    string answer2() override { return string("a"); }
    string answer3() override { return string("c"); }
};

class TestPaperB: public TestPaper
{
protected:
    string answer1() override { return string("d"); }
    string answer2() override { return string("b"); }
    string answer3() override { return string("a"); }
};

int main()
{
    cout << "ѧ���׳����Ծ�: " << endl;
    TestPaperA studentA;
    studentA.testQuestion1();
    studentA.testQuestion2();
    studentA.testQuestion3();

    cout << "ѧ���ҳ����Ծ�: " << endl; 
    TestPaperB studentB;
    studentB.testQuestion1();
    studentB.testQuestion2();
    studentB.testQuestion3();

    return 0;
}