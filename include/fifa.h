#ifndef _FIFA_H
#define _FIFA_H

//headfile that game need

#include "iostream"

#include "cstdio"

#include "cstring"

#include "algorithm"

#include "iomanip"

#include "ctime"

#include "calc.h"

#include "fstream"

using namespace std;

//posi:
/*
GK:门将
SW:清道夫
RWB:右边后卫
RB:右后卫
RCB:右中后卫
CB:中后卫
LCB:左中后卫
LB:左后卫
LWB:左边后卫
RDM:右后腰
CDM:后腰
LDM:左后腰
RWM:右边中场
RM:右中场
RCM:右中中场
CM:中中场
LCM:左中中场
LM:左中场
LWM:左边中场
RCAM:右前腰
CAM:前腰
LCAM:左前腰
RF:右前锋
CF:中前锋
LF:左前锋
RW:右边锋
RS:右中峰
ST:中锋
SS:影峰
LS:左中峰
LW:左边锋
*/

struct player{//普通球员
    string posi;//位置
    string name;
    int pac;//速度
    int dri;//控球
    int sho;//射门
    int def;//防守
    int pas;//过人
    int phy;//身体
};

struct GK{//门将
    string posi;//位置
    string name;
    int div;//扑救
    int ref;//反应
    int han;//控球
    int spd;//速度
    int kic;//踢球
    int pos;//站位
};

struct Team{//队伍
    string team_name;
    int kit_num[12];//球衣号码
    string name[12];//球员名字
    int num_A;
    int num_M;
    int num_D;
    int Attack;//攻击数值
    int MidField;//中场数值
    int Defence;//防守数值
    int GK;
    int OverAll;//总数值
    Team(){
        team_name="Null";
        Attack=0;
        MidField=0;
        Defence=0;
        num_A=0;
        num_M=0;
        num_D=0;
        GK=0;
        OverAll=0;
    }
};

struct Club{//俱乐部排行榜
    string name;
    int PI;
    int GD;
    int Pts;
    Club(){
        name="Null";
        PI=0;
        GD=0;
        Pts=0;
    }
};

struct person{//个人排行
    string name;
    int value;
    person(){
        name="Null";
        value=0;
    }
};

struct goal{
    bool goal_side;//主队为1,客队为0
    string name;//得分者名字
    int kit_num;//得分者号码
    int goal_time;//进球时间
    string assister;
    int num_ass;
    goal(){
        goal_side=1;
        name="Null";
        kit_num=-1;
        goal_time=-1;
        assister="Null";
        num_ass=-1;
    }
};

struct result{
    string home_name;
    string away_name;
    int home_goal;//主队进球数
    int away_goal;//客队进球数
    int home_shoot;//主队射门次数
    int away_shoot;//客队射门次数
    int home_shoot_on_target;//主队射正次数
    int away_shoot_on_target;//客队射正次数
    int home_save;//主队扑救次数
    int away_save;//客队扑救次数
    int home_holdball;//主队控球率(保留整数)
    int away_holdball;//客队控球率(保留整数)
    goal goal_list[101];
    result(){
        home_goal=0;
        away_goal=0;
        home_shoot=0;
        away_shoot=0;
        home_shoot_on_target=0;
        away_shoot_on_target=0;
        home_save=0;
        away_save=0;
        home_holdball=0;
        away_holdball=0;
    }
};

bool cmp1(struct goal x,struct goal y);

bool cmp2(struct Club x,struct Club y);

bool cmp3(struct person x,struct person y);

int FindType(string name);

GK FindGK(string name);

player FindPlayer(string name);

Team FindTeam(string name);

result match(string Home,string Away);

void detail(result game);

int shooter(Team t);

int assister(Team t,int shoot);

void Archive(result x);

void NewSeason();

result GetResult(int x);//获取比赛编号为x的比赛数据

void PushResult(result x);//将比赛数据存档

void ShowClubList();

void ShowShooterList();

void ShowAssisterList();

void ShowGoalkeeperList();

void ShowTeam();

bool cmp1(struct goal x,struct goal y){
    if(x.goal_side==y.goal_side)
    return x.goal_time<y.goal_time;
    return x.goal_side>y.goal_side;
}

bool cmp2(struct Club x,struct Club y){
    if(x.Pts==y.Pts){
        if(x.GD==y.GD)
        return x.PI<y.PI;
        return x.GD>y.GD;
    }
    return x.Pts>y.Pts;
}

bool cmp3(struct person x,struct person y){
    return x.value>y.value;
}

int FindType(string name){//GK0 Defence1 MidField2 Attack3 Error4 or 5
    string posi,now,dat1,dat2,dat3,dat4,dat5,dat6;
    ifstream in("..\\data\\playerlist.sav");
    while(in>>posi){
        in>>now;
        in>>dat1;
        in>>dat2;
        in>>dat3;
        in>>dat4;
        in>>dat5;
        in>>dat6;
        if(now==name){
                if(posi=="GK")return 0;//GK
                if(posi=="SW")return 1;
                if(posi=="RWB")return 1;
                if(posi=="RB")return 1;
                if(posi=="RCB")return 1;
                if(posi=="CB")return 1;
                if(posi=="LCB")return 1;
                if(posi=="LB")return 1;
                if(posi=="LWB")return 1;//Defence
                if(posi=="RDM")return 2;
                if(posi=="CDM")return 2;
                if(posi=="LDM")return 2;
                if(posi=="RWM")return 2;
                if(posi=="RM")return 2;
                if(posi=="RCM")return 2;
                if(posi=="CM")return 2;
                if(posi=="LCM")return 2;
                if(posi=="LM")return 2;
                if(posi=="LWM")return 2;
                if(posi=="RCAM")return 2;
                if(posi=="CAM")return 2;
                if(posi=="LCAM")return 2;//MidField
                if(posi=="RF")return 3;
                if(posi=="CF")return 3;
                if(posi=="LF")return 3;
                if(posi=="RW")return 3;
                if(posi=="RS")return 3;
                if(posi=="ST")return 3;
                if(posi=="SS")return 3;
                if(posi=="LS")return 3;
                if(posi=="LW")return 3;//Attack
                else return 5;//Error
        }
    }
    return 4;
}

GK FindGK(string name){
    GK res;
    //puts("start to find GK");
    //system("pause");
    ifstream in("..\\data\\playerlist.sav");
    while(in>>res.posi){
        in>>res.name;
        in>>res.div;
        in>>res.ref;
        in>>res.han;
        in>>res.spd;
        in>>res.kic;
        in>>res.pos;
        if(res.name==name){
            //puts("right name OK\n");
            //system("pause");
            return res;
        }
    }
    res.name="NULL";
    return res;
}

