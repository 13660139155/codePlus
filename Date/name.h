#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

/**
*������Date������
*���ߣ��½���
*ʱ�䣺2018-2-8  21:49
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
            class Invalid{};// ��Ϊ�쳣�׳�
            Date();// Ĭ�Ϲ��캯��
            Date(int ,Month ,int );// ������ڵĺϷ��Բ���ʼ��--һ�㹹�캯��

            // ���ı����ĳ�Ա����
            int Getyear() const {return(_y);}
            Month Getmon() const {return(_m);}
            int Getday() const {return(_d);}

            // �ı����ĳ�Ա����
            void Setyear(int );
            void Setmon(Month );
            void Setday(int );

        private :
            int _y;// ��
            Month _m;// ��
            int _d;// ��
        };

        // ��������
        bool is_date(int ,Month ,int );// �����ںϷ�ʱ����true
        bool is_leapyear(int );// ��y������ʱ����true
        const Date& default_date();

        // ���������
        bool operator==(const Date& a,const Date& b);
        bool operator!=(const Date& a,const Date& b);
        istream& operator>>(istream& is,const Date& dd);
        ostream& operator<<(ostream& os,const Date& d);
        Month operator++(Month& m);

};

#endif // NAME_H_INCLUDED
