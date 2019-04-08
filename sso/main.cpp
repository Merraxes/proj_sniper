#include "Functions.h"
#include "Sniper.h"
#include "Soldier.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define HIT_INTERVAL 1000000

using namespace std;

int main(int argc, char const *argv[])
{
    srand(argc == 2
        ? atoi(argv[1])
        : time(NULL));


    Sniper Simo;
    int n=N;
    Soldier soldiers[n];

    printf("%s\n\t", Simo.description().c_str());


    //Tura Simo

    bool detected = false;
    bool dead = false;
    int weather_parameter=test();


    do{

        weather_parameter=weather(weather_parameter);
        weather_desription(weather_parameter/10);

        bool found = false;
        if (detected==false){

            found=true;
            printf("%s\n\t","Simo skanuje otoczenie..." );

            for (int i=0; i<n; i++){

                if (Simo.scan(soldiers[i].camouflage()+weather_parameter/10)){
                    printf("%s\n\t","Simo wykrył przeciwnika..." );

                    //oddawanie strzału
                    printf("%s\n\t","Simo oddaje strzał w przeciwnika..." );
                    i=N;

                    if(Simo.shot(weather_parameter/10)){
                        printf("%s\n\t","Trafiony, przeciwnik unieszkodliwiony..." );
                        --n;
                        printf("%s %d\n\t","Liczba pozostalych przeciwnikow: ",n);


                    }

                    else printf("%s\n\t","Spudłował...." );
                }
            }

            if (found==0) printf("%s\n\t","Simo nie zlokalizował celu..." );
        }
        else{
              Simo.move();
              printf("%s\n\t","Simo sie przemieszcza...." );
            }


    // tura wrogich jednostek
      bool found_2=false;
      if (n==0) break;
      for (int i=0; i<n; i++){
            if (soldiers[i].scan(Simo.camouflage()+weather_parameter/10)) {
                detected=true;
                if (found_2==0){
                     found_2=true;
                     printf("%s\n\t","Simo zostal zlokalizowany" );}

                if (soldiers[i].shot(weather_parameter/10)){
                    int dmg = Simo.demage();
                    printf("%s %d %s %d\n\t", "Simo został trafiony za", dmg, "zostalo mu ", Simo.hp()  );

                    if (Simo.hp()<=0){
                        printf("%s\n\t","Simo nie żyje, koniec gry" );
                        dead=true;
                        break;}
                }
                else printf("%s\n\t","Wrog spudlowal..." );

            }
        }

        if (dead) break;
        if (found_2==0){
            printf("%s\n\t" ,"Simo nie został zlokalizowany ..." );
            detected=false;
            for (int i=0; i<n; i++) soldiers[i].move();
            printf("%s\n\t","wrogie jednostki sie przemieszczaja...." );
        }
   }while(n>0);

}
