/**
*������
*���ߣ��½���
*ʱ�䣺2018-2-8  21:49
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

        void ShowInfo();// ��ʾ����������Ϣ
        void TouchCards(int );// ����

        vector<int>defaultCards;// Ĭ������
        vector<int>surplusCards;// ʣ�������
        vector<int>playerCards;// ��ҵ�ǰ������

    protected:

    private:
        string m_name;
        string m_sex;
        int m_gold;
        int m_exp;

        void CardsInit();// ���Ƴ�ʼ��;
        void ShowCards(const vector<int>&);// ��ʾ����
        bool judgecard(int );// �ж�Ҫ���������Ƿ�����ʣ�������
        void deletecard(int );// ɾ��һ������ʣ������Ƶ�����
        string getColor(int );// ��û�ɫ
        string getCard(int );// �������
};

#endif // LANDOWNER_H
