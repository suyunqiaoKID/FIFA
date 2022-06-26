#include "fifa.h"

#include "conio.h"

using namespace std;

int now_round;

string host_team;

string home[225],away[225];

void CreatSchedule();

void GetSchedule();

void init();

void save();

void choose_host_team();

void CreatSchedule(){
    ifstream in("..\\data\\clublist.sav");
    int round=0;
    Club x[5][9];
    int num_h[57]={0,1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4,5,1,2,5,7,1,1,2,3,4,5,6,8,8,7,7,6,3,3,4,6,8,5,4,2,6,7,8,6,7,8,5,7,8,5,6,8,5,6,7};
    int num_a[57]={0,8,7,6,5,7,6,5,8,6,5,8,7,5,8,7,6,4,2,4,6,8,3,4,3,2,1,7,8,7,6,5,6,7,1,4,3,5,5,8,2,1,3,2,1,4,3,2,1,4,3,2,1,4,3,2,1};
    string out_home[225],out_away[225];
    for(register int i=1;i<=4;i++){
        string level;
        in>>level;
        for(register int j=1;j<=8;j++)
        in>>x[i][j].name>>x[i][j].PI>>x[i][j].GD>>x[i][j].Pts;
    }
    for(register int i=1;i<=4;i++){
        round=i;
        for(register int j=1;j<=56;j++){
            out_home[round]=x[i][num_h[j]].name;
            out_away[round]=x[i][num_a[j]].name;
            round+=4;
        }
    }
    in.close();
    ofstream out("..\\data\\round.sav");
    out<<1<<endl;
    out<<0<<endl;
    for(register int i=1;i<=224;i++)
    out<<out_home[i]<<" "<<out_away[i]<<endl;
    out.close();
    return;
}

void GetSchedule(){
    bool inited;
    ifstream in("..\\data\\round.sav");
    in>>inited>>now_round;
    for(register int i=1;i<=224;i++)
    in>>home[i]>>away[i];
    in.close();
    return;
}

void init(){
    bool inited;
    int round;
    ifstream in("..\\data\\round.sav");
    in>>inited>>round;
    if(!inited)
    CreatSchedule();
    GetSchedule();
    in.close();
    return;
}

void save(){
    ofstream out("..\\data\\round.sav");
    out<<1<<endl;
    out<<now_round<<endl;
    for(register int i=1;i<=224;i++)
    out<<home[i]<<" "<<away[i]<<endl;
    out.close();
    return;
}

void choose_host_team(){
    ifstream in("..\\data\\host_team.sav");
    in>>host_team;
    in.close();
    if(host_team=="Null"){
        puts("choose your host team in these team");
        ShowTeam();
        cin>>host_team;
        while(FindTeam(host_team).team_name=="Null"){
            puts("opps! can't find it , press again please");
            cin>>host_team;
        }
        ofstream out("..\\data\\host_team.sav");
        out<<host_team<<endl;
        out.close();
    }
    return;
}

