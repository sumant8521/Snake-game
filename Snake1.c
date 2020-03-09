#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int width=20,height=20,gameOver;
int x,y,fruitx,fruity,score,flag;
int tailx[100],taily[100];
int counttail=0;
void Setup()
{
    gameOver=0;
    x=width/2;
    y=height/2;

    label1:
    fruitx=rand()%15;
    if(fruitx==0)
        goto label1;

    label2:
    fruity=rand()%15;
    if(fruity==0)
        goto label2;
}
void Draw()
{

    int i,j,k;
    system("CLS");
    for(i=0;i<width;i++)
    {
      for(j=0;j<height;j++)
        {
            if(i==0||i==height-1||j==0||j==width-1)
            {
                printf("*");
            }
            else
            {
                 if(i==x&&j==y)
                 printf("O");
                else if(i==fruitx&&j==fruity)
                    printf("F");
                else
                {
                    int ch=0;
                    for(k=0;k<counttail;k++)
                    {
                        if(i==tailx[k]&&j==taily[k])
                        {
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch==0)
                    printf(" ");
                }

            }

        }
        printf("\n");
    }
     printf("Score: %d",score);
}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
            flag=1;
            break;
        case 'd':
            flag=2;
            break;
        case 'w':
            flag=3;
            break;
        case 'z':
            flag=4;
            break;
        case 'v':
            gameOver=1;
            break;

        }
    }
}
void logic()
{
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;
    int i;
    for(i=1;i<counttail;i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(flag)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    default:
        break;

    }
    if(x<0||x>width||y<0||y>height)
        gameOver=1;

        for(i=0;i<counttail;i++)
        {
            if(x==tailx[i]&&y==taily[i])
                gameOver=1;
        }
        if(x==fruitx&&y==fruity)
        {
            label3:
            fruitx=rand()%15;
            if(fruitx==0)
            goto label3;

            label4:
            fruity=rand()%15;
            if(fruity==0)
            goto label4;
            score+=10;
            counttail++;
        }
}

int main()
{

    int m,n;
    char c;
    label5:
    Setup();
    while(1)
    {
        Draw();
        input();
        logic();
        //delay(1000);
        if(gameOver==1)
            break;
            for(m=0;m<1000;m++)
            {
                for(n=0;n<50000;n++)
                {

                }
            }
            for(m=0;m<1000;m++)
            {
                for(n=0;n<1000;n++)
                {

                }
            }



    }
    printf("\n press Y to continue\n");
    scanf("%c",&c);
    if(c=='y'||c=='Y')
        goto label5;

    return 0;
}
