#include <iostream>
#include <array>
#include <conio.h>
using namespace std;

int main()
{
    /** �������� */
    string constellation[12][2]{
        {"Ħ����","ˮƿ��"},//һ��
        {"ˮƿ��","˫����"},//����
        {"˫����","������"},//����
        {"������","��ţ��"},//����
        {"��ţ��","˫����"},//����
        {"˫����","��з��"},//����
        {"��з��","ʨ����"},//����
        {"ʨ����","��Ů��"},//����
        {"��Ů��","�����"},//����
        {"�����","��Ы��"},//ʮ��
        {"��Ы��","������"},//ʮһ��
        {"������","Ħ����"},//ʮ����
        };
    /**  ������������ */
    array<int,12>constellation_date{20,19,21,20,21,21,23,23,23,23,22,22};
    /** ������ */
    int value_year;
    /** ������ */
    int value_month;
    /** ������ */
    int value_day;
    /** ���� */
    string constell;
    cout<<"�������ʲô����?"<<endl;
    cout<<"��������ĳ��������գ�year month day����"<<endl;
    cin>>value_year>>value_month>>value_day;
    constell=constellation[value_month-1][value_day/constellation_date[value_month-1]];
    cout<<constell<<endl;

    getch();
    return 0;
}
