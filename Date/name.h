#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

/**
*描述：Date类日期
*作者：陈健宇
*时间：2018-2-8  21:49
*/

#include <iostream>

using namespace std;
using std::basic_ostream;

namespace name
{
    enum class Month
    { jan = 1,fed,mar,apr,may,jun,jul,aug,sep,oct,nov,dec };
    class Date
    {
        public :
            class Invalid{};// 作为异常抛出
            Date();// 默认构造函数
            Date(int ,Month ,int );// 检查日期的合法性并初始化--一般构造函数

            // 不改变对象的成员函数
            int Getyear() const {return(_y);}
            Month Getmon() const {return(_m);}
            int Getday() const {return(_d);}

            // 改变对象的成员函数
            void Setyear(int );
            void Setmon(Month );
            void Setday(int );

        private :
            int _y;// 年
            Month _m;// 月
            int _d;// 日
        };

        // 辅助函数
        bool is_date(int ,Month ,int );// 当日期合法时返回true
        bool is_leapyear(int );// 当y是闰年时返回true
        const Date& default_date();

        // 重载运算符
        bool operator==(const Date& a,const Date& b);
        bool operator!=(const Date& a,const Date& b);
        istream& operator>>(istream& is,const Date& dd);
        ostream& operator<<(ostream& os,const Date& d);
        Month operator++(Month& m);

};

#endif // NAME_H_INCLUDED
