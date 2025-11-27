    #include <stdio.h>   //printf,scanf를 사용하기 위해서 해더추가
    #include <stdlib.h>  //rand, srand를 사용하기 위해서 해더 추가
    #include <time.h>    //time 함수를 사용하기 위해서 해더 추가

    int main(void) //프로그램을 실행하는 main함수
    {              //메인 함수의 시작
        int ball[3];   //3개의 난수 저장 배열
        srand(time(NULL));  //난수를 초기화하고 현제 시간을 기준으로 시드를 설정한다.

        do { //do~while 동일한 코드를 특정 조건일때 반복하고 싶다->중복되지 않는 3개의 난수 생성
            ball[0] = rand() % 9+1;    //1~9 사이에 난수 생성
            ball[1] = rand() % 9+1;
            ball[2] = rand() % 9+1;
        } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]);  //중복검사 0,1,2에 나온숫자가 0=1이거나 1=2이거나 ,2=0,일때 다시 반복한다
        printf("===숫자 야구 게임을 시작~~~하겠습니다!!===\n");

        //printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]);//숫자가 안보이게 하기 위하여 주석처리

        //3개의 숫자를 입력
        int input[3];  //사용자가 입력한 숫자를 저장 인트에 바구니 3개!
        int strike_count ,ball_count,out_count;   //스트라이크!볼!아웃!이라는걸 만듬

        while(1) //게임 반복 루프이며 홈런이 나올때 까지 반복
    {
        do {  //이럴땐 다시 반복할꺼에요

        printf("Enter the first number: ");
        scanf("%d", &input[0]);

        printf("Enter the second number: ");
        scanf("%d", &input[1]);

        printf("Enter the third number: ");
        scanf("%d", &input[2]);           //1,2,3입력했을때!

         if(input[0] < 1 || input[0] > 9 ||   
            input[1] < 1 || input[1] > 9 ||
            input[2] < 1 || input[2] > 9 ||
            input[0] == input[1] || input[0] == input[2] || input[1] == input[2])// 만약 입력한 값 0.1.2.범위가 1~9가 아니거나! 중복이 되는 경우면! (아까 do로 가서 다시 반복할 꺼에요!)
        {
        printf("잘못된 입력값이나 중복입력값이 있습니다. 다시 입력해주세요!\n");
        }
        else
        {
            break;  //유효한 값이니 반복을 종료합니다!
        }
    }while (1); 
    

        printf("input : %d %d %d\n", input[0], input[1], input[2]) ;  //내가 입력한 숫자!

        strike_count = 0;
        ball_count = 0 ;
        out_count = 3 ;      //왜 int가 빠졌나요?(매우중요):위에서 이미 int라는 바구니를 만들었으니(변수선언) 그대로 두고 처음값을 지정(값을 초기화)하는 거에요! 

        if( ball[0] == input[0] )       // strike count
        {
            strike_count = strike_count + 1 ; //스트라이크 +1
            out_count = out_count - 1 ;  //아웃 카운트 +1
        }
        if( ball[0] == input[1] )     // ball count
        {
            ball_count = ball_count + 1 ;  //볼카운트 +1 ---->나머지도 반복됩니다!
            out_count = out_count - 1 ;
        }
        if( ball[0] ==  input[2] )     // ball count
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[1] == input[0] ) // ball count
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[1] == input[1] )      // strike count
        {
            strike_count = strike_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[1] ==  input[2] ) // ball count
        {
            ball_count = ball_count + 1;
            out_count = out_count - 1 ;
        }
        if( ball[2] == input[0] ) // ball count
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[2] == input[1] ) // ball count
        { 
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
         if( ball[2] ==  input[2] )      // strike count
        { 
            strike_count = strike_count + 1 ;
            out_count = out_count - 1 ;
        }



        if( strike_count == 3)  //결과출력:만약 스트라이크가 3개라면?
        {
            printf("Home Run~\n") ;  //홈런~출력!
            break; //반복 종료!
        }
        else  //아니라면?
        {
            printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count) ; //스트라이크, 볼 ,아웃 개수 표기한다!
        }
    }
        return 0; //프로그램 종료!
    }