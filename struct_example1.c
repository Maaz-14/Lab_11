#include<stdio.h>
#include<string.h>
struct player{
    char name[50];
    int score;
};

struct batsman{
    char style[50];
    int highest_score;
    struct player p;

}batsman1,batsman2;
int main(){
    strcpy(batsman1.p.name,"Babar Azam");
    batsman1.p.score= 150;
    strcpy(batsman1.style,"Right hand batsman");
    batsman1.highest_score=175;

    str
}
// #include <stdio.h>
// #include <string.h>

// struct batsman {
//     char name[50];
//     int score;
//     char style[50];
//     int highest_score;
// };

// struct bowler {
//     char name[50];
//     int wicket;
//     char style[50];
//     int record;
// };

// int main() {
//     struct batsman batsman1, batsman2;
//     struct bowler bowler1, bowler2;

//     strcpy(batsman1.name, "Babar Azam");
//     batsman1.score = 150;
//     strcpy(batsman1.style, "Right Hand Batsman");
//     batsman1.highest_score = 175;

//     strcpy(batsman2.name, "Muhammad Rizwan");
//     batsman2.score = 160;
//     strcpy(batsman2.style, "Right Hand Batsman");
//     batsman2.highest_score = 165;

//     strcpy(bowler1.name, "Shaheen Afridi");
//     bowler1.wicket = 5;
//     strcpy(bowler1.style, "Left Arm Bowler");
//     bowler1.record = 500;

//     strcpy(bowler2.name, "Shahid Afridi");
//     bowler2.wicket = 7;
//     strcpy(bowler2.style, "Right Arm Bowler");
//     bowler2.record = 550;

//     printf("Batsman 1:\n");
//     printf("Name: %s\n", batsman1.name);
//     printf("Score: %d\n", batsman1.score);
//     printf("Style: %s\n", batsman1.style);
//     printf("Highest Score: %d\n\n", batsman1.highest_score);

//     printf("Batsman 2:\n");
//     printf("Name: %s\n", batsman2.name);
//     printf("Score: %d\n", batsman2.score);
//     printf("Style: %s\n", batsman2.style);
//     printf("Highest Score: %d\n\n", batsman2.highest_score);

//     printf("Bowler 1:\n");
//     printf("Name: %s\n", bowler1.name);
//     printf("Wickets in Match: %d\n", bowler1.wicket);
//     printf("Style: %s\n", bowler1.style);
//     printf("Total Wickets: %d\n\n", bowler1.record);

//     printf("Bowler 2:\n");
//     printf("Name: %s\n", bowler2.name);
//     printf("Wickets in Match: %d\n", bowler2.wicket);
//     printf("Style: %s\n", bowler2.style);
//     printf("Total Wickets: %d\n", bowler2.record);

//     return 0;
// }
