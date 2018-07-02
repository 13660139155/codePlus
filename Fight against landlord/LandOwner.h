/**
*描述：
*作者：陈健宇
*时间：2018-2-8  21:49
*/#ifndef LANDOWNER_H
#define LANDOWNER_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>

using namespace std;

class LandOwner
{
    public:
        LandOwner();
        LandOwner(string ,string );
        ~LandOwner();

        string Getname() { return m_name; }
        void Setname(string val) { m_name = val; }
        string Getsex() { return m_sex; }
        void Setsex(string val) { m_sex = val; }
        int Getgold() { return m_gold; }
        void Setgold(int val) { m_gold = val; }
        int Getexp() { return m_exp; }
        void Setexp(int val) { m_exp = val; }

        void ShowInfo();// 显示地主基本信息
        void TouchCards(int );// 摸牌

        vector<int>defaultCards;// 默认手牌
        vector<int>surplusCards;// 剩余的手牌
        vector<int>playerCards;// 玩家当前的手牌

    protected:

    private:
        string m_name;
        string m_sex;
        int m_gold;
        int m_exp;

        void CardsInit();// 手牌初始化;
        void ShowCards(const vector<int>&);// 显示手牌
        bool judgecard(int );// 判断要摸的牌面是否属于剩余的手牌
        void deletecard(int );// 删除一个属于剩余的手牌的手牌
        string getColor(int );// 获得花色
        string getCard(int );// 获得牌面
};

#endif // LANDOWNER_H
