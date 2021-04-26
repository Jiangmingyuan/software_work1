#include <bits/stdc++.h>
using namespace std;
struct Material//�ṹ�彨��
{
    int No;//���
    string name;//����
    int price;//����
    int innumber;//�������
    int stillnumber;//�������
    int outnumber;//��������
    string protector;//������
    int indate[3];//����ʱ��
    int outdate[3];//����ʱ��
    string remarks;//��ע
    Material *next;
};
Material *head=NULL;//ȫ�ֱ��� ͷָ��
Material *findtail(Material *head)//Ѱ��βָ��
{
    Material *Tail= NULL;
    for (Tail= head; Tail->next!= NULL; Tail= Tail->next) ;
    return Tail;
}
void wendangduru()//�ļ����뺯��
{
    Material *p=NULL;
    Material *pre=NULL;
    head=NULL;
    Material *tail=NULL;
    ifstream rfile;
    string filename="���Ϲ���ϵͳ.txt";
    rfile.open(filename.c_str());
    if(rfile.is_open())
    {
    }
    while(rfile.good())
        {
            p=new Material;
            rfile>>p->No>> p->name>>p->price>>p->innumber>>p->stillnumber>>p->outnumber>>p->protector>>p->indate[0]>>p->indate[1]>>p->indate[2]>>p->outdate[0]>>p->outdate[1]>>p->outdate[2]>>p->remarks;
            if(head==NULL)
                head=p;
            else
                pre->next=p;
            pre=p;
            tail=pre;
            p->next=NULL;
            if(rfile.eof())
            {
                return;
            }
            if(rfile.fail())
            {
            }

        }
}
void Input(int x)//���뺯��
{
    Material *tail;
    if(x==1)
    {
        tail=findtail(head);
    }
    else
        tail=NULL;
    cout<<"*  �ɹ�ִ�����뺯��  *"<<endl;
    Material *p=NULL;
    Material *pre=NULL;
    while(1)
    {
        p=new Material;
        cout<<"��������ϱ�ţ�";
        cin>>p->No;
        if(p->No==-1)
        {
            pre->next=NULL;
            cout<<"*  ���뺯����������  *"<<endl;
            return;
        }
        else
        {
            getchar();
            cout<<"������������ƣ�";
            getline(cin,p->name);
            cout<<"��������ϵ��ۣ�";
            cin>>p->price;
            cout<<"������������������";
            cin>>p->innumber;
            cout<<"��������Ͽ��������";
            cin>>p->stillnumber;
            cout<<"��������ϳ���������";
            cin>>p->outnumber;
            getchar();
            cout<<"��������ϱ����ˣ�";
            getline(cin,p->protector);
            cout<<"��������Ͻ���ʱ�䣨�� �� �գ���";
            cin>>p->indate[0]>>p->indate[1]>>p->indate[2];
            cout<<"��������ϳ���ʱ�䣨�� �� �գ���";
            cin>>p->outdate[0]>>p->outdate[1]>>p->outdate[2];
            getchar();
            cout<<"��������ϱ�ע��";
            getline(cin,p->remarks);
            cout<<"��������������ɣ��������������ֻ��������Ϊ-1����"<<endl;
            if(head==NULL)
                head=p;
            else
                {
                    if(x==1)
                        tail->next=p;
                    else
                        pre->next=p;
                }
                pre=p;
                tail=pre;
        }
    }
}
void Display()//��ʾ����
{
    cout<<"*  �ɹ�ִ����ʾ����  *"<<endl;
    Material *p=new Material;
    for(p=head;p!=NULL;p=p->next)
    {
        cout<<"��ţ�"<<p->No<<endl;
        cout<<"���ƣ�"<<p->name<<endl;
        cout<<"���ۣ�"<<p->price<<endl;
        cout<<"���������"<<p->innumber<<endl;
        cout<<"���������"<<p->stillnumber<<endl;
        cout<<"����������"<<p->outnumber<<endl;
        cout<<"�����ˣ�"<<p->protector<<endl;
        cout<<"����ʱ�䣺"<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
        cout<<"����ʱ�䣺"<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
        cout<<"��ע��"<<p->remarks<<endl;
        cout<<endl;
    }
    return;
}
void Modify()//�޸ĺ���
{
    Material *tail;
    tail=findtail(head);
    cout<<"*  �ɹ�ִ���޸ĺ���  *"<<endl;
    char x;
    string y;
    int aim;
    cout<<"��������Ҫ�޸ĵ����"<<endl;
    cin>>aim;//������Ҫ�޸ĵı��
    getchar();
    int o=1;
    Material *p=new Material;
    Material *pre=NULL;
    for(p=head;p!=NULL;p=p->next)
    {
        if(p->No==aim)
            o=0;
    }
    if(o==1)
        {cout<<"�޴˱������������"<<endl;return;}
    while(1)
    {
       // clrscr(); // ����Ļ
        printf("* * * * * *ѡ��˱������Ҫ�޸ĵ�����* * * * * *\n");
        printf("*       a. ���     *\n");
        printf("*       b. ����    *\n");
        printf("*       c. ����    *\n");
        printf("*       d. �������      *\n");
        printf("*       e. �������      *\n");
        printf("*       f. ��������      *\n");
        printf("*       g. ������      *\n");
        printf("*       h. ����ʱ��      *\n");
        printf("*       i. ����ʱ��      *\n");
        printf("*       j. ��ע      *\n");
        printf("*       k. ɾ������      *\n");
        printf("*       l. �˳�      *\n");
        printf("*   ������a~l    *\n");
        printf("* * * * * * * * * * * * * *\n");
        cin>>x;
        if(x=='l')
            {return ;}
        else switch(x)
        {
        case 'a': y="No";getchar();break;
        case 'b': y="name";getchar();break;
        case 'c': y="price";getchar();break;
        case 'd': y="innumber";getchar();break;
        case 'e': y="stillnumber";getchar(); break;
        case 'f': y="outnumber";getchar(); break;
        case 'g': y="protector";getchar(); break;
        case 'h': y="indate";getchar(); break;
        case 'i': y="outdate";getchar(); break;
        case 'j': y="remarks";getchar(); break;
        case 'l': y="delete";getchar(); break;
        }

        for(p=head;p!=NULL;p=p->next)
        {

            if(p->No==aim)
            {
                cout<<"��������Ҫ�޸ĺ������"<<endl;
                if(y=="No")
                {
                    int newNo;
                    cin>>newNo;
                    p->No=newNo;
                    break;
                }
                if(y=="name")
                {
                    string newname;
                    getline(cin,newname);
                    p->name.assign(newname);
                    break;
                }
                if(y=="price")
                {
                    int newprice;
                    cin>>newprice;
                    p->price=newprice;
                    break;
                }
                if(y=="innumber")
                {
                    int newinnumber;
                    cin>>newinnumber;
                    p->innumber=newinnumber;
                    break;
                }
                if(y=="stillnumber")
                {
                    int newstillnumber;
                    cin>>newstillnumber;
                    p->stillnumber=newstillnumber;
                    break;
                }
                if(y=="outnumber")
                {
                    int newoutnumber;
                    cin>>newoutnumber;
                    p->outnumber=newoutnumber;
                    break;
                }
                if(y=="protector")
                {
                    string newprotector;
                    getline(cin,newprotector);
                    p->protector.assign(newprotector);
                    break;
                }
                if(y=="indate")
                {
                    int newindate[3];
                    cin>>newindate[0]>>newindate[1]>>newindate[2];
                    p->indate[0]=newindate[0];cout<<"!!!!"<<newindate[0]<<endl;
                    p->indate[1]=newindate[1];
                    p->indate[2]=newindate[2];
                    break;
                }
                if(y=="outdate")
                {
                    int newoutdate[3];
                    cin>>newoutdate[0]>>newoutdate[1]>>newoutdate[2];
                    p->outdate[0]=newoutdate[0];
                    p->outdate[1]=newoutdate[1];
                    p->outdate[2]=newoutdate[2];
                    break;
                }
                if(y=="remarks")
                {
                    string newremarks;
                    getline(cin,newremarks);
                    p->remarks.assign(newremarks);
                    break;
                }
                if(y=="delete")
                {
                    if(p==head)
                    {
                        head=p->next;
                        break;
                    }
                    else
                    {
                        if(p->next=NULL)
                            tail=pre;
                        pre->next=p->next;
                        break;
                    }
                }
            }
            pre=p;
        }
    }
    return;
}
void Find()//���Һ���
{
    cout<<"*  �ɹ�ִ�в��Һ���  *"<<endl;
    char i;
    int x=0;
    int first=1;
    while(1)
    {
        if(first==1)
            getchar();//clrscr(); // ����Ļ
        first=0;
        printf("* * * * * *Menue* * * * * *\n");
        printf("*       a. ��֪��Ų���      *\n");
        printf("*       b. ��֪���Ʋ���    *\n");
        printf("*       c. ��֪���۲���    *\n");
        printf("*       d. ��֪�����������    *\n");
        printf("*       e. ��֪�����������    *\n");
        printf("*       f. ��֪������������    *\n");
        printf("*       g. ��֪�����˲���    *\n");
        printf("*       h. ��֪����ʱ�����    *\n");
        printf("*       i. ��֪����ʱ�����    *\n");
        printf("*       j. ��֪��ע����    *\n");
        printf("*       k. Exit      *\n");
        printf("*    Please select a to k    *\n");
        printf("* * * * * * * * * * * * * *\n");
        cin>> i;//i=getchar();
        if(i=='k') return;
        else switch(i)
        {
        case 'a': x=1;break;
        case 'b': x=2;getchar();break;
        case 'c': x=3;break;
        case 'd': x=4;break;
        case 'e': x=5;break;
        case 'f': x=6;break;
        case 'g': x=7;break;
        case 'h': x=8;break;
        case 'i': x=9;break;
        case 'j': x=10;break;
        }
        Material *p=new Material;
            if(x==1)//��֪��Ų���
            {
                int flag=0;
                int aim;
                cout<<"������Ŀ����"<<endl;
                cin>>aim;//�������Ŀ����
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->No==aim)
                    {
                        flag=1;
                        cout<<"��ţ�"<<p->No<<endl;
                        cout<<"���ƣ�"<<p->name<<endl;
                        cout<<"���ۣ�"<<p->price<<endl;
                        cout<<"���������"<<p->innumber<<endl;
                        cout<<"���������"<<p->stillnumber<<endl;
                        cout<<"����������"<<p->outnumber<<endl;
                        cout<<"�����ˣ�"<<p->protector<<endl;
                        cout<<"����ʱ�䣺"<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                        cout<<"����ʱ�䣺"<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                        cout<<"��ע��"<<p->remarks<<endl;
                    }
                }
                if(flag==0)
                        cout<<"�޸���Ų��ϣ�����������Ѱ�ҷ�ʽ"<<endl;
            }
            if(x==2)
            {
                int flag=0;
                string aim;//�������Ŀ������
                cout<<"������Ŀ������"<<endl;
                getline(cin,aim);
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->name==aim)
                    {
                    flag=1;
                    cout<<"��ţ�"<<p->No<<endl;
                    cout<<"���ƣ�"<<p->name<<endl;
                    cout<<"���ۣ�"<<p->price<<endl;
                    cout<<"���������"<<p->innumber<<endl;
                    cout<<"���������"<<p->stillnumber<<endl;
                    cout<<"����������"<<p->outnumber<<endl;
                    cout<<"�����ˣ�"<<p->protector<<endl;
                    cout<<"����ʱ�䣺"<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"����ʱ�䣺"<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"��ע��"<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"�޸����Ʋ��ϣ�����������Ѱ�ҷ�ʽ"<<endl;
            }
            if(x==3)
            {
                int flag=0;
                int aim;
                cout<<"������Ŀ�굥��"<<endl;
                cin>>aim;//�������Ŀ�굥��
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->price==aim)
                    {
                    flag=1;
                    cout<<"��ţ�"<<p->No<<endl;
                    cout<<"���ƣ�"<<p->name<<endl;
                    cout<<"���ۣ�"<<p->price<<endl;
                    cout<<"���������"<<p->innumber<<endl;
                    cout<<"���������"<<p->stillnumber<<endl;
                    cout<<"����������"<<p->outnumber<<endl;
                    cout<<"�����ˣ�"<<p->protector<<endl;
                    cout<<"����ʱ�䣺"<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"����ʱ�䣺"<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"��ע��"<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"�޸õ��۲��ϣ�����������Ѱ�ҷ�ʽ"<<endl;
            }
            if(x==4)
            {
                int flag=0;
                int aim;
                cout<<"������Ŀ���������"<<endl;
                cin>>aim;//�������Ŀ���������
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->innumber==aim)
                    {
                    flag=1;
                    cout<<"��ţ�"<<p->No<<endl;
                    cout<<"���ƣ�"<<p->name<<endl;
                    cout<<"���ۣ�"<<p->price<<endl;
                    cout<<"���������"<<p->innumber<<endl;
                    cout<<"���������"<<p->stillnumber<<endl;
                    cout<<"����������"<<p->outnumber<<endl;
                    cout<<"�����ˣ�"<<p->protector<<endl;
                    cout<<"����ʱ�䣺"<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"����ʱ�䣺"<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"��ע��"<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"�޸�����������ϣ�����������Ѱ�ҷ�ʽ"<<endl;
            }
            if(x==5)
            {
                int flag=0;
                int aim;
                cout<<"������Ŀ��������"<<endl;
                cin>>aim;//�������Ŀ��������
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->stillnumber==aim)
                    {
                    flag=1;
                    cout<<"��ţ�"<<p->No<<endl;
                    cout<<"���ƣ�"<<p->name<<endl;
                    cout<<"���ۣ�"<<p->price<<endl;
                    cout<<"���������"<<p->innumber<<endl;
                    cout<<"���������"<<p->stillnumber<<endl;
                    cout<<"����������"<<p->outnumber<<endl;
                    cout<<"�����ˣ�"<<p->protector<<endl;
                    cout<<"����ʱ�䣺"<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"����ʱ�䣺"<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"��ע��"<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"�޸ÿ���������ϣ�����������Ѱ�ҷ�ʽ"<<endl;
            }
            if(x==6)
            {
                int flag=0;
                int aim;
                cout<<"������Ŀ���������"<<endl;
                cin>>aim;//�������Ŀ���������
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->outnumber==aim)
                    {
                    flag=1;
                    cout<<"��ţ�"<<p->No<<endl;
                    cout<<"���ƣ�"<<p->name<<endl;
                    cout<<"���ۣ�"<<p->price<<endl;
                    cout<<"���������"<<p->innumber<<endl;
                    cout<<"���������"<<p->stillnumber<<endl;
                    cout<<"����������"<<p->outnumber<<endl;
                    cout<<"�����ˣ�"<<p->protector<<endl;
                    cout<<"����ʱ�䣺"<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"����ʱ�䣺"<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"��ע��"<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"�޸ó����������ϣ�����������Ѱ�ҷ�ʽ"<<endl;
            }
            if(x==7)
            {
                int flag=0;
                string aim;//�������Ŀ�걣����
                cout<<"������Ŀ�걣����"<<endl;
                getline(cin,aim);
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->protector==aim)
                    {
                    flag=1;
                    cout<<"��ţ�"<<p->No<<endl;
                    cout<<"���ƣ�"<<p->name<<endl;
                    cout<<"���ۣ�"<<p->price<<endl;
                    cout<<"���������"<<p->innumber<<endl;
                    cout<<"���������"<<p->stillnumber<<endl;
                    cout<<"����������"<<p->outnumber<<endl;
                    cout<<"�����ˣ�"<<p->protector<<endl;
                    cout<<"����ʱ�䣺"<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"����ʱ�䣺"<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"��ע��"<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"�޸ñ����˲��ϣ�����������Ѱ�ҷ�ʽ"<<endl;
            }
            if(x==8)
            {
                int flag=0;
                int aim[3];
                cout<<"������Ŀ�����ʱ��"<<endl;
                cin>>aim[0]>>aim[1]>>aim[2];//�������Ŀ�����ʱ��
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->indate[0]==aim[0]&&p->indate[1]==aim[1]&&p->indate[2]==aim[2])
                    {
                    flag=1;
                    cout<<"��ţ�"<<p->No<<endl;
                    cout<<"���ƣ�"<<p->name<<endl;
                    cout<<"���ۣ�"<<p->price<<endl;
                    cout<<"���������"<<p->innumber<<endl;
                    cout<<"���������"<<p->stillnumber<<endl;
                    cout<<"����������"<<p->outnumber<<endl;
                    cout<<"�����ˣ�"<<p->protector<<endl;
                    cout<<"����ʱ�䣺"<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"����ʱ�䣺"<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"��ע��"<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"�޸����ʱ����ϣ�����������Ѱ�ҷ�ʽ"<<endl;
            }
            if(x==9)
            {
                int flag=0;
                int aim[3];
                cout<<"������Ŀ�����ʱ��"<<endl;
                cin>>aim[0]>>aim[1]>>aim[2];//�������Ŀ�����ʱ��
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->outdate[0]==aim[0]&&p->outdate[1]==aim[1]&&p->outdate[2]==aim[2])
                    {
                    flag=1;
                    cout<<"��ţ�"<<p->No<<endl;
                    cout<<"���ƣ�"<<p->name<<endl;
                    cout<<"���ۣ�"<<p->price<<endl;
                    cout<<"���������"<<p->innumber<<endl;
                    cout<<"���������"<<p->stillnumber<<endl;
                    cout<<"����������"<<p->outnumber<<endl;
                    cout<<"�����ˣ�"<<p->protector<<endl;
                    cout<<"����ʱ�䣺"<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"����ʱ�䣺"<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"��ע��"<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"�޸ÿ�ʱ����ϣ�����������Ѱ�ҷ�ʽ"<<endl;
            }
            if(x==10)
            {
                int flag=0;
                string aim;//�������Ŀ������
                cout<<"������Ŀ�걸ע"<<endl;
                getline(cin,aim);
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->remarks==aim)
                    {
                    flag=1;
                    cout<<"��ţ�"<<p->No<<endl;
                    cout<<"���ƣ�"<<p->name<<endl;
                    cout<<"���ۣ�"<<p->price<<endl;
                    cout<<"���������"<<p->innumber<<endl;
                    cout<<"���������"<<p->stillnumber<<endl;
                    cout<<"����������"<<p->outnumber<<endl;
                    cout<<"�����ˣ�"<<p->protector<<endl;
                    cout<<"����ʱ�䣺"<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"����ʱ�䣺"<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"��ע��"<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"�޸ñ�ע���ϣ�����������Ѱ�ҷ�ʽ"<<endl;
        }
}
}
void Add()//��Ӻ���
{
    Material *tail;
    tail=findtail(head);
    cout<<"*  �ɹ�ִ����Ӻ���  *"<<endl;
    while(1)
    {
        cout<<"��������Ҫ��ӵı��"<<endl;
        Material *p=new Material;
        cin>>p->No;
        if(p->No!=-1)
        {
            getchar();
            cout<<"������������ƣ�";
            getline(cin,p->name);
            cout<<"��������ϵ��ۣ�";
            cin>>p->price;
            cout<<"������������������";
            cin>>p->innumber;
            cout<<"��������Ͽ��������";
            cin>>p->stillnumber;
            cout<<"��������ϳ���������";
            cin>>p->outnumber;
            getchar();
            cout<<"��������ϱ����ˣ�";
            getline(cin,p->protector);
            cout<<"��������Ͻ���ʱ�䣨�� �� �գ���";
            cin>>p->indate[0]>>p->indate[1]>>p->indate[2];
            cout<<"��������ϳ���ʱ�䣨�� �� �գ���";
            cin>>p->outdate[0]>>p->outdate[1]>>p->outdate[2];
            getchar();
            cout<<"��������ϱ�ע��";
            getline(cin,p->remarks);
            cout<<"��������������ɣ��������������ֻ��������Ϊ-1����"<<endl;
            tail->next=p;
        }
        else
        {
            tail->next=NULL;
            return;
        }
        tail=p;
        tail->next=NULL;
    }
}
int main()//������
{
    cout<<"�Ƿ��Զ�����ϴν���ʱ��������ļ�"<<endl;
    cout<<"��������1����֮����2"<<endl;
    cout<<"���ǵ�һ��ʹ�øó������Ծ�����2"<<endl;
    int x;
    cin>>x;
    if(x==1)
        wendangduru();
    char i;
    while(1)  //   ѭ��ִ�й��ܲ˵�
    {
        printf("* * * * * *Menue* * * * * *\n");
        printf("*       a. ����      *\n");//���뺯��
        printf("*       b. ��ʾ    *\n");//��ʾ����
        printf("*       c. �޸�    *\n");//�޸ĺ���
        printf("*       d. ����      *\n");//���Һ���
        printf("*       e. ���      *\n");//��Ӻ���
        printf("*       f. �˳�      *\n");
        printf("*    Please select a to f    *\n");
        printf("* * * * * * * * * * * * * *\n");
        cin>>i;
        if(i=='f')
            break;
        else switch(i)
        {
        case 'a': Input(x);getchar();break;
        case 'b': Display();getchar();break;
        case 'c': Modify();break;
        case 'd': Find();getchar();break;
        case 'e': Add(); getchar();break;
        }
    }
    ofstream fout("���Ϲ���ϵͳ.txt");
    Material *p=new Material;
    int first= 1;
    for(p=head;p!=NULL;p=p->next)
    {
            if (first) first = 0;
            else fout<<endl;
        fout<<p->No<<' '<<p->name<<' '<<p->price<<' '<<p->innumber<<' '<<p->stillnumber<<' '<<p->outnumber<<' '<<p->protector<<' '<<p->indate[0]<<' '<<p->indate[1]<<' '<<p->indate[2]<<' '<<p->outdate[0]<<' '<<p->outdate[1]<<' '<<p->outdate[2]<<' '<<p->remarks;
    }
    fout.close();
    return 0;
}
