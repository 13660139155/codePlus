#include "LandOwner.h"

LandOwner::LandOwner()
{
    Setname("系统");
    Setsex("保密");
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
 * 显示地主基本信息
 */
void LandOwner::ShowInfo()
{
    cout << "昵称：" << Getname() << endl;
    cout << "性别：" << Getsex() << endl;
    cout << "金币：" << Getgold() << endl;
    cout << "经验：" << Getexp() << endl;
}

/**
 * 手牌初始化
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
  * 显示手牌
  * cards 要显示的手牌
  */
void LandOwner::ShowCards(const vector<int>& cards)
{
    /* C语言习惯
    for(int i=0;i<cards.size();i++)
    {
        cout << cards[i] << "," ;
    }
    cout << endl;
     */

    /* 使用迭代器
    vector<int>::const_iterator it;// 得到迭代器对象
    for(it=cards.begin();it!=cards.end();it++)
    {
        cout << *it << ",";
    }
    cout << endl;
     */

    /* 使用C++11中auto类型推断
    for(auto it=cards.begin();it!=cards.end();it++)
    {
        cout << *it << ",";
    }
    cout << endl;
     */

    /* 使用算法的方式，将容器的内容复制到cout绑定的迭代器中
     * #include <iterator>
     * #include <algorithm>
     copy(cards.cbegin(),cards.cend(),ostream_iterator<int>(cout,","));
     cout << endl;
     */

    /** for遍历 */
     for(auto card:cards)
     {
         cout << card << "-" << getColor(card) << "(" << getCard(card) << ")" << ",";
     }
     cout << endl;
}

/**
 * 摸牌
 * cardscount 要摸的手牌数
 */
void LandOwner::TouchCards(int cardscount)
{
    srand(time(NULL));
    cout << Getname() << "当前手牌如下：" << endl;
    ShowCards(playerCards);
    cout << "当前剩余的牌如下：" << endl;
    ShowCards(surplusCards);
    ShowCards(playerCards);
    for(int i=0;i<cardscount;i++)
    {
        int cardIndex = rand()%54;// 0~53随机数
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
    cout << Getname() << "摸了" << cardscount << "张牌后,手牌如下：" << endl;
    ShowCards(playerCards);
    cout << "<" << Getname() << ">摸了" << cardscount << "张牌后，剩余的牌如下：" << endl;
    ShowCards(surplusCards);
}

/**
 * 判断要摸的牌面是否属于剩余的手牌
 * card 要摸的手牌
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
 * 删除一个属于剩余的手牌的手牌
 * card 要删除的手牌
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
 * 获得花色
 * card 哪一张牌要获得花色
 */
string LandOwner::getColor(int card)
{
    string color[]{"黑桃","红桃","方块","梅花"};
    if(card==53)
        return("小王");
    if(card==54)
        return("大王");
    return(color[(card-1)/13]);

}

/**
 * 获得牌面
 * card 哪一张牌要获得牌面
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