player FindPlayer(string name){
    player res;
    ifstream in("..\\data\\playerlist.sav");
    while(in>>res.posi){
        in>>res.name;
        in>>res.pac;
        in>>res.dri;
        in>>res.sho;
        in>>res.def;
        in>>res.pas;
        in>>res.phy;
        if(res.name==name)
        return res;
    }
    res.name="NULL";
    return res;
}

void Calculate(struct Team &t){//计算球队数值
    int now=1;//当前球员编号(1~11)
    int num_D=0;//Defence
    int num_M=0;//MidField
    int num_A=0;//Attack;
    player tmp;
    for(register int i=1;i<=11;i++){
        int Type=FindType(t.name[now]);
        if(Type==3){//Attack
            t.num_A++;
            tmp=FindPlayer(t.name[now]);
            t.Attack+=tmp.sho*5+tmp.phy+tmp.pas*3;
            t.MidField+=tmp.dri*3+tmp.phy*2;
            t.Defence+=tmp.def*3+tmp.phy*2;
            //printf("No. %d player\n",now);
            //system("pause");
            now++;
            //printf("A Attack:%d\n",t.Attack);
        }
        else if(Type==2){//MidField
            t.num_M++;
            tmp=FindPlayer(t.name[now]);
            t.Attack+=tmp.sho*2+tmp.pas*1+tmp.pac*2;
            t.MidField+=tmp.dri*3+tmp.pac+tmp.pas;
            t.Defence+=tmp.def*5;
            //printf("No. %d player\n",now);
            //system("pause");
            now++;
            //printf("M Attack:%d\n",t.Attack);
        }
        else if(Type==1){//Defence
            t.num_D++;
            tmp=FindPlayer(t.name[now]);
            t.Attack+=tmp.sho;
            t.MidField+=tmp.pac*3+tmp.pas*2;
            t.Defence+=tmp.def*3+tmp.phy*2;
            //printf("No. %d player\n",now);
            //system("pause");
            now++;
            //printf("D Attack:%d\n",t.Attack);
        }
        else{//GK
            GK GoalKeeper=FindGK(t.name[now]);
            //puts("calculated GK");
            //system("pause");
            t.GK=GoalKeeper.div+GoalKeeper.ref+GoalKeeper.pos;
        }
    }
    /*while(FindType(t.name[now])==3){
        t.num_A++;
        tmp=FindPlayer(t.name[now]);
        t.Attack+=tmp.sho*5+tmp.phy+tmp.pas*3;
        t.MidField+=tmp.dri*3+tmp.phy*2;
        t.Defence+=tmp.def*3+tmp.phy*2;
        //printf("No. %d player\n",now);
        //system("pause");
        now++;
        //printf("A Attack:%d\n",t.Attack);
    }*/
    /*while(FindType(t.name[now])==2){
        t.num_M++;
        tmp=FindPlayer(t.name[now]);
        t.Attack+=tmp.sho*2+tmp.pas*1+tmp.pac*2;
        t.MidField+=tmp.dri*3+tmp.pac+tmp.pas;
        t.Defence+=tmp.def*5;
        //printf("No. %d player\n",now);
        //system("pause");
        now++;
        //printf("M Attack:%d\n",t.Attack);
    }*/
    /*while(FindType(t.name[now])==1){
        t.num_D++;
        tmp=FindPlayer(t.name[now]);
        t.Attack+=tmp.sho;
        t.MidField+=tmp.pac*3+tmp.pas*2;
        t.Defence+=tmp.def*3+tmp.phy*2;
        //printf("No. %d player\n",now);
        //system("pause");
        now++;
        //printf("D Attack:%d\n",t.Attack);
    }*/
    //printf("t.num_A=%d\n",t.num_A);
    //printf("ready again\n");
    //system("pause");
    if(t.num_A)
    t.Attack=(t.Attack/t.num_A)*(1+(t.num_A)/10);
    //puts("calculated Attacker");
    //system("pause");
    if(t.num_M)
    t.MidField=(t.MidField/t.num_M)*(1+(t.num_M)/10);
    //puts("calculated MidField");
    //system("pause");
    if(t.num_D)
    t.Defence=(t.Defence/t.num_D)*(1+(t.num_D)/10);
    t.OverAll=t.Attack+t.MidField+t.Defence;
    //puts("calculated Defence");
    //system("pause");
    //GK GoalKeeper=FindGK(t.name[now]);
    //puts("calculated GK");
    //system("pause");
    //t.GK=GoalKeeper.div+GoalKeeper.ref+GoalKeeper.pos;
    //t.OverAll=t.Attack+t.MidField+t.Defence;
    //printf("calculated in function\n");
    //system("pause");
    return;
}

Team FindTeam(string name){
    //puts("start to find team");
    //system("pause");
    Team res;
    ifstream in("..\\data\\teamopition.sav");
    while(in>>res.team_name){
        for(register int i=1;i<=11;i++)
        in>>res.kit_num[i]>>res.name[i];
        if(res.team_name==name){
            //printf("ready to calculate\n");
            //system("pause");
            Calculate(res);
            //printf("calculated\n");
            //system("pause");
            return res;
        }
    }
    res.team_name="Null";
    return res;
}

void detail(result game){
    sort(game.goal_list+1,game.goal_list+game.home_goal+game.away_goal+1,cmp1);
    int num_goal=1;
    cout<<game.home_name<<" vs "<<game.away_name<<endl;
    printf("Total score: %d - %d\n",game.home_goal,game.away_goal);
    printf("Possession: %d - %d\n",game.home_holdball,game.away_holdball);
    printf("Shots(Shots on goal): %d ( %d ) - %d ( %d )\n",game.home_shoot,game.home_shoot_on_target,game.away_shoot,game.away_shoot_on_target);
    printf("Saves: %d - %d\n",game.home_save,game.away_save);
    printf("Home team goals:\n");
    while(game.goal_list[num_goal].goal_side&&num_goal<=game.home_goal){
        cout<<"No. "<<game.goal_list[num_goal].kit_num<<":"<<game.goal_list[num_goal].name<<"   ["<<game.goal_list[num_goal].goal_time<<"']   ";
        if(game.goal_list[num_goal].num_ass!=-1)
        cout<<"   Assister: No."<<game.goal_list[num_goal].num_ass<<":"<<game.goal_list[num_goal].assister<<endl;
        else
        puts("");
        num_goal++;
    }
    printf("Away team goals:\n");
    while(num_goal<=game.home_goal+game.away_goal){
        cout<<"No. "<<game.goal_list[num_goal].kit_num<<":"<<game.goal_list[num_goal].name<<"   ["<<game.goal_list[num_goal].goal_time<<"']";
        if(game.goal_list[num_goal].num_ass!=-1)
        cout<<"   Assister: No."<<game.goal_list[num_goal].num_ass<<":"<<game.goal_list[num_goal].assister<<endl;
        else
        puts("");
        num_goal++;
    }
}