int main(){
    srand(time(NULL));
    init();
    choose_host_team();
    while(true){
        system("cls");
        printf("next game id:%d    ",now_round+1);
        cout<<"your host team :"<<host_team<<endl;
        puts("Q:save W:jump to next game      E:jump to next host team game       R:view histroy game record\nT:view team standing    Y:view shooter broad     U:view assister broad     I:view goalkeeper broad");
        char key;
        do{
            key=getch();
            if(key>='a'&&key<='z')
            key+='A'-'a';
            if(key=='Q'){
                save();
                return 0;
            }
            else if(key=='W'){
                system("cls");
                now_round++;
                if(now_round>224){
                    puts("this season is finished");
                    puts("let's view this season!");
                    puts("press any key to continue");
                    char opt=getch();
                    system("cls");
                    ShowClubList();
                    puts("\n\n");
                    ShowShooterList();
                    puts("\n\n");
                    ShowAssisterList();
                    puts("\n\n");
                    ShowGoalkeeperList();
                    puts("\n\n");
                    puts("press any key to start next season!");
                    opt=getch();
                    NewSeason();
                    init();
                    now_round=0;
                    system("cls");
                }
                result tmp=match(home[now_round],away[now_round]);
                //printf("mark2");
                detail(tmp);
                Archive(tmp);
                PushResult(tmp);
                save();
                puts("press any key to back");
                char opt=getch();
                break;
            }
            else if(key=='E'){
                system("cls");
                while(home[now_round+1]!=host_team&&away[now_round+1]!=host_team){
                    now_round++;
                    if(now_round>224){
                    puts("this season is finished");
                    puts("let's view this season!");
                    puts("press any key to continue");
                    char opt=getch();
                    system("cls");
                    ShowClubList();
                    puts("\n\n");
                    ShowShooterList();
                    puts("\n\n");
                    ShowAssisterList();
                    puts("\n\n");
                    ShowGoalkeeperList();
                    puts("\n\n");
                    puts("press any key to start next season!");
                    opt=getch();
                    NewSeason();
                    now_round=0;
                    system("cls");
                    break;
                }
                    result tmp=match(home[now_round],away[now_round]);
                    Archive(tmp);
                    PushResult(tmp);
                    save();
                }
                now_round++;
                if(now_round>224){
                    puts("this season is finished");
                    puts("let's view this season!");
                    puts("press any key to continue");
                    char opt=getch();
                    system("cls");
                    ShowClubList();
                    puts("\n\n");
                    ShowShooterList();
                    puts("\n\n");
                    ShowAssisterList();
                    puts("\n\n");
                    ShowGoalkeeperList();
                    puts("\n\n");
                    puts("press any key to start next season!");
                    opt=getch();
                    NewSeason();
                    now_round=0;
                    init();
                    system("cls");
                    break;
                }
                result tmp=match(home[now_round],away[now_round]);
                Archive(tmp);
                PushResult(tmp);
                detail(tmp);
                save();
                puts("press any key to back");
                char opt=getch();
                break;
            }
            else if(key=='R'){
                system("cls");
                for(register int i=1;i<=now_round;i++){
                    result tmp=GetResult(i);
                    printf("game id:%d\n",i);
                    cout<<setw(15)<<tmp.home_name<<setw(5)<<" vs "<<setw(15)<<tmp.away_name<<endl;
                    cout<<setw(15)<<tmp.home_goal<<" - "<<tmp.away_goal<<endl;
                }
                puts("Q:back   W:view specified match   E:view specified team's match");
                char opt;
                do{
                    opt=getch();
                    if(opt>='a'&&opt<='z')
                    opt+='A'-'a';
                    if(opt=='Q'){
                        system("cls");
                        break;
                    }
                    else if(opt=='W'){
                        puts("press game id to view");
                        int x;
                        cin>>x;
                        system("cls");
                        detail(GetResult(x));
                        puts("press any key to back");
                        opt=getch();
                        break;
                    }
                    else if(opt=='E'){
                        puts("press team name id to view");
                        string team_name;
                        cin>>team_name;
                        system("cls");
                        for(register int i=1;i<=now_round;i++){
                            result tmp=GetResult(i);
                            if(tmp.home_name!=team_name&&tmp.away_name!=team_name)
                            continue;
                            printf("game id:%d\n",i);
                            cout<<setw(15)<<tmp.home_name<<setw(5)<<" vs "<<setw(15)<<tmp.away_name<<endl;
                            cout<<setw(15)<<tmp.home_goal<<" - "<<tmp.away_goal<<endl;
                        }
                        puts("Q:back  W:view specified match");
                        char opt1;
                        do{
                            opt1=getch();
                            if(opt1>='a'&&opt1<='z')
                            opt1+='A'-'a';
                            if(opt1=='Q'){
                                system("cls");
                                break;
                            }
                            else if(opt1=='W'){
                                puts("press game id to view");
                                int x;
                                cin>>x;
                                system("cls");
                                detail(GetResult(x));
                                puts("press any key to back");
                                opt=getch();
                                break;
                            }
                        }while(opt1!='Q'&&opt1!='W');
                    }
                }while(opt!='Q'&&opt!='W'&&opt!='E');
            }
            else if(key=='T'){
                system("cls");
                ShowClubList();
                puts("press any key to back");
                char opt=getch();
                break;
            }
            else if(key=='Y'){
                system("cls");
                ShowShooterList();
                puts("press any key to back");
                char opt=getch();
                break;
            }
            else if(key=='U'){
                system("cls");
                ShowAssisterList();
                puts("press any key to back");
                char opt=getch();
                break;
            }
            else if(key=='I'){
                system("cls");
                ShowGoalkeeperList();
                puts("press any key to back");
                char opt=getch();
                break;
            }
        }while(key!='Q'&&key!='W'&&key!='E'&&key!='R'&&key!='T'&&key!='Y');
    }
    return 0;
}