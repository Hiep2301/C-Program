#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("Console setup\n");
    printf("-------------\n");
    printf("1) Configure Network Interfaces\n");
    printf("2) Configure Link Aggregation\n");
    printf("3) Configure VLAN Interface\n");
    printf("4) Configure Default Route\n");
    printf("5) Configure Static Routes\n");
    printf("6) Configure DNS\n");
    printf("7) Reset Root Password\n");
    printf("8) Reset to factory defaults\n");
    printf("9) Shell\n");
    printf("10) System Update (requires networking)\n");
    printf("11) Create volume backup\n");
    printf("12) Restore volume from a backup\n");
    printf("13) Reboot\n");
    printf("14) Shutdown\n");

    int option;
    printf("\nEnter an option from 1-14: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        printf("1) Configure Network Interfaces\n");
        break;
    case 2:
        printf("2) Configure Link Aggregation\n");
        break;
    case 3:
        printf("3) Configure VLAN Interface\n");
        break;
    case 4:
        printf("4) Configure Default Route\n");
        break;
    case 5:
        printf("5) Configure Static Routes\n");
        break;
    case 6:
        printf("6) Configure DNS\n");
        break;
    case 7:
        printf("7) Reset Root Password\n");
        break;
    case 8:
        printf("8) Reset to factory defaults\n");
        break;
    case 9:
        printf("9) Shell\n");
        break;
    case 10:
        printf("10) System Update (requires networking)\n");
        break;
    case 11:
        printf("11) Create volume backup\n");
        break;
    case 12:
        printf("12) Restore volume from a backup\n");
        break;
    case 13:
        printf("13) Reboot\n");
        break;
    case 14:
        printf("14) Shutdown\n");
        break;
    default:
        printf("Error Message");
        break;
    }
    return 0;
}