int shooter(Team t){
    int key=rand()%100+1;
    int res;
    if(key<=15)
    res=t.num_A+t.num_M+(rand()%t.num_D)+1;
    else if(key<=50)
    res=t.num_A+(rand()%t.num_M)+1;
    else
    res=rand()%t.num_A+1;
    return res;
}

int assister(Team t,int shoot){
    //puts("start to calculating..");
    //system("pause");
    int key=rand()%100+1;
    int res=0;
    int de_inwhile=0;
    if(key<=10)
    res=-1;
    else if(key<=30){
        do{
            res=t.num_A+t.num_M+(rand()%t.num_D)+1;
        }
        while(res==shoot);
    }
    else if(key<=80){
        do{
            res=t.num_A+(rand()%t.num_M)+1;
        }
        while(res==shoot);  
    }
    else{
       do{
            //printf("res=%d\n,res");
            res=rand()%t.num_A+1;
            de_inwhile++;
            if(de_inwhile==15){
                //puts("de_inwhile");
                do{
                    res=t.num_A+(rand()%t.num_M)+1;
                }
                while(res==shoot); 
            }
        }
        while(res==shoot); 
    }
    //printf("res=%d\n",res);
    //system("pause");
    return res;
}

result match(string Home,string Away){//模拟比赛
    result res;
    //printf("start\n");
    //system("pause");
    res.home_name=Home;
    res.away_name=Away;
    Team home,away;
    home=FindTeam(Home);
    away=FindTeam(Away);
    //puts("Team Found");
    //system("pause");
    int All_Opportunity=rand()%26+25;//25~50次总进攻机会
    //printf("Oppo. A.=%d\n",All_Opportunity);
    int Home_Opportunity;//主队进攻机会
    int Away_Opportunity;//客队进攻机会
    res.home_holdball=100*(double)((double)home.OverAll/(double)(home.OverAll+away.OverAll));
    if(rand()&1)
    res.home_holdball+=rand()%11;
    else
    res.home_holdball-=rand()%11;//上下浮动10%左右控球率
    res.away_holdball=100-res.home_holdball;//求出客队控球率
    Home_Opportunity=All_Opportunity*(double)((double)res.home_holdball/(double)(res.home_holdball+res.away_holdball));
    if((rand()&1||Home_Opportunity<10)&&Home_Opportunity>5)
    Home_Opportunity+=rand()%6;
    else
    Home_Opportunity-=rand()%6;//上下浮动5次左右进攻机会
    Away_Opportunity=All_Opportunity-Home_Opportunity;//求出客队进攻机会
    //printf("Oppo. H.=%d\n",Home_Opportunity);
    //printf("Oppo. A.=%d\n",Away_Opportunity);
    //system("pause");
    while(Home_Opportunity--){//主队每次进攻机会
        //printf("home tring\n");
        if(Rand(rand()%11+20)){//20%~30%的概率起脚
            //puts("try shoot");
            res.home_shoot++;
            int plynum=shooter(home);
            player ply=FindPlayer(home.name[plynum]);
            int cha_dev=100-ply.sho;//射偏的几率
            if(rand()&1)
            cha_dev+=rand()%11;
            else
            cha_dev-=rand()%11;//上下浮动10%的概率
            if(Rand(cha_dev))
            continue;//射偏了
            res.home_shoot_on_target++;
            int chance=70;//70%概率破门
            //puts("shoot on target");
            if(away.GK>ply.sho*3)
            chance-=(away.GK-ply.sho*3);
            if(Rand(chance)){//GOAL!
                //puts("goal");
                res.home_goal++;
                int all_goal=res.home_goal+res.away_goal;
                goal tmp;
                tmp.goal_side=1;
                tmp.goal_time=rand()%90+1;
                tmp.name=home.name[plynum];
                tmp.kit_num=home.kit_num[plynum];
                //puts("mark");
                //puts("mark1");
                int ass=assister(home,plynum);
                //puts("mark2");
                tmp.num_ass=home.kit_num[ass];
                if(ass!=-1)
                tmp.assister=home.name[ass];
                //puts("mark");
                if(ass!=-1){
                    tmp.num_ass=home.kit_num[ass];
                    tmp.assister=home.name[ass];
                }
                else{
                    tmp.num_ass=-1;
                }
                res.goal_list[all_goal]=tmp;
                //puts("deald");
            }
            else{//what a save!
                res.away_save++;
            }
        }
    }
    //printf("all of home oppo\n");
    while(Away_Opportunity--){//客队每次进攻机会
        //printf("away tring\n");
        if(Rand(rand()%11+20)){//20%~30%的概率起脚
            res.away_shoot++;
            int plynum=shooter(away);
            player ply=FindPlayer(away.name[plynum]);
            int cha_dev=100-ply.sho;//射偏的几率
            if(rand()&1)
            cha_dev+=rand()%11;
            else
            cha_dev-=rand()%11;//上下浮动10%的概率
            if(Rand(cha_dev))
            continue;//射偏了
            res.away_shoot_on_target++;
            int chance=70;//70%概率破门
            if(home.GK>ply.sho*3)
            chance-=(home.GK-ply.sho*3);
            if(Rand(chance)){//GOAL!
                res.away_goal++;
                int all_goal=res.away_goal+res.home_goal;
                goal tmp;
                tmp.goal_side=0;
                tmp.goal_time=rand()%90+1;
                tmp.name=away.name[plynum];
                tmp.kit_num=away.kit_num[plynum];
                int ass=assister(away,plynum);
                if(ass!=-1){
                    tmp.num_ass=away.kit_num[ass];
                    tmp.assister=away.name[ass];
                }
                else{
                    tmp.num_ass=-1;
                }
                res.goal_list[all_goal]=tmp;
            }
            else{//what a save!
                res.home_save++;
            }
        }
    }
    //printf("return\n");
    return res;
}

