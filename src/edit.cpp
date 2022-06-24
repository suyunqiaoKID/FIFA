#include "bits/stdc++.h"
#include "fifa.h"

using namespace std;

string name;

int main(){
    srand(time(NULL));
    //freopen("..\\note\\data.txt","w",stdout);
    /*puts("press name");
    cin>>name;
    if(FindType(name)==0){
        GK ply;
        ply=FindGK(name);
        printf("position:");
        cout<<ply.posi<<endl;
        printf("name:");
        cout<<ply.name<<endl;
        printf("DIV:%d\n",ply.div);
        printf("REF:%d\n",ply.ref);
        printf("HAN:%d\n",ply.han);
        printf("SPD:%d\n",ply.spd);
        printf("KIC:%d\n",ply.kic);
        printf("POS:%d\n",ply.pos);
    }
    else{
        player ply;
        ply=FindPlayer(name);
        printf("position:");
        cout<<ply.posi<<endl;
        printf("name:");
        cout<<ply.name<<endl;
        printf("PAC:%d\n",ply.pac);
        printf("DIR:%d\n",ply.dri);
        printf("SHO:%d\n",ply.sho);
        printf("DEF:%d\n",ply.def);
        printf("PAS:%d\n",ply.pas);
        printf("PHY:%d\n",ply.phy);
    }*/
    /*puts("press team_name");
    cin>>name;
    */
    /*Team t=FindTeam("Dortmund");
    printf("OverAll:%d\n",t.OverAll);
    printf("Attack:%d\n",t.Attack);
    printf("MidField:%d\n",t.MidField);
    printf("Defence:%d\n",t.Defence);
    */
    //srand(time(NULL));
    while(true){
        detail(match("Dortmund","Tottenham-Hotspur"));
        puts("");
        system("pause");
        system("cls");
    }
    /*ifstream in("..\\data\\league.sav");
    for(register int i=1;i<=4;i++){
        string level;
        string team_name;
        in>>level;
        cout<<level<<endl;
        for(register int j=1;j<=8;j++){
            in>>team_name;
            cout<<team_name<<endl;
            Team t=FindTeam(team_name);
            printf("OverAll:%d\n",t.OverAll);
            printf("Attack:%d\n",t.Attack);
            printf("MidField:%d\n",t.MidField);
            printf("Defence:%d\n",t.Defence);
            puts("\n");
        }
    }
    while(true){
        player ply;
        string plyname;
        cin>>plyname;
        ply=FindPlayer(plyname);
        printf("position:");
        cout<<ply.posi<<endl;
        printf("name:");
        cout<<ply.name<<endl;
        printf("PAC:%d\n",ply.pac);
        printf("DIR:%d\n",ply.dri);
        printf("SHO:%d\n",ply.sho);
        printf("DEF:%d\n",ply.def);
        printf("PAS:%d\n",ply.pas);
        printf("PHY:%d\n",ply.phy);
        puts("\n");
        system("pause");
    }*/
    system("pause");
    return 0;
}