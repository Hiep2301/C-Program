#include<stdio.h>
#include<string.h>

//Định nghĩa struct là định nghĩa 1 kiểu dữ liệu mới
//Nên phần định nghĩa này phải nằm ngoài tất cả các hàm

typedef struct
{
    /* data */
    char teamId[5];
    char teamName[50];
    char coachName[50];
    int score;
} FootballTeam;

void printTeamInfo(FootballTeam team);

int main(int argc, char const *argv[])
{
    //Khai báo biến team1 có kiểu dữ liệu là struct FootballTeam
    FootballTeam team1;

    //Truy cập vào các biến thành viên của struct bằng toán tử .
    strcpy(team1.teamId, "SLNA");
    strcpy(team1.teamName, "Song Lam Nghe An");
    strcpy(team1.coachName, "Dao Van Duc");
    team1.score = 10;

    printf("Ma doi : %s\n", team1.teamId);
    printf("Ten doi: %s\n", team1.teamName);
    printf("Ten HLV: %s\n", team1.coachName);
    printf("Diem   : %d\n", team1.score);

    FootballTeam team2;
    //Nhập thông tin cho team2 từ bàn phím, sau đó in ra màn hình
    printf("\n---------------------\n");
    printf("Ma doi : ");
    gets(team2.teamId);
    printf("Ten doi: ");
    gets(team2.teamName);
    printf("Ten HLV: ");
    gets(team2.coachName);
    //fflush(stdin);
    printf("Diem   : ");
    scanf("%d", &team2.score);
    
    printTeamInfo(team2);
    return 0;
}

void printTeamInfo(FootballTeam team)
{
    printf("\n---------------------\n");
    printf("Ma doi : %s\n", team.teamId);
    printf("Ten doi: %s\n", team.teamName);
    printf("Ten HLV: %s\n", team.coachName);
    printf("Diem   : %d\n", team.score);
}
    