void Archive(result x){
    //club
    //puts("mark1");
    ifstream in("..\\data\\clublist.sav");
    string level,need_sort;
    Club super[9],major[9],senior[9],junior[9];
    in>>level;//super
    //cout<<"level:"<<level<<endl;
    for(register int i=1;i<=8;i++){
        in>>super[i].name>>super[i].PI>>super[i].GD>>super[i].Pts;
        //printf("super No.%d : \n",i);
        //cout<<super[i].name<<setw(10);
        //printf("   PI:%d  GD:%d   Pts:%d\n",super[i].PI,super[i].GD,super[i].Pts);
        if(super[i].name==x.home_name){
            need_sort=level;
            //cout<<"need_sort yes:"<<need_sort<<endl;
            super[i].PI++;
            super[i].GD+=(x.home_goal-x.away_goal);
            if(x.home_goal>x.away_goal)
            super[i].Pts+=3;
            if(x.home_goal==x.away_goal)
            super[i].Pts++;
        }
        if(super[i].name==x.away_name){
            need_sort=level;
            //cout<<"need_sort yes:"<<need_sort<<endl;
            super[i].PI++;
            super[i].GD+=(x.away_goal-x.home_goal);
            if(x.away_goal>x.home_goal)
            super[i].Pts+=3;
            if(x.away_goal==x.home_goal)
            super[i].Pts++;
        }
    }
    in>>level;//major
    //cout<<"level:"<<level<<endl;
    for(register int i=1;i<=8;i++){
        in>>major[i].name>>major[i].PI>>major[i].GD>>major[i].Pts;
        //printf("major No.%d : \n",i);
        //cout<<major[i].name<<setw(10);
        //printf("   PI:%d  GD:%d   Pts:%d\n",major[i].PI,major[i].GD,major[i].Pts);
        if(major[i].name==x.home_name){
            need_sort=level;
            //cout<<"need_sort yes:"<<need_sort<<endl;
            major[i].PI++;
            major[i].GD+=(x.home_goal-x.away_goal);
            if(x.home_goal>x.away_goal)
            major[i].Pts+=3;
            if(x.home_goal==x.away_goal)
            major[i].Pts++;
        }
        if(major[i].name==x.away_name){
            need_sort=level;
            //cout<<"need_sort yes:"<<need_sort<<endl;
            major[i].PI++;
            major[i].GD+=(x.away_goal-x.home_goal);
            if(x.away_goal>x.home_goal)
            major[i].Pts+=3;
            if(x.away_goal==x.home_goal)
            major[i].Pts++;
        }
    }
    in>>level;//senior
    //cout<<"level:"<<level<<endl;
    for(register int i=1;i<=8;i++){
        in>>senior[i].name>>senior[i].PI>>senior[i].GD>>senior[i].Pts;
        //printf("senior No.%d : \n",i);
        //cout<<senior[i].name<<setw(10);
        //printf("   PI:%d  GD:%d   Pts:%d\n",senior[i].PI,senior[i].GD,senior[i].Pts);
        if(senior[i].name==x.home_name){
            need_sort=level;
            //cout<<"need_sort yes:"<<need_sort<<endl;
            senior[i].PI++;
            senior[i].GD+=(x.home_goal-x.away_goal);
            if(x.home_goal>x.away_goal)
            senior[i].Pts+=3;
            if(x.home_goal==x.away_goal)
            senior[i].Pts++;
        }
        if(senior[i].name==x.away_name){
            need_sort=level;
            //cout<<"need_sort yes:"<<need_sort<<endl;
            senior[i].PI++;
            senior[i].GD+=(x.away_goal-x.home_goal);
            if(x.away_goal>x.home_goal)
            senior[i].Pts+=3;
            if(x.away_goal==x.home_goal)
            senior[i].Pts++;
        }
    }
    in>>level;//junior
    //cout<<"level:"<<level<<endl;
    for(register int i=1;i<=8;i++){
        in>>junior[i].name>>junior[i].PI>>junior[i].GD>>junior[i].Pts;
        //printf("junior No.%d : \n",i);
        //cout<<junior[i].name<<setw(10);
        //printf("   PI:%d  GD:%d   Pts:%d\n",junior[i].PI,junior[i].GD,junior[i].Pts);
        if(junior[i].name==x.home_name){
            need_sort=level;
            //cout<<"need_sort yes:"<<need_sort<<endl;
            junior[i].PI++;
            junior[i].GD+=(x.home_goal-x.away_goal);
            if(x.home_goal>x.away_goal)
            junior[i].Pts+=3;
            if(x.home_goal==x.away_goal)
            junior[i].Pts++;
        }
        if(junior[i].name==x.away_name){
            need_sort=level;
            //cout<<"need_sort yes:"<<need_sort<<endl;
            junior[i].PI++;
            junior[i].GD+=(x.away_goal-x.home_goal);
            if(x.away_goal>x.home_goal)
            junior[i].Pts+=3;
            if(x.away_goal==x.home_goal)
            junior[i].Pts++;
        }
    }
    in.close();
    ofstream out("..\\data\\clublist.sav");
    //puts("wait to sort for club");
    //system("pause");
    //sort
    if(need_sort=="super")
    sort(super+1,super+9,cmp2);
    if(need_sort=="major")
    sort(major+1,major+9,cmp2);
    if(need_sort=="senior")
    sort(senior+1,senior+9,cmp2);
    if(need_sort=="junior")
    sort(junior+1,junior+9,cmp2);
    //puts("wait for out for club");
    //system("pause");
    //out
    out<<"super"<<endl;
    for(register int i=1;i<=8;i++)
    out<<super[i].name<<" "<<super[i].PI<<" "<<super[i].GD<<" "<<super[i].Pts<<endl;
    out<<endl;
    out<<"major"<<endl;
    for(register int i=1;i<=8;i++)
    out<<major[i].name<<" "<<major[i].PI<<" "<<major[i].GD<<" "<<major[i].Pts<<endl;
    out<<endl;
    out<<"senior"<<endl;
    for(register int i=1;i<=8;i++)
    out<<senior[i].name<<" "<<senior[i].PI<<" "<<senior[i].GD<<" "<<senior[i].Pts<<endl;
    out<<endl;
    out<<"junior"<<endl;
    for(register int i=1;i<=8;i++)
    out<<junior[i].name<<" "<<junior[i].PI<<" "<<junior[i].GD<<" "<<junior[i].Pts<<endl;
    out<<endl;
    //puts("out for club success");
    //system("pause");
    //cout<<"need_sort: "<<need_sort<<endl;
    out.close();
    //person(shooter)
    int num_super,num_major,num_senior,num_junior;
    person super_shoot[5000],major_shoot[5000],senior_shoot[5000],junior_shoot[5000];
    ifstream ain("..\\data\\shooterlist.sav");
    ain>>level;
    ain>>num_super;
    for(register int j=1;j<=num_super;j++)
    ain>>super_shoot[j].name>>super_shoot[j].value;
    if(level==need_sort){//super
        for(register int i=1;i<=x.home_goal+x.away_goal;i++){
            string shooter_name=x.goal_list[i].name;
            bool been=false;
            for(register int j=1;j<=num_super;j++){
                if(super_shoot[j].name==shooter_name){
                    super_shoot[j].value++;
                    been=true;
                    break;
                }
            }
            if(!been){//add new person
                num_super++;
                super_shoot[num_super].name=shooter_name;
                super_shoot[num_super].value=1;
            }
        }
    }
    ain>>level;
    ain>>num_major;
    for(register int j=1;j<=num_major;j++)
    ain>>major_shoot[j].name>>major_shoot[j].value;
    if(level==need_sort){//major
        for(register int i=1;i<=x.home_goal+x.away_goal;i++){
            string shooter_name=x.goal_list[i].name;
            bool been=false;
            for(register int j=1;j<=num_major;j++){
                if(major_shoot[j].name==shooter_name){
                    major_shoot[j].value++;
                    been=true;
                    break;
                }
            }
            if(!been){//add new person
                num_major++;
                major_shoot[num_major].name=shooter_name;
                major_shoot[num_major].value=1;
            }
        }
    }
    ain>>level;
    ain>>num_senior;
    for(register int j=1;j<=num_senior;j++)
    ain>>senior_shoot[j].name>>senior_shoot[j].value;
    if(level==need_sort){//senior
        for(register int i=1;i<=x.home_goal+x.away_goal;i++){
            string shooter_name=x.goal_list[i].name;
            bool been=false;
            for(register int j=1;j<=num_senior;j++){
                if(senior_shoot[j].name==shooter_name){
                    senior_shoot[j].value++;
                    been=true;
                    break;
                }
            }
            if(!been){//add new person
                num_senior++;
                senior_shoot[num_senior].name=shooter_name;
                senior_shoot[num_senior].value=1;
            }
        }
    }
    ain>>level;
    ain>>num_junior;
    for(register int j=1;j<=num_junior;j++)
    ain>>junior_shoot[j].name>>junior_shoot[j].value;
    if(level==need_sort){//junior
        for(register int i=1;i<=x.home_goal+x.away_goal;i++){
            string shooter_name=x.goal_list[i].name;
            bool been=false;
            for(register int j=1;j<=num_junior;j++){
                if(junior_shoot[j].name==shooter_name){
                    junior_shoot[j].value++;
                    been=true;
                    break;
                }
            }
            if(!been){//add new person
                num_junior++;
                junior_shoot[num_junior].name=shooter_name;
                junior_shoot[num_junior].value=1;
            }
        }
    }
    ain.close();
    //puts("wait to sort for shooter");
    //system("pause");
    //sort
    if(need_sort=="super")
    sort(super_shoot+1,super_shoot+num_super+1,cmp3);
    if(need_sort=="major")
    sort(major_shoot+1,major_shoot+num_major+1,cmp3);
    if(need_sort=="senior")
    sort(senior_shoot+1,senior_shoot+num_senior+1,cmp3);
    if(need_sort=="junior")
    sort(junior_shoot+1,junior_shoot+num_junior+1,cmp3);
    //puts("wait to out for shooter");
    //system("pause");
    //out
    ofstream aout("..\\data\\shooterlist.sav");
    aout<<"super"<<endl;
    aout<<num_super<<endl;
    for(register int i=1;i<=num_super;i++)
    aout<<super_shoot[i].name<<" "<<super_shoot[i].value<<endl;
    aout<<endl;
    aout<<"major"<<endl;
    aout<<num_major<<endl;
    for(register int i=1;i<=num_major;i++)
    aout<<major_shoot[i].name<<" "<<major_shoot[i].value<<endl;
    aout<<endl;
    aout<<"senior"<<endl;
    aout<<num_senior<<endl;
    for(register int i=1;i<=num_senior;i++)
    aout<<senior_shoot[i].name<<" "<<senior_shoot[i].value<<endl;
    aout<<endl;
    aout<<"junior"<<endl;
    aout<<num_junior<<endl;
    for(register int i=1;i<=num_junior;i++)
    aout<<junior_shoot[i].name<<" "<<junior_shoot[i].value<<endl;
    aout<<endl;
    aout.close();
    //puts("out for shooter success");
    //system("pause");
    //person(assister)
    person super_assist[5000],major_assist[5000],senior_assist[5000],junior_assist[5000];
    ifstream bin("..\\data\\assisterlist.sav");
    bin>>level;
    bin>>num_super;
    for(register int j=1;j<=num_super;j++)
    bin>>super_assist[j].name>>super_assist[j].value;
    if(level==need_sort){//super
        for(register int i=1;i<=x.home_goal+x.away_goal;i++){
            if(x.goal_list[i].num_ass==-1)
            continue;
            string assister_name=x.goal_list[i].assister;
            bool been=false;
            for(register int j=1;j<=num_super;j++){
                if(super_assist[j].name==assister_name){
                    super_assist[j].value++;
                    been=true;
                    break;
                }
            }
            if(!been){//add new person
                num_super++;
                super_assist[num_super].name=assister_name;
                super_assist[num_super].value=1;
            }
        }
    }
    bin>>level;
    bin>>num_major;
    for(register int j=1;j<=num_major;j++)
    bin>>major_assist[j].name>>major_assist[j].value;
    if(level==need_sort){//major
        for(register int i=1;i<=x.home_goal+x.away_goal;i++){
            if(x.goal_list[i].num_ass==-1)
            continue;
            string assister_name=x.goal_list[i].assister;
            bool been=false;
            for(register int j=1;j<=num_major;j++){
                if(major_assist[j].name==assister_name){
                    major_assist[j].value++;
                    been=true;
                    break;
                }
            }
            if(!been){//add new person
                num_major++;
                major_assist[num_major].name=assister_name;
                major_assist[num_major].value=1;
            }
        }
    }
    bin>>level;
    bin>>num_senior;
    for(register int j=1;j<=num_senior;j++)
    bin>>senior_assist[j].name>>senior_assist[j].value;
    if(level==need_sort){//senior
        for(register int i=1;i<=x.home_goal+x.away_goal;i++){
            if(x.goal_list[i].num_ass==-1)
            continue;
            string assister_name=x.goal_list[i].assister;
            bool been=false;
            for(register int j=1;j<=num_senior;j++){
                if(senior_assist[j].name==assister_name){
                    senior_assist[j].value++;
                    been=true;
                    break;
                }
            }
            if(!been){//add new person
                num_senior++;
                senior_assist[num_senior].name=assister_name;
                senior_assist[num_senior].value=1;
            }
        }
    }//system("cls");
    bin>>level;
    bin>>num_junior;
    for(register int j=1;j<=num_junior;j++)
    bin>>junior_assist[j].name>>junior_assist[j].value;
    if(level==need_sort){//junior
        for(register int i=1;i<=x.home_goal+x.away_goal;i++){
            if(x.goal_list[i].num_ass==-1)
            continue;
            string assister_name=x.goal_list[i].assister;
            bool been=false;
            for(register int j=1;j<=num_junior;j++){
                if(junior_assist[j].name==assister_name){
                    junior_assist[j].value++;
                    been=true;
                    break;
                }
            }
            if(!been){//add new person
                num_junior++;
                junior_assist[num_junior].name=assister_name;
                junior_assist[num_junior].value=1;
            }
        }
    }
    bin.close();
    //puts("wait to sort for assister");
    //system("pause");
    //sort
    if(need_sort=="super")
    sort(super_assist+1,super_assist+num_super+1,cmp3);
    if(need_sort=="major")
    sort(major_assist+1,major_assist+num_major+1,cmp3);
    if(need_sort=="senior")
    sort(senior_assist+1,senior_assist+num_senior+1,cmp3);
    if(need_sort=="junior")
    sort(junior_assist+1,junior_assist+num_junior+1,cmp3);
    //out
    //puts("wait to out for assister");
    //system("pause");
    ofstream bout("..\\data\\assisterlist.sav");
    bout<<"super"<<endl;
    bout<<num_super<<endl;
    for(register int i=1;i<=num_super;i++)
    bout<<super_assist[i].name<<" "<<super_assist[i].value<<endl;
    bout<<endl;
    bout<<"major"<<endl;
    bout<<num_major<<endl;
    for(register int i=1;i<=num_major;i++)
    bout<<major_assist[i].name<<" "<<major_assist[i].value<<endl;
    bout<<endl;
    bout<<"senior"<<endl;
    bout<<num_senior<<endl;
    for(register int i=1;i<=num_senior;i++)
    bout<<senior_assist[i].name<<" "<<senior_assist[i].value<<endl;
    bout<<endl;
    bout<<"junior"<<endl;
    bout<<num_junior<<endl;
    for(register int i=1;i<=num_junior;i++)
    bout<<junior_assist[i].name<<" "<<junior_assist[i].value<<endl;
    bout<<endl;
    bout.close();
    //puts("out for assister success");
    //system("pause");
    //puts("mark");
    ifstream din("..\\data\\goalkeeperlist.sav");
    person super_GK[50],major_GK[50],senior_GK[50],junior_GK[50];
    din>>level;
    din>>num_super;
    //printf("num_super=%d\n",num_super);
    for(register int i=1;i<=num_super;i++)
    din>>super_GK[i].name>>super_GK[i].value;
    if(level==need_sort){
        string home_GK=FindTeam(x.home_name).name[11];
        string away_GK=FindTeam(x.away_name).name[11];
        bool been=false;
        for(register int i=1;i<=num_super;i++){
            if(super_GK[i].name==home_GK){
                super_GK[i].value+=x.home_save;
                been=true;
            }
        }
        if(!been&&x.home_save>0){
            num_super++;
            super_GK[num_super].name=home_GK;
            super_GK[num_super].value=x.home_save;
        }
        been=false;
        for(register int i=1;i<=num_super;i++){
            if(super_GK[i].name==away_GK){
                super_GK[i].value+=x.away_save;
                been=true;
            }
        }
        if(!been&&x.away_save>0){
            num_super++;
            super_GK[num_super].name=away_GK;
            super_GK[num_super].value=x.away_save;
        }
    }
    din>>level;
    din>>num_major;
    for(register int i=1;i<=num_major;i++)
    din>>major_GK[i].name>>major_GK[i].value;
    if(level==need_sort){
        string home_GK=FindTeam(x.home_name).name[11];
        string away_GK=FindTeam(x.away_name).name[11];
        bool been=false;
        for(register int i=1;i<=num_major;i++){
            if(major_GK[i].name==home_GK){
                major_GK[i].value+=x.home_save;
                been=true;
            }
        }
        if(!been&&x.home_save>0){
            num_major++;
            major_GK[num_major].name=home_GK;
            major_GK[num_major].value=x.home_save;
        }
        been=false;
        for(register int i=1;i<=num_major;i++){
            if(major_GK[i].name==away_GK){
                major_GK[i].value+=x.away_save;
                been=true;
            }
        }
        if(!been&&x.away_save>0){
            num_major++;
            major_GK[num_major].name=away_GK;
            major_GK[num_major].value=x.away_save;
        }
    }
    din>>level;
    din>>num_senior;
    for(register int i=1;i<=num_senior;i++)
    din>>senior_GK[i].name>>senior_GK[i].value;
    if(level==need_sort){
        string home_GK=FindTeam(x.home_name).name[11];
        string away_GK=FindTeam(x.away_name).name[11];
        bool been=false;
        for(register int i=1;i<=num_senior;i++){
            if(senior_GK[i].name==home_GK){
                senior_GK[i].value+=x.home_save;
                been=true;
            }
        }
        if(!been&&x.home_save>0){
            num_senior++;
            senior_GK[num_senior].name=home_GK;
            senior_GK[num_senior].value=x.home_save;
        }
        been=false;
        for(register int i=1;i<=num_senior;i++){
            if(senior_GK[i].name==away_GK){
                senior_GK[i].value+=x.away_save;
                been=true;
            }
        }
        if(!been&&x.away_save>0){
            num_senior++;
            senior_GK[num_senior].name=away_GK;
            senior_GK[num_senior].value=x.away_save;
        }
    }
    din>>level;
    din>>num_junior;
    for(register int i=1;i<=num_junior;i++)
    din>>junior_GK[i].name>>junior_GK[i].value;
    if(level==need_sort){
        string home_GK=FindTeam(x.home_name).name[11];
        string away_GK=FindTeam(x.away_name).name[11];
        bool been=false;
        for(register int i=1;i<=num_junior;i++){
            if(junior_GK[i].name==home_GK){
                junior_GK[i].value+=x.home_save;
                been=true;
            }
        }
        if(!been&&x.home_save>0){
            num_junior++;
            junior_GK[num_junior].name=home_GK;
            junior_GK[num_junior].value=x.home_save;
        }
        been=false;
        for(register int i=1;i<=num_junior;i++){
            if(junior_GK[i].name==away_GK){
                junior_GK[i].value+=x.away_save;
                been=true;
            }
        }
        if(!been&&x.away_save>0){
            num_junior++;
            junior_GK[num_junior].name=away_GK;
            junior_GK[num_junior].value=x.away_save;
        }
    }
    din.close();
    if(need_sort=="super")
    sort(super_GK+1,super_GK+num_super+1,cmp3);
    if(need_sort=="major")
    sort(major_GK+1,major_GK+num_major+1,cmp3);
    if(need_sort=="senior")
    sort(senior_GK+1,senior_GK+num_senior+1,cmp3);
    if(need_sort=="junior")
    sort(junior_GK+1,junior_GK+num_junior+1,cmp3);
    ofstream dout("..\\data\\goalkeeperlist.sav");
    dout<<"super"<<endl;
    dout<<num_super<<endl;
    for(register int i=1;i<=num_super;i++)
    dout<<super_GK[i].name<<" "<<super_GK[i].value<<endl;
    dout<<endl;
    dout<<"major"<<endl;
    dout<<num_major<<endl;
    for(register int i=1;i<=num_major;i++)
    dout<<major_GK[i].name<<" "<<major_GK[i].value<<endl;
    dout<<endl;
    dout<<"senior"<<endl;
    dout<<num_senior<<endl;
    for(register int i=1;i<=num_senior;i++)
    dout<<senior_GK[i].name<<" "<<senior_GK[i].value<<endl;
    dout<<endl;
    dout<<"junior"<<endl;
    dout<<num_junior<<endl;
    for(register int i=1;i<=num_junior;i++)
    dout<<junior_GK[i].name<<" "<<junior_GK[i].value<<endl;
    dout<<endl;
    dout.close();
    return;
}

