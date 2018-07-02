#include <iostream>
#include <iomanip>

using namespace std;

/* 使用函数实现游戏中的私聊 */
/**
 *向他人发送信息
 *@param name 他人的名字
 *@param content 向别人发送的聊天信息
 *@return 返回聊天内容
 */
string tochat(const string& ,const string& );
/**
 *他人回复信息
 *@param name 他人的名字
 *@param content 回复的聊天信息
 *@return 返回聊天内容
 */
string formchat(const string& = "系统",const string& = "对方已下线");


/* 使用模板技术实现不同类型数据的数组排序 */
/**
 *定义排序函数模板声明
 */
template<typename T>void Sort(T* ,int );

/**
 *定义打印数组函数模板声明
 */
template<typename T>void Show(T* ,int );

int main()
{
    int numi[] = {12,3,56,13,1,5};
    float numf[] = {12.3f,5.3f,56.4f,2.1f,57.3f,9.2f};
    double numd[] = {23.4,45.3,12.1,45,4,12.3,1,1};

    cout<<setw(15)<<"整型数组"<<endl;
    cout<<"排序前：";
    Show(numi,sizeof(numi)/sizeof(int));
    cout<<endl;
    cout<<"排序后：";
    Sort(numi,sizeof(numi)/sizeof(int));
    Show(numi,sizeof(numi)/sizeof(int));
    cout<<endl<<endl;

    cout<<setw(17)<<"float型数组"<<endl;
    cout<<"排序前：";
    Show(numf,sizeof(numf)/sizeof(float));
    cout<<endl;
    cout<<"排序后：";
    Sort(numf,sizeof(numf)/sizeof(float));
    Show(numf,sizeof(numf)/sizeof(float));
    cout<<endl<<endl;

    cout<<setw(18)<<"double型数组"<<endl;
    cout<<"排序前：";
    Show(numd,sizeof(numd)/sizeof(double));
    cout<<endl;
    cout<<"排序后：";
    Sort(numd,sizeof(numd)/sizeof(double));
    Show(numd,sizeof(numd)/sizeof(double));
    cout<<endl;







    /*
    string name,context;
    cout<<"请输入对方的名字：";
    getline(cin,name);
    cout<<"请输入你要对对方说的话：";
    cin>>context;
    cout<<tochat(name,context)<<endl;
    cout<<formchat()<<endl;
    */
    return 0;
}

string tochat(const string& name,const string& content)
{
    string chat_content = "※你悄悄对【"+name+"】说:"+content;
    return(chat_content);
}
string formchat(const string& name,const string& content)
{
    string chat_content = "【"+name+"】回复了你一条信息："+content;
    return(chat_content);
}


/**
 *定义排序函数模板实现
 *T 虚拟类型
 *num 数组
 *len 数组的长度
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
 *定义打印数组函数模板实现
 *T 虚拟类型
 *num 要传过来的数组首指针
 *len 数组长度
 */
template<typename T>
void Show(T* num,int len)
{
   for(int i=0;i<len;i++)
   {
       cout<<num[i]<<",";
   }
}
