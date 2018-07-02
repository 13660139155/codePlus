#include <iostream>
#include <array>
#include <conio.h>
using namespace std;

int main()
{
    /** 星座数组 */
    string constellation[12][2]{
        {"摩羯座","水瓶座"},//一月
        {"水瓶座","双鱼座"},//二月
        {"双鱼座","白羊座"},//三月
        {"白羊座","金牛座"},//四月
        {"金牛座","双子座"},//五月
        {"双子座","巨蟹座"},//六月
        {"巨蟹座","狮子座"},//七月
        {"狮子座","处女座"},//八月
        {"处女座","天秤座"},//九月
        {"天秤座","天蝎座"},//十月
        {"天蝎座","射手座"},//十一月
        {"射手座","摩羯座"},//十二月
        };
    /**  跨星座的日期 */
    array<int,12>constellation_date{20,19,21,20,21,21,23,23,23,23,22,22};
    /** 出生年 */
    int value_year;
    /** 出生月 */
    int value_month;
    /** 出生日 */
    int value_day;
    /** 星座 */
    string constell;
    cout<<"测测你是什么星座?"<<endl;
    cout<<"请输入你的出生年月日（year month day）："<<endl;
    cin>>value_year>>value_month>>value_day;
    constell=constellation[value_month-1][value_day/constellation_date[value_month-1]];
    cout<<constell<<endl;

    getch();
    return 0;
}