result GetResult(int x){
    result res;
    ifstream in("..\\data\\result.sav");
    for(register int i=1;i<=x;i++){
        in>>res.home_name;
        in>>res.away_name;
        in>>res.home_goal;
        in>>res.away_goal;
        in>>res.home_shoot;
        in>>res.away_shoot;
        in>>res.home_shoot_on_target;
        in>>res.away_shoot_on_target;
        in>>res.home_save;
        in>>res.away_save;
        in>>res.home_holdball;
        in>>res.away_holdball;
        for(register int i=1;i<=res.home_goal+res.away_goal;i++){
            in>>res.goal_list[i].goal_side;
            in>>res.goal_list[i].name;
            in>>res.goal_list[i].kit_num;
            in>>res.goal_list[i].goal_time;
            in>>res.goal_list[i].assister;
            in>>res.goal_list[i].num_ass;
        }
    }
    return res;
}

void PushResult(result x){
    ofstream out("..\\data\\result.sav",ios::app);
    out<<x.home_name<<endl;
    out<<x.away_name<<endl;
    out<<x.home_goal<<endl;
    out<<x.away_goal<<endl;
    out<<x.home_shoot<<endl;
    out<<x.away_shoot<<endl;
    out<<x.home_shoot_on_target<<endl;
    out<<x.away_shoot_on_target<<endl;
    out<<x.home_save<<endl;
    out<<x.away_save<<endl;
    out<<x.home_holdball<<endl;
    out<<x.away_holdball<<endl;
    for(register int i=1;i<=x.home_goal+x.away_goal;i++){
        out<<x.goal_list[i].goal_side<<endl;
        out<<x.goal_list[i].name<<endl;
        out<<x.goal_list[i].kit_num<<endl;
        out<<x.goal_list[i].goal_time<<endl;
        out<<x.goal_list[i].assister<<endl;
        out<<x.goal_list[i].num_ass<<endl;
    }
    return;
}

