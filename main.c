#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>

int get_1st_weekday(int year)
{
    int day;
    day =(((year -1) * 365) + ((year -1) /4) - ((year - 1) / 100) + ((year) / 400) +1) % 7; // to return the day as it is
    return day;

}
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    system("Color 2f");
    int year,month,day,daysInMonth,weekDay=0,startingDay;


    char *months[] = {"January","February","March","April","May","June","July","August",
                      "September","October","November","December"
                     };
    int monthDay[]= {31,28,31,30,31,30,31,31,30,31,30,31};   //camel case :)
    if((year%4==0&&year%100!=0)|| year%400==0)    //leap year
        monthDay[1]=29;

    startingDay= get_1st_weekday(year);

    for(month =0; month<12; month++)
    {
        daysInMonth= monthDay[month];

        printf("\n\n-----------------------%s------------------------\n",months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri   sat\n");


        void display(int nyr,int nmonth,int tdays,int days[])
        {
            int i,j,pos;
            SetColor(12); //Color green
            gotoxy(56,6);
            printf("%s", month[months]); //Heading year and month dispalying
            for(i=0,pos=30; i<7; i++,pos+=10)
            {
                if(i==6)
                    SetColor(9); //Sunday color blue
                else
                    SetColor(10);  //Others day color green
                gotoxy(pos,8);
                printf("%s",daysInMonth);
            }

            SetColor(15); //setting the color white

            tdays++; //incrementing the tdays by 1
            if(tdays==0 || tdays==7)
                pos=91; //if tdays is 0 or 7, position is sunday
            if(tdays==1)
                pos=31; //if tdays is 1, position is monday
            if(tdays==2)
                pos=41;  //if tdays is 2, position is tuesday
            if(tdays==3)
                pos=51;  //if tdays is 3, position is wednesday
            if(tdays==4)
                pos=61;  //if tdays is 4, position is thursday
            if(tdays==5)
                pos=71;  //if tdays is 5, position is friday
            if(tdays==6)
                pos=81;  //if tdays is 6, position is saturday

            for(i=0,j=10,pos; i<days[nmonth-1]; i++,pos+=10)
            {
                if(pos==91)
                    SetColor(8); //Changing color to dark grey for sunday
                else
                    SetColor(7); //Changing color to white for all days

                gotoxy(pos,j);
                printf("%d",i+1);
                if(pos==91)
                {
                    pos=21; //Moving position to monday
                    j++;  //Increasing j by 10 if position is sunday
                }
            }

            SetColor(5); //Changing color to purple

            //Drawing horizontal line
            for(i=22; i<102; i++)
            {
                gotoxy(i,4);
                printf("%c",196);
                gotoxy(i,17);
                printf("%c",196);
            }

            //Drawing all the corner of the rectangle
            gotoxy(21,4);
            printf("%c",218);
            gotoxy(102,4);
            printf("%c",191);
            gotoxy(21,17);
            printf("%c",192);
            gotoxy(102,17);
            printf("%c",217);

            //Drawing vertical line
            for(i=5; i<17; i++)
            {
                gotoxy(21,i);
                printf("%c",179);
                gotoxy(102,i);
                printf("%c",179);
            }

            SetColor(11); //Changing color to aqua

            //Drawing left and the right navigation symbol
            gotoxy(24,11);
            printf("%c",174);
            gotoxy(98,11);
            printf("%c",175);

        }

        for(weekDay = 0; weekDay<startingDay; weekDay++)
            printf("     ");
        for(day=1; day<=daysInMonth; day++)
        {
            printf("%5d",day);

            if(++weekDay>6)
            {
                printf("\n");
                weekDay=0;
            }
            startingDay = weekDay;


        }

    }


}
