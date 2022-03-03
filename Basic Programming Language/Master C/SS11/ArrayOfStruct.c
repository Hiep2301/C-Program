#include<stdio.h>
#include<string.h>

struct FootballTeam
{
    /* data */
    char teamId[5];
    char teamName[50];
    char coachName[50];
    int score;
};

void printTeamInfo(struct FootballTeam team);
struct FootballTeam getTeamInfo();


int main(int argc, char const *argv[])
{
    struct FootballTeam listTeams[10] = 
    {
        {"A1", "I to P", "Dao Van Duc", 10},
        {"A2", "DSA", "Dao Van Duc", 11},
        {"A3", "OOP", "Dao Van Duc", 12},
        {"A4", "Networking", "Dao Van Duc", 1},
        {"A5", "RDBMS", "Dao Van Duc", 2}
    };

    for (int i = 0; i < 5; i++)
    {
        printTeamInfo(listTeams[i]);
    }
    
    listTeams[5] = getTeamInfo();

    return 0;
}

void printTeamInfo(struct FootballTeam team)
{
    printf("\n----------------------------------------------------------------------\n");
    printf("    %-10s\t\t %-12s\t\t %8s\t %d\n\n", team.teamId, team.teamName, team.coachName, team.score);
    printf("------------------------------------------------------------------------\n");
    // printf("\n---------------------\n");
    // printf("Ma doi : %s\n", team.teamId);
    // printf("Ten doi: %s\n", team.teamName);
    // printf("Ten HLV: %s\n", team.coachName);
    // printf("Diem   : %d\n", team.score);
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