void NewSeason(){
    Club super[9],major[9],senior[9],junior[9];
    string level;
    ifstream in("..\\data\\clublist.sav");
    in>>level;//super
    for(register int i=1;i<=8;i++){
        in>>super[i].name>>super[i].PI>>super[i].GD>>super[i].Pts;
        super[i].PI=super[i].GD=super[i].Pts=0;
    }
    in>>level;//major
    for(register int i=1;i<=8;i++){
        in>>major[i].name>>major[i].PI>>major[i].GD>>major[i].Pts;
        major[i].PI=major[i].GD=major[i].Pts=0;
    }
    in>>level;//senior
    for(register int i=1;i<=8;i++){
        in>>senior[i].name>>senior[i].PI>>senior[i].GD>>senior[i].Pts;
        senior[i].PI=senior[i].GD=senior[i].Pts=0;
    }
    in>>level;//junior
    for(register int i=1;i<=8;i++){
        in>>junior[i].name>>junior[i].PI>>junior[i].GD>>junior[i].Pts;
        junior[i].PI=junior[i].GD=junior[i].Pts=0;
    }
    in.close();
    //upgrade & downgrade
    swap(super[7],major[1]);
    swap(super[8],major[2]);//super<-->major
    swap(major[7],senior[1]);
    swap(major[8],senior[2]);//major<-->senior
    swap(senior[7],junior[1]);
    swap(senior[8],junior[2]);//senior<-->junior
    ofstream out("..\\data\\clublist.sav");
    out<<"super"<<endl;
    for(register int i=1;i<=8;i++)
    out<<super[i].name<<" "<<super[i].PI<<" "<<super[i].GD<<" "<<super[i].Pts<<endl;
    out<<endl;
    out<<"major"<<endl;
    for(register int i=1;i<=8;i++)
    out<<major[i].name<<" "<<major[i].PI<<" "<<major[i].GD<<" "<<major[i].Pts<<endl;
    out<<endl;
    out<<"senior"<<endl;
    for(register int i=1;i<=8;i++)
    out<<senior[i].name<<" "<<senior[i].PI<<" "<<senior[i].GD<<" "<<senior[i].Pts<<endl;
    out<<endl;
    out<<"junior"<<endl;
    for(register int i=1;i<=8;i++)
    out<<junior[i].name<<" "<<junior[i].PI<<" "<<junior[i].GD<<" "<<junior[i].Pts<<endl;
    out<<endl;
    out.close();
    ofstream aout("..\\data\\shooterlist.sav");
    aout<<"super\n0\n\nmajor\n0\n\nsenior\n0\n\njunior\n0\n";
    aout.close();
    ofstream bout("..\\data\\assisterlist.sav");
    bout<<"super\n0\n\nmajor\n0\n\nsenior\n0\n\njunior\n0\n";
    bout.close();
    ofstream fout("..\\data\\goalkeeperlist.sav");
    fout<<"super\n0\n\nmajor\n0\n\nsenior\n0\n\njunior\n0\n";
    fout.close();
    ofstream dout("..\\data\\round.sav");
    dout<<"0\n0\n";
    dout.close();
    ofstream eout("..\\data\\result.sav");
    eout<<endl;
    eout.close();
    return;
}

