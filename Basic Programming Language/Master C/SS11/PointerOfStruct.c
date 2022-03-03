#include <stdio.h>
#include <string.h>
#include<stdlib.h>


struct FootballTeam
{
    char teamId[5];
    char teamName[50];
    char coachName[50];
    int score;
};

struct FootballTeam getTeamInfo();
void printTeamInfo(struct FootballTeam *pTeam);

int main(int argc, char const *argv[])
{
    struct FootballTeam team = {"A", "JAV", "Tokuda", 10};
    struct FootballTeam *pTeam;

    pTeam = &team;

    printf("Ma doi : %s\n", pTeam->teamId);
    printf("Ten doi: %s\n", pTeam->teamName);
    printf("Ten HLV: %s\n", pTeam->coachName);
    printf("Diem   : %d\n", pTeam->score);


    struct FootballTeam *listTeams;

    listTeams = malloc(5 * sizeof(struct FootballTeam));
    
    for (int i = 0; i < 5; i++)
    {
        *(listTeams + i) = getTeamInfo();
    }
    
    for (int i = 0; i < 5; i++)
    {
        printTeamInfo(listTeams + i);
    }
    
    
    
    return 0;
}

void printTeamInfo(struct FootballTeam *pTeam)
{
    printf("\n----------------------------------------------------------------------\n");
    printf("    %-10s\t\t %-12s\t\t %8s\t %d\n\n", pTeam->teamId, pTeam->teamName, pTeam->coachName, pTeam->score);
    printf("------------------------------------------------------------------------\n");
}

struct FootballTeam getTeamInfo()
{
    struct FootballTeam team;

    printf("Ma doi : ");
    gets(team.teamId);
    printf("Ten doi: ");
    gets(team.teamName);
    printf("Ten HLV: ");
    gets(team.coachName);
    //fflush(stdin);
    printf("Diem   : ");
    scanf("%d", &team.score);

    return team;
}