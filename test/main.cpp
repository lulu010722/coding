#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int result = rand() % 1000;
    cout << "\033[1;32m下面我们来玩一个猜数字的游戏吧！\033[0m" << endl;
    while (true)
    {
        int guess = 0;
        cout << "你猜猜这个数字是多大？:";
        cin >> guess;
        if (guess < result)
        {
            cout << "哎呀，你猜的有点小！" << endl;
        }
        else if (guess > result)
        {
            cout << "哎呀，你猜的有点大！" << endl;
        }
        else
        {
            cout << "猜对啦！这个数字就是" << result << endl;
            break;
        }
    }
    return 0;
}