void ShowClubList(){
    ifstream in("..\\data\\clublist.sav");
    string level,team_name;
    int PI,GD,Pts;
    in>>level;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Club"<<setw(5)<<"PI"<<setw(4)<<"GD"<<setw(5)<<"Pts\n";
    for(register int i=1;i<=8;i++){
        in>>team_name>>PI>>GD>>Pts;
        cout<<i<<setw(25)<<team_name<<setw(4)<<PI<<setw(4)<<GD<<setw(4)<<Pts<<endl;
    }
    puts("\n\n");
    in>>level;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Club"<<setw(5)<<"PI"<<setw(4)<<"GD"<<setw(5)<<"Pts\n";
    for(register int i=1;i<=8;i++){
        in>>team_name>>PI>>GD>>Pts;
        cout<<i<<setw(25)<<team_name<<setw(4)<<PI<<setw(4)<<GD<<setw(4)<<Pts<<endl;
    }
    puts("\n\n");
    in>>level;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Club"<<setw(5)<<"PI"<<setw(4)<<"GD"<<setw(5)<<"Pts\n";
    for(register int i=1;i<=8;i++){
        in>>team_name>>PI>>GD>>Pts;
        cout<<i<<setw(25)<<team_name<<setw(4)<<PI<<setw(4)<<GD<<setw(4)<<Pts<<endl;
    }
    puts("\n\n");
    in>>level;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Club"<<setw(5)<<"PI"<<setw(4)<<"GD"<<setw(5)<<"Pts\n";
    for(register int i=1;i<=8;i++){
        in>>team_name>>PI>>GD>>Pts;
        cout<<i<<setw(25)<<team_name<<setw(4)<<PI<<setw(4)<<GD<<setw(4)<<Pts<<endl;
    }
    in.close();
    return;
}

