#include <stdio.h>

struct activity {
    char date[20];
    float km;
    float time;
    float weight;
    int reps;
};

void red() {
    printf("\033[0;31m");
}
void green() {
    printf("\033[0;32m");
}
void cyan() {
    printf("\033[0;36m");
}
void reset() {
    printf("\033[0m");
}
void showingStatistics(char *file, int type) {
    //printf("Showing statistics\n");
    if (type == 1) printf("    DATE    | KM | TIME ");
    if (type == 2) printf("    DATE    | WEIGHT | REPS ");
    if (type == 3) printf("    DATE    | TIME ");
    
    printf("\n-----------------------------\n");
    FILE *f = fopen(file, "r");
    if (f == NULL) {
        printf("Error opening file\n");
        return;
    }
    struct activity a;
    while (fscanf(f, "%s", a.date) != EOF) {
        red();
        printf("%s", a.date);
        reset();
        if(type == 1) {
            fscanf(f, "%f", &a.km);
            fscanf(f, "%f", &a.time);
            printf(" | ");
            green();
            printf("%.2f", a.km);
            reset();
            printf(" km | ");
            cyan();
            printf("%.2f", a.time);
            reset();
            printf(" h");
        } else if(type == 2) {
            fscanf(f, "%f", &a.weight);
            fscanf(f, "%d", &a.reps);
            printf(" | ");
            green();
            printf("%.2f", a.weight);
            reset();
            printf(" kg | ");
            cyan();
            printf("%d", a.reps);
            reset();
            printf(" reps");
        } else if(type == 3) {
            fscanf(f, "%f", &a.time);
            printf(" | ");
            cyan();
            printf("%.2f", a.time);
            reset();
            printf(" h");
        }
        reset();
        printf("\n");
    }
    char date[20];

    fclose(f);
    printf("\n-----------------------------\n");
}

void savingProgress(char *fileName) {
    printf("Saving progress\n");
    char date[20];
    FILE *f = fopen(fileName, "a");
    if (f == NULL) {
        printf("Error opening file\n");
        return;
    }
    printf("Enter DATE (dd.mm.yyyy): ");
    scanf("%s", date);
    fprintf(f, "%s\n", date);
    if (fileName == "./data/swim.txt" || fileName == "./data/walk.txt" || fileName == "./data/cycle.txt") {
        float km, time;
        printf("Enter KM: ");
        scanf("%f", &km);
        printf("Enter TIME (in minutes): ");
        scanf("%f", &time);
        fprintf(f, "%.2f\n%.2f\n", km, time);
    } else if (fileName == "./data/strength.txt") {
        float weight;
        int reps;
        printf("Enter WEIGHT: ");
        scanf("%f", &weight);
        printf("Enter REPS (repetitions): ");
        scanf("%d", &reps);
        fprintf(f, "%.2f\n%d\n", weight, reps);
    } else if (fileName == "./data/stretching.txt") {
        float time;
        printf("Enter TIME (in minutes): ");
        scanf("%f", &time);
        fprintf(f, "%.2f\n", time);
    }
    fclose(f);
    printf("Progress saved\n");
}

void swimApp() {
    while (1) {
        printf("---SWIMMING---\n");
        printf("1.STATISTICS\n");
        printf("2.ENTER PROGRESS [DATE, KM, TIME]\n");
        printf("3.EXIT\n");
        char option;
        scanf(" %c", &option);
        printf("\e[1;1H\e[2J");
        switch(option) {
            case '1':
                showingStatistics("./data/swim.txt", 1);
                break;
            case '2':
                savingProgress("./data/swim.txt");
                break;
            case '3':
                return;
            default:
                // printf("Invalid option\n");
                // scanf("%*s");
                break;
        }
    }
}


void walkApp() {
    while (1) {
        printf("---WALKING---\n");
        printf("1.STATISTICS\n");
        printf("2.ENTER PROGRESS [DATE, KM, TIME]\n");
        printf("3.EXIT\n");
        char option;
        scanf(" %c", &option);
        printf("\e[1;1H\e[2J");
        switch(option) {
            case '1':
                showingStatistics("./data/walk.txt", 1);
                break;
            case '2':
                savingProgress("./data/walk.txt");
                break;
            case '3':
                return;
            default:
                // printf("Invalid option\n");
                // scanf("%*s");                
                break;
        }
    }
}

void cycleApp() {
    while (1) {
        printf("---CYCLING---\n");
        printf("1.STATISTICS\n");
        printf("2.ENTER PROGRESS [DATE, KM, TIME]\n");
        printf("3.EXIT\n");
        char option;
        scanf(" %c", &option);
        printf("\e[1;1H\e[2J");
        switch(option) {
            case '1':
                showingStatistics("./data/cycle.txt", 1);
                break;
            case '2':
                savingProgress("./data/cycle.txt");
                break;
            case '3':
                return;
            default:
                // printf("Invalid option\n");
                // scanf("%*s");
                break;
        }
    }
}

void strengthApp() {
    while (1) {
        printf("---STRENGTH---\n");
        printf("1.STATISTICS\n");
        printf("2.ENTER PROGRESS [DATE, WEIGHT, REPS]\n");
        printf("3.EXIT\n");
        char option;
        scanf(" %c", &option);
        printf("\e[1;1H\e[2J");
        
        switch(option) {
            case '1':
                showingStatistics("./data/strength.txt", 2);
                break;
            case '2':
                savingProgress("./data/strength.txt");
                break;
            case '3':
                return;
            default:
                // printf("Invalid option\n");
                // scanf("%*s");
                break;
        }
    }
}

void stretchingApp() {
    while (1) {
        printf("---STRETCHING---\n");
        printf("1.STATISTICS\n");
        printf("2.ENTER PROGRESS [DATE, TIME]\n");
        printf("3.EXIT\n");
        char option;
        scanf(" %c", &option);
        printf("\e[1;1H\e[2J");

        switch(option) {
            case '1':
                showingStatistics("./data/stretching.txt", 3);
                break;
            case '2':
                savingProgress("./data/stretching.txt");
                break;
            case '3':
                return;
            default:
                // printf("Invalid option\n");
                // scanf("%*s");
                break;
        }
    }
}




void run() {
    while(1) {
        printf("\e[1;1H\e[2J");
        printf("---APLICATIE SPORTIVA---\n");
        printf("1.SWIMMING\n");
        printf("2.WALKING\n");
        printf("3.CYCLING\n");
        printf("4.SRENGTH\n");
        printf("5.STRETCHING\n");
        printf("6.EXIT\n");

        char option;
        printf("Choose an option: ");
        scanf(" %c", &option);
        printf("\e[1;1H\e[2J");
        switch(option) {
            case '1':
                swimApp();
                break;
            case '2':
                walkApp();
                break;
            case '3':
                cycleApp();
                break;
            case '4':
                strengthApp();
                break;
            case '5':
                stretchingApp();
                break;
            case '6':
                return;
                break;
            default:
                // printf("Invalid option\nEnter any key to continue\n");
                // scanf("%*s");
                break;
        }
        
    }
}

int main() {
    run();
    return 0;
}