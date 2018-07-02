#include "name.h"

namespace name
{
    Date::Date(int y,Month m,int d):_y{y},_m{m},_d{d}
    {
        if(!is_date(y,m,d))
            throw Invalid();
    }

    const Date& default_date()
    {
        static Date dd{2001,Month::jan,1};//默认21世纪开始
        return(dd);
    }
    Date::Date():_y{default_date().Getyear()},_m{default_date().Getmon()},_d{default_date().Getday()}
    {}

    void Date::Setday(int d)
    {
        _d = ++d;
    }
    void Date::Setmon(Month m)
    {
        _m = ++m;
    }
    void Date::Setyear(int y)
    {
        _y = ++y;
    }

    bool is_date(int y,Month m,int d)
    {
        int day_month = 31;
        if(y<=0||d<=0)
            return false;
        if(m<Month::jan||m>Month::dec)
            return false;
        switch(m)
        {
        case Month::fed:
            day_month = (is_leapyear(y))?29:28;
        case Month::apr:case Month::jun:case Month::sep:case Month::nov:
            day_month = 30;
        }
        if(d>day_month)
            return false;
        return true;
    }
    bool is_leapyear(int y){}

    bool operator==(const Date& a,const Date& b)
    {
        return (a.Getyear()==b.Getyear()&&a.Getmon()==b.Getmon()&&a.Getday()==b.Getday());
    }
    bool operator!=(const Date& a,const Date& b)
    {
        return (a!=b);
    }
    ostream& operator<<(ostream& os,const Date& d)
    {
        return os<<'('<<d.Getyear()<<','<<d.Getmon()<<','<<d.Getday<<')';
    }
    istream& operator>>(istream& is,const Date& dd)
    {
        return(is);
    }
    Month operator++(Month& m)
    {
        m = (m==Month::dec)?Month::jan:Month(int(m)+1);
        return(m);
    }

}
