#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int result = rand() % 1000;
    cout << "\033[1;32m������������һ�������ֵ���Ϸ�ɣ�\033[0m" << endl;
    while (true)
    {
        int guess = 0;
        cout << "��²���������Ƕ��:";
        cin >> guess;
        if (guess < result)
        {
            cout << "��ѽ����µ��е�С��" << endl;
        }
        else if (guess > result)
        {
            cout << "��ѽ����µ��е��" << endl;
        }
        else
        {
            cout << "�¶�����������־���" << result << endl;
            break;
        }
    }
    return 0;
}