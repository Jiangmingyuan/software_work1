#include <bits/stdc++.h>
using namespace std;
struct Material//结构体建立
{
    int No;//编号
    string name;//名称
    int price;//单价
    int innumber;//入库数量
    int stillnumber;//库存数量
    int outnumber;//出库数量
    string protector;//保管人
    int indate[3];//进货时间
    int outdate[3];//出货时间
    string remarks;//备注
    Material *next;
};
Material *head=NULL;//全局变量 头指针
Material *findtail(Material *head)//寻找尾指针
{
    Material *Tail= NULL;
    for (Tail= head; Tail->next!= NULL; Tail= Tail->next) ;
    return Tail;
}
void wendangduru()//文件读入函数
{
    Material *p=NULL;
    Material *pre=NULL;
    head=NULL;
    Material *tail=NULL;
    ifstream rfile;
    string filename="材料管理系统.txt";
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
void Input(int x)//输入函数
{
    Material *tail;
    if(x==1)
    {
        tail=findtail(head);
    }
    else
        tail=NULL;
    cout<<"*  成功执行输入函数  *"<<endl;
    Material *p=NULL;
    Material *pre=NULL;
    while(1)
    {
        p=new Material;
        cout<<"请输入材料编号：";
        cin>>p->No;
        if(p->No==-1)
        {
            pre->next=NULL;
            cout<<"*  输入函数函数结束  *"<<endl;
            return;
        }
        else
        {
            getchar();
            cout<<"请输入材料名称：";
            getline(cin,p->name);
            cout<<"请输入材料单价：";
            cin>>p->price;
            cout<<"请输入材料入库数量：";
            cin>>p->innumber;
            cout<<"请输入材料库存数量：";
            cin>>p->stillnumber;
            cout<<"请输入材料出库数量：";
            cin>>p->outnumber;
            getchar();
            cout<<"请输入材料保管人：";
            getline(cin,p->protector);
            cout<<"请输入材料进货时间（年 月 日）：";
            cin>>p->indate[0]>>p->indate[1]>>p->indate[2];
            cout<<"请输入材料出货时间（年 月 日）：";
            cin>>p->outdate[0]>>p->outdate[1]>>p->outdate[2];
            getchar();
            cout<<"请输入材料备注：";
            getline(cin,p->remarks);
            cout<<"单组数据输入完成，若结束输出，则只需输入编号为-1即可"<<endl;
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
void Display()//显示函数
{
    cout<<"*  成功执行显示函数  *"<<endl;
    Material *p=new Material;
    for(p=head;p!=NULL;p=p->next)
    {
        cout<<"编号："<<p->No<<endl;
        cout<<"名称："<<p->name<<endl;
        cout<<"单价："<<p->price<<endl;
        cout<<"入库数量："<<p->innumber<<endl;
        cout<<"库存数量："<<p->stillnumber<<endl;
        cout<<"出库数量："<<p->outnumber<<endl;
        cout<<"保管人："<<p->protector<<endl;
        cout<<"进货时间："<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
        cout<<"出货时间："<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
        cout<<"备注："<<p->remarks<<endl;
        cout<<endl;
    }
    return;
}
void Modify()//修改函数
{
    Material *tail;
    tail=findtail(head);
    cout<<"*  成功执行修改函数  *"<<endl;
    char x;
    string y;
    int aim;
    cout<<"请输入需要修改的序号"<<endl;
    cin>>aim;//输入需要修改的编号
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
        {cout<<"无此编号请重新输入"<<endl;return;}
    while(1)
    {
       // clrscr(); // 清屏幕
        printf("* * * * * *选择此编号下需要修改的内容* * * * * *\n");
        printf("*       a. 编号     *\n");
        printf("*       b. 名称    *\n");
        printf("*       c. 单价    *\n");
        printf("*       d. 入库数量      *\n");
        printf("*       e. 库存数量      *\n");
        printf("*       f. 出库数量      *\n");
        printf("*       g. 保管人      *\n");
        printf("*       h. 进货时间      *\n");
        printf("*       i. 出货时间      *\n");
        printf("*       j. 备注      *\n");
        printf("*       k. 删除该项      *\n");
        printf("*       l. 退出      *\n");
        printf("*   请输入a~l    *\n");
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
                cout<<"请输入需要修改后的数据"<<endl;
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
void Find()//查找函数
{
    cout<<"*  成功执行查找函数  *"<<endl;
    char i;
    int x=0;
    int first=1;
    while(1)
    {
        if(first==1)
            getchar();//clrscr(); // 清屏幕
        first=0;
        printf("* * * * * *Menue* * * * * *\n");
        printf("*       a. 已知编号查找      *\n");
        printf("*       b. 已知名称查找    *\n");
        printf("*       c. 已知单价查找    *\n");
        printf("*       d. 已知入库数量查找    *\n");
        printf("*       e. 已知库存数量查找    *\n");
        printf("*       f. 已知出库数量查找    *\n");
        printf("*       g. 已知保管人查找    *\n");
        printf("*       h. 已知进货时间查找    *\n");
        printf("*       i. 已知出货时间查找    *\n");
        printf("*       j. 已知备注查找    *\n");
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
            if(x==1)//已知编号查找
            {
                int flag=0;
                int aim;
                cout<<"请输入目标编号"<<endl;
                cin>>aim;//输入查找目标编号
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->No==aim)
                    {
                        flag=1;
                        cout<<"编号："<<p->No<<endl;
                        cout<<"名称："<<p->name<<endl;
                        cout<<"单价："<<p->price<<endl;
                        cout<<"入库数量："<<p->innumber<<endl;
                        cout<<"库存数量："<<p->stillnumber<<endl;
                        cout<<"出库数量："<<p->outnumber<<endl;
                        cout<<"保管人："<<p->protector<<endl;
                        cout<<"进货时间："<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                        cout<<"出货时间："<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                        cout<<"备注："<<p->remarks<<endl;
                    }
                }
                if(flag==0)
                        cout<<"无该序号材料，请重新输入寻找方式"<<endl;
            }
            if(x==2)
            {
                int flag=0;
                string aim;//输入查找目标名称
                cout<<"请输入目标名称"<<endl;
                getline(cin,aim);
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->name==aim)
                    {
                    flag=1;
                    cout<<"编号："<<p->No<<endl;
                    cout<<"名称："<<p->name<<endl;
                    cout<<"单价："<<p->price<<endl;
                    cout<<"入库数量："<<p->innumber<<endl;
                    cout<<"库存数量："<<p->stillnumber<<endl;
                    cout<<"出库数量："<<p->outnumber<<endl;
                    cout<<"保管人："<<p->protector<<endl;
                    cout<<"进货时间："<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"出货时间："<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"备注："<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"无该名称材料，请重新输入寻找方式"<<endl;
            }
            if(x==3)
            {
                int flag=0;
                int aim;
                cout<<"请输入目标单价"<<endl;
                cin>>aim;//输入查找目标单价
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->price==aim)
                    {
                    flag=1;
                    cout<<"编号："<<p->No<<endl;
                    cout<<"名称："<<p->name<<endl;
                    cout<<"单价："<<p->price<<endl;
                    cout<<"入库数量："<<p->innumber<<endl;
                    cout<<"库存数量："<<p->stillnumber<<endl;
                    cout<<"出库数量："<<p->outnumber<<endl;
                    cout<<"保管人："<<p->protector<<endl;
                    cout<<"进货时间："<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"出货时间："<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"备注："<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"无该单价材料，请重新输入寻找方式"<<endl;
            }
            if(x==4)
            {
                int flag=0;
                int aim;
                cout<<"请输入目标入库数量"<<endl;
                cin>>aim;//输入查找目标入库数量
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->innumber==aim)
                    {
                    flag=1;
                    cout<<"编号："<<p->No<<endl;
                    cout<<"名称："<<p->name<<endl;
                    cout<<"单价："<<p->price<<endl;
                    cout<<"入库数量："<<p->innumber<<endl;
                    cout<<"库存数量："<<p->stillnumber<<endl;
                    cout<<"出库数量："<<p->outnumber<<endl;
                    cout<<"保管人："<<p->protector<<endl;
                    cout<<"进货时间："<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"出货时间："<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"备注："<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"无该入库数量材料，请重新输入寻找方式"<<endl;
            }
            if(x==5)
            {
                int flag=0;
                int aim;
                cout<<"请输入目标库存数量"<<endl;
                cin>>aim;//输入查找目标库存数量
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->stillnumber==aim)
                    {
                    flag=1;
                    cout<<"编号："<<p->No<<endl;
                    cout<<"名称："<<p->name<<endl;
                    cout<<"单价："<<p->price<<endl;
                    cout<<"入库数量："<<p->innumber<<endl;
                    cout<<"库存数量："<<p->stillnumber<<endl;
                    cout<<"出库数量："<<p->outnumber<<endl;
                    cout<<"保管人："<<p->protector<<endl;
                    cout<<"进货时间："<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"出货时间："<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"备注："<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"无该库存数量材料，请重新输入寻找方式"<<endl;
            }
            if(x==6)
            {
                int flag=0;
                int aim;
                cout<<"请输入目标出库数量"<<endl;
                cin>>aim;//输入查找目标出库数量
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->outnumber==aim)
                    {
                    flag=1;
                    cout<<"编号："<<p->No<<endl;
                    cout<<"名称："<<p->name<<endl;
                    cout<<"单价："<<p->price<<endl;
                    cout<<"入库数量："<<p->innumber<<endl;
                    cout<<"库存数量："<<p->stillnumber<<endl;
                    cout<<"出库数量："<<p->outnumber<<endl;
                    cout<<"保管人："<<p->protector<<endl;
                    cout<<"进货时间："<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"出货时间："<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"备注："<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"无该出库数量材料，请重新输入寻找方式"<<endl;
            }
            if(x==7)
            {
                int flag=0;
                string aim;//输入查找目标保管人
                cout<<"请输入目标保管人"<<endl;
                getline(cin,aim);
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->protector==aim)
                    {
                    flag=1;
                    cout<<"编号："<<p->No<<endl;
                    cout<<"名称："<<p->name<<endl;
                    cout<<"单价："<<p->price<<endl;
                    cout<<"入库数量："<<p->innumber<<endl;
                    cout<<"库存数量："<<p->stillnumber<<endl;
                    cout<<"出库数量："<<p->outnumber<<endl;
                    cout<<"保管人："<<p->protector<<endl;
                    cout<<"进货时间："<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"出货时间："<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"备注："<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"无该保管人材料，请重新输入寻找方式"<<endl;
            }
            if(x==8)
            {
                int flag=0;
                int aim[3];
                cout<<"请输入目标入库时间"<<endl;
                cin>>aim[0]>>aim[1]>>aim[2];//输入查找目标入库时间
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->indate[0]==aim[0]&&p->indate[1]==aim[1]&&p->indate[2]==aim[2])
                    {
                    flag=1;
                    cout<<"编号："<<p->No<<endl;
                    cout<<"名称："<<p->name<<endl;
                    cout<<"单价："<<p->price<<endl;
                    cout<<"入库数量："<<p->innumber<<endl;
                    cout<<"库存数量："<<p->stillnumber<<endl;
                    cout<<"出库数量："<<p->outnumber<<endl;
                    cout<<"保管人："<<p->protector<<endl;
                    cout<<"进货时间："<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"出货时间："<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"备注："<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"无该入库时间材料，请重新输入寻找方式"<<endl;
            }
            if(x==9)
            {
                int flag=0;
                int aim[3];
                cout<<"请输入目标出库时间"<<endl;
                cin>>aim[0]>>aim[1]>>aim[2];//输入查找目标出库时间
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->outdate[0]==aim[0]&&p->outdate[1]==aim[1]&&p->outdate[2]==aim[2])
                    {
                    flag=1;
                    cout<<"编号："<<p->No<<endl;
                    cout<<"名称："<<p->name<<endl;
                    cout<<"单价："<<p->price<<endl;
                    cout<<"入库数量："<<p->innumber<<endl;
                    cout<<"库存数量："<<p->stillnumber<<endl;
                    cout<<"出库数量："<<p->outnumber<<endl;
                    cout<<"保管人："<<p->protector<<endl;
                    cout<<"进货时间："<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"出货时间："<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"备注："<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"无该库时间材料，请重新输入寻找方式"<<endl;
            }
            if(x==10)
            {
                int flag=0;
                string aim;//输入查找目标名称
                cout<<"请输入目标备注"<<endl;
                getline(cin,aim);
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->remarks==aim)
                    {
                    flag=1;
                    cout<<"编号："<<p->No<<endl;
                    cout<<"名称："<<p->name<<endl;
                    cout<<"单价："<<p->price<<endl;
                    cout<<"入库数量："<<p->innumber<<endl;
                    cout<<"库存数量："<<p->stillnumber<<endl;
                    cout<<"出库数量："<<p->outnumber<<endl;
                    cout<<"保管人："<<p->protector<<endl;
                    cout<<"进货时间："<<p->indate[0]<<'.'<<p->indate[1]<<'.'<<p->indate[2]<<endl;
                    cout<<"出货时间："<<p->outdate[0]<<'.'<<p->outdate[1]<<'.'<<p->outdate[2]<<endl;
                    cout<<"备注："<<p->remarks<<endl;
                }
                }
                if(flag==0)
                    cout<<"无该备注材料，请重新输入寻找方式"<<endl;
        }
}
}
void Add()//添加函数
{
    Material *tail;
    tail=findtail(head);
    cout<<"*  成功执行添加函数  *"<<endl;
    while(1)
    {
        cout<<"请输入需要添加的编号"<<endl;
        Material *p=new Material;
        cin>>p->No;
        if(p->No!=-1)
        {
            getchar();
            cout<<"请输入材料名称：";
            getline(cin,p->name);
            cout<<"请输入材料单价：";
            cin>>p->price;
            cout<<"请输入材料入库数量：";
            cin>>p->innumber;
            cout<<"请输入材料库存数量：";
            cin>>p->stillnumber;
            cout<<"请输入材料出库数量：";
            cin>>p->outnumber;
            getchar();
            cout<<"请输入材料保管人：";
            getline(cin,p->protector);
            cout<<"请输入材料进货时间（年 月 日）：";
            cin>>p->indate[0]>>p->indate[1]>>p->indate[2];
            cout<<"请输入材料出货时间（年 月 日）：";
            cin>>p->outdate[0]>>p->outdate[1]>>p->outdate[2];
            getchar();
            cout<<"请输入材料备注：";
            getline(cin,p->remarks);
            cout<<"单组数据输入完成，若结束输出，则只需输出编号为-1即可"<<endl;
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
int main()//主函数
{
    cout<<"是否自动添加上次结束时所输入的文件"<<endl;
    cout<<"是请输入1，反之输入2"<<endl;
    cout<<"若是第一次使用该程序，请自觉输入2"<<endl;
    int x;
    cin>>x;
    if(x==1)
        wendangduru();
    char i;
    while(1)  //   循环执行功能菜单
    {
        printf("* * * * * *Menue* * * * * *\n");
        printf("*       a. 输入      *\n");//输入函数
        printf("*       b. 显示    *\n");//显示函数
        printf("*       c. 修改    *\n");//修改函数
        printf("*       d. 查找      *\n");//查找函数
        printf("*       e. 添加      *\n");//添加函数
        printf("*       f. 退出      *\n");
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
    ofstream fout("材料管理系统.txt");
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
