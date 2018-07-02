#include "LandOwner.h"

LandOwner::LandOwner()
{
    Setname("ϵͳ");
    Setsex("����");
    Setexp(0);
    Setgold(1000);

    CardsInit();
}

LandOwner::LandOwner(string name,string sex) : m_name(name),m_sex(sex)
{
    Setexp(0);
    Setgold(1000);

    CardsInit();
}

/**
 * ��ʾ����������Ϣ
 */
void LandOwner::ShowInfo()
{
    cout << "�ǳƣ�" << Getname() << endl;
    cout << "�Ա�" << Getsex() << endl;
    cout << "��ң�" << Getgold() << endl;
    cout << "���飺" << Getexp() << endl;
}

/**
 * ���Ƴ�ʼ��
 */
void LandOwner::CardsInit()
{
    for(int i=0;i<54;i++)
    {
        defaultCards.push_back(i+1);
        surplusCards.push_back(defaultCards.at(i));
    }
    playerCards.clear();
}

/**
  * ��ʾ����
  * cards Ҫ��ʾ������
  */
void LandOwner::ShowCards(const vector<int>& cards)
{
    /* C����ϰ��
    for(int i=0;i<cards.size();i++)
    {
        cout << cards[i] << "," ;
    }
    cout << endl;
     */

    /* ʹ�õ�����
    vector<int>::const_iterator it;// �õ�����������
    for(it=cards.begin();it!=cards.end();it++)
    {
        cout << *it << ",";
    }
    cout << endl;
     */

    /* ʹ��C++11��auto�����ƶ�
    for(auto it=cards.begin();it!=cards.end();it++)
    {
        cout << *it << ",";
    }
    cout << endl;
     */

    /* ʹ���㷨�ķ�ʽ�������������ݸ��Ƶ�cout�󶨵ĵ�������
     * #include <iterator>
     * #include <algorithm>
     copy(cards.cbegin(),cards.cend(),ostream_iterator<int>(cout,","));
     cout << endl;
     */

    /** for���� */
     for(auto card:cards)
     {
         cout << card << "-" << getColor(card) << "(" << getCard(card) << ")" << ",";
     }
     cout << endl;
}

/**
 * ����
 * cardscount Ҫ����������
 */
void LandOwner::TouchCards(int cardscount)
{
    srand(time(NULL));
    cout << Getname() << "��ǰ�������£�" << endl;
    ShowCards(playerCards);
    cout << "��ǰʣ��������£�" << endl;
    ShowCards(surplusCards);
    ShowCards(playerCards);
    for(int i=0;i<cardscount;i++)
    {
        int cardIndex = rand()%54;// 0~53�����
        if(judgecard(defaultCards[cardIndex]))
        {
            playerCards.push_back(defaultCards[cardIndex]);
            deletecard(defaultCards[cardIndex]);

        }
        else
        {
            i--;
        }
    }
    cout << Getname() << "����" << cardscount << "���ƺ�,�������£�" << endl;
    ShowCards(playerCards);
    cout << "<" << Getname() << ">����" << cardscount << "���ƺ�ʣ��������£�" << endl;
    ShowCards(surplusCards);
}

/**
 * �ж�Ҫ���������Ƿ�����ʣ�������
 * card Ҫ��������
 */
bool LandOwner::judgecard(int card)
{
    vector<int>::iterator it;
    for(it=surplusCards.begin();it!=surplusCards.end();it++)
    {
        if(*it==card)
        {  return true; break; }
    }
    return false;
    /*
    vector<int>::iterator it = find(surplusCards.begin(),surplusCards.end(),card);
    if(it==surplusCards.end())
        return false;
    return true;
    */

}

/**
 * ɾ��һ������ʣ������Ƶ�����
 * card Ҫɾ��������
 */
void LandOwner::deletecard(int card)
{
    for(auto it=surplusCards.begin();it!=surplusCards.end();++it)
    {
        if(*it==card)
        {
            surplusCards.erase(it);
            break;
        }
    }
    /*
    auto it = find(surplusCards.begin(),surplusCards.end(),card);
    if(it!=surplusCards.end())
        surplusCards.erase(it);
    */
}

/**
 * ��û�ɫ
 * card ��һ����Ҫ��û�ɫ
 */
string LandOwner::getColor(int card)
{
    string color[]{"����","����","����","÷��"};
    if(card==53)
        return("С��");
    if(card==54)
        return("����");
    return(color[(card-1)/13]);

}

/**
 * �������
 * card ��һ����Ҫ�������
 */
string LandOwner::getCard(int card)
{
    string cards[]{"A","1","2","3","4","5","6","7","8","9","10","J","Q","K"};
    if(card==53)
        return("Black Joker");
    if(card==54)
        return("Red Joker");
    return(cards[(card-1)%13]);
}

LandOwner::~LandOwner()
{
    // ctor
}