void ShowShooterList(){
    ifstream in("..\\data\\shooterlist.sav");
    string level,name;
    int num,score;
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Goals\n";
    for(register int i=1;i<=num;i++){
        in>>name>>score;
        cout<<i<<setw(25)<<name<<setw(13)<<score<<endl;
    }
    puts("\n\n");
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Goals\n";
    for(register int i=1;i<=num;i++){
        in>>name>>score;
        cout<<i<<setw(25)<<name<<setw(13)<<score<<endl;
    }
    puts("\n\n");
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Goals\n";
    for(register int i=1;i<=num;i++){
        in>>name>>score;
        cout<<i<<setw(25)<<name<<setw(13)<<score<<endl;
    }
    puts("\n\n");
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Goals\n";
    for(register int i=1;i<=num;i++){
        in>>name>>score;
        cout<<i<<setw(25)<<name<<setw(13)<<score<<endl;
    }
    puts("\n\n");
    in.close();
    return;
}

void ShowAssisterList(){
    ifstream in("..\\data\\assisterlist.sav");
    string level,name;
    int num,assists;
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Assists\n";
    for(register int i=1;i<=num;i++){
        in>>name>>assists;
        cout<<i<<setw(25)<<name<<setw(13)<<assists<<endl;
    }
    puts("\n\n");
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Assists\n";
    for(register int i=1;i<=num;i++){
        in>>name>>assists;
        cout<<i<<setw(25)<<name<<setw(13)<<assists<<endl;
    }
    puts("\n\n");
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Assists\n";
    for(register int i=1;i<=num;i++){
        in>>name>>assists;
        cout<<i<<setw(25)<<name<<setw(13)<<assists<<endl;
    }
    puts("\n\n");
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Assists\n";
    for(register int i=1;i<=num;i++){
        in>>name>>assists;
        cout<<i<<setw(25)<<name<<setw(13)<<assists<<endl;
    }
    puts("\n\n");
    in.close();
    return;
}

void ShowTeam(){
    ifstream in("..\\data\\clublist.sav");
    string level,team_name;
    int PI,GD,Pts;
    in>>level;
    cout<<level<<" league\n";
    //cout<<"Pos"<<setw(23)<<"Club"<<setw(5)<<"PI"<<setw(4)<<"GD"<<setw(5)<<"Pts\n";
    for(register int i=1;i<=8;i++){
        in>>team_name>>PI>>GD>>Pts;
        cout<<i<<setw(25)<<team_name/*<<setw(4)<<PI<<setw(4)<<GD<<setw(4)<<Pts*/<<endl;
    }
    puts("\n\n");
    in>>level;
    cout<<level<<" league\n";
    //cout<<"Pos"<<setw(23)<<"Club"<<setw(5)<<"PI"<<setw(4)<<"GD"<<setw(5)<<"Pts\n";
    for(register int i=1;i<=8;i++){
        in>>team_name>>PI>>GD>>Pts;
        cout<<i<<setw(25)<<team_name/*<<setw(4)<<PI<<setw(4)<<GD<<setw(4)<<Pts*/<<endl;
    }
    puts("\n\n");
    in>>level;
    cout<<level<<" league\n";
    //cout<<"Pos"<<setw(23)<<"Club"<<setw(5)<<"PI"<<setw(4)<<"GD"<<setw(5)<<"Pts\n";
    for(register int i=1;i<=8;i++){
        in>>team_name>>PI>>GD>>Pts;
        cout<<i<<setw(25)<<team_name/*<<setw(4)<<PI<<setw(4)<<GD<<setw(4)<<Pts*/<<endl;
    }
    puts("\n\n");
    in>>level;
    cout<<level<<" league\n";
    //cout<<"Pos"<<setw(23)<<"Club"<<setw(5)<<"PI"<<setw(4)<<"GD"<<setw(5)<<"Pts\n";
    for(register int i=1;i<=8;i++){
        in>>team_name>>PI>>GD>>Pts;
        cout<<i<<setw(25)<<team_name/*<<setw(4)<<PI<<setw(4)<<GD<<setw(4)<<Pts*/<<endl;
    }
    in.close();
    return;
}

void ShowGoalkeeperList(){
    ifstream in("..\\data\\goalkeeperlist.sav");
    string level,name;
    int num,saves;
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Saves\n";
    for(register int i=1;i<=num;i++){
        in>>name>>saves;
        cout<<i<<setw(25)<<name<<setw(13)<<saves<<endl;
    }
    puts("\n\n");
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Saves\n";
    for(register int i=1;i<=num;i++){
        in>>name>>saves;
        cout<<i<<setw(25)<<name<<setw(13)<<saves<<endl;
    }
    puts("\n\n");
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Saves\n";
    for(register int i=1;i<=num;i++){
        in>>name>>saves;
        cout<<i<<setw(25)<<name<<setw(13)<<saves<<endl;
    }
    puts("\n\n");
    in>>level;
    in>>num;
    cout<<level<<" league\n";
    cout<<"Pos"<<setw(23)<<"Name"<<setw(15)<<"Saves\n";
    for(register int i=1;i<=num;i++){
        in>>name>>saves;
        cout<<i<<setw(25)<<name<<setw(13)<<saves<<endl;
    }
    puts("\n\n");
    in.close();
    return;
}

#endif