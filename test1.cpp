    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    int main(void) 
    {
        int ball[3];
        srand(time(NULL));

        do {
            ball[0] = rand() % 9+1;
            ball[1] = rand() % 9+1;
            ball[2] = rand() % 9+1;
        } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]);
        printf("===숫자 야구 게임을 시작~~~하겠습니다!!===");

        //printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]);//숫자가 안보이게 하기 위하여 주석처리

        //3개의 숫자를 입력
        int input[3];
        int strike_count ,ball_count,out_count;

        while(1)
    {
        while(1)
        {
        printf("Enter the first number: ");
        scanf("%d", &input[0]);

        printf("Enter the second number: ");
        scanf("%d", &input[1]);

        printf("Enter the third number: ");
        scanf("%d", &input[2]);

        if(input[0] < 1 || input[0] > 9 ||
           input[1] < 1 || input[1] > 9 ||
           input[2] < 1 || input[2] > 9 )
           {
            printf("1과 9 사이의 숫자만 입력 가능합니다..\n");
            continue;
           }
           if(input[0] == input[1] || input[1] == input[2] || input[2] == input[0] )
           {
            printf("같은 숫자는 입력이 불가능 합니다 \n");
            continue;
           }
           break;
        }
        printf("input : %d %d %d\n", input[0], input[1], input[2]) ;

        strike_count = 0;
        ball_count = 0 ;
        out_count = 3 ;

        if( ball[0] == input[0] )       // strike count
        {
            strike_count = strike_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[0] == input[1] )     // ball count
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[0] ==  input[2] )     // ball count
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[1] == input[0] )
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[1] == input[1] )
        {
            strike_count = strike_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[1] ==  input[2] )
        {
            ball_count = ball_count + 1;
            out_count = out_count - 1 ;
        }
        if( ball[2] == input[0] )
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[2] == input[1] )
        { 
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
         if( ball[2] ==  input[2] )
        { 
            strike_count = strike_count + 1 ;
            out_count = out_count - 1 ;
        }



        if( strike_count == 3)
        {
            printf("Home Run~\n") ;
            break;
        }
        else
        {
            printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count) ;
        }
    }
        return 0;
    }

        