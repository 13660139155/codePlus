#include <iostream>
#include <iomanip>

using namespace std;

/* ʹ�ú���ʵ����Ϸ�е�˽�� */
/**
 *�����˷�����Ϣ
 *@param name ���˵�����
 *@param content ����˷��͵�������Ϣ
 *@return ������������
 */
string tochat(const string& ,const string& );
/**
 *���˻ظ���Ϣ
 *@param name ���˵�����
 *@param content �ظ���������Ϣ
 *@return ������������
 */
string formchat(const string& = "ϵͳ",const string& = "�Է�������");


/* ʹ��ģ�弼��ʵ�ֲ�ͬ�������ݵ��������� */
/**
 *����������ģ������
 */
template<typename T>void Sort(T* ,int );

/**
 *�����ӡ���麯��ģ������
 */
template<typename T>void Show(T* ,int );

int main()
{
    int numi[] = {12,3,56,13,1,5};
    float numf[] = {12.3f,5.3f,56.4f,2.1f,57.3f,9.2f};
    double numd[] = {23.4,45.3,12.1,45,4,12.3,1,1};

    cout<<setw(15)<<"��������"<<endl;
    cout<<"����ǰ��";
    Show(numi,sizeof(numi)/sizeof(int));
    cout<<endl;
    cout<<"�����";
    Sort(numi,sizeof(numi)/sizeof(int));
    Show(numi,sizeof(numi)/sizeof(int));
    cout<<endl<<endl;

    cout<<setw(17)<<"float������"<<endl;
    cout<<"����ǰ��";
    Show(numf,sizeof(numf)/sizeof(float));
    cout<<endl;
    cout<<"�����";
    Sort(numf,sizeof(numf)/sizeof(float));
    Show(numf,sizeof(numf)/sizeof(float));
    cout<<endl<<endl;

    cout<<setw(18)<<"double������"<<endl;
    cout<<"����ǰ��";
    Show(numd,sizeof(numd)/sizeof(double));
    cout<<endl;
    cout<<"�����";
    Sort(numd,sizeof(numd)/sizeof(double));
    Show(numd,sizeof(numd)/sizeof(double));
    cout<<endl;







    /*
    string name,context;
    cout<<"������Է������֣�";
    getline(cin,name);
    cout<<"��������Ҫ�ԶԷ�˵�Ļ���";
    cin>>context;
    cout<<tochat(name,context)<<endl;
    cout<<formchat()<<endl;
    */
    return 0;
}

string tochat(const string& name,const string& content)
{
    string chat_content = "�������Ķԡ�"+name+"��˵:"+content;
    return(chat_content);
}
string formchat(const string& name,const string& content)
{
    string chat_content = "��"+name+"���ظ�����һ����Ϣ��"+content;
    return(chat_content);
}


/**
 *����������ģ��ʵ��
 *T ��������
 *num ����
 *len ����ĳ���
 */
template<typename T>
void Sort(T* num,int len)
{
   T temp;
   int k = 0;
   for(int i=0;i<len-1;i++)
   {
      k = i;
      for(int j=k;j<len;j++)
      {
          if(num[j]<num[k])
          {
              k =j;
          }
      }
      if(k!=i)
      {
          temp = num[i];
          num[i] = num[k];
          num[k] = temp;
      }
   }
}

/**
 *�����ӡ���麯��ģ��ʵ��
 *T ��������
 *num Ҫ��������������ָ��
 *len ���鳤��
 */
template<typename T>
void Show(T* num,int len)
{
   for(int i=0;i<len;i++)
   {
       cout<<num[i]<<",";
   }
}
