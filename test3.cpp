#include <stdio.h>      //ㅐPRINTF, scanf를 사용하기 위해서 헤더 추가
#include <stdlib.h>    // rand, srand를 사용하기 위해서 헤더 추가
#include <time.h>   // time 함수를 사용하기 위해서 헤더 추가

int main(void)      //프로그램을 실행하는 main 함수
{                   //메인함수의 시작
    int ball[3]; // 3개의 난수 저장 배열
    srand(time(NULL)); // 난수 초기화
    // 중복 없는 3자리 난수 생성
    do {//do~while 동일한 코드를 특정 조건일때 반복하고 싶다->중복되지 않는 3개의 난수 생성
        ball[0] = rand() % 10;  // 0~9 중 첫 번째 숫자 생성
        ball[1] = rand() % 10;  // 0~9 중 두 번째 숫자 생성
        ball[2] = rand() % 10;// 0~9 중 세 번째 숫자 생성
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]);// 세 숫자 중 하나라도 중복되면 다시 난수 생성

    //printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]); // 정답 확인용(테스트시만)

    int input[3];// 사용자가 입력할 숫자 3개 저장 배열
    int strike_count = 0 ;  // Strike 개수 저장 변수
    int ball_count = 0 ;   // Ball 개수 저장 변수
    int out_count = 0; // Out 개수 저장 변수
    int try_count = 0; // 몇 번 시도했는지 저장 변수

    clock_t start, end;// 게임 시간 측정용 변수
    start = clock(); // 게임 시작 시간 기록

    // 정답을 맞출 때까지 무한 반복
    while (1) {//일때
        printf("\n숫자 3개를 입력하세요 (공백으로 구분): ");//"숫자 3개를 입력해 주세요"터미널에 출력
         //전에는 scanf("%d", &input[0]);같이 하나하나 노가다 하였다    
        scanf("%d %d %d", &input[0], &input[1], &input[2]); //사용자에게 숫자 3개를 입력 받을꺼에요
       

            strike_count = 0; // 새 턴 시작 → strike 초기화
            ball_count = 0; // 새 턴 시작 → ball 초기화

        // strike, ball 판정    
        for (int i = 0; i < 3; i++) {//i는 0으로 초기화하고 3미만일때 까지 (0-1-2 3번 도는동안)
            //i=0
            if (input[i] == ball[i])//i0,1,2
            {
                strike_count++;// 숫자와 위치가 모두 일치하면 strike 증가
            } 
            else if (input[i] == ball[(i+1)%3] || input[i] == ball[(i+2)%3])//i=1일때 2나누기 3이면 나머지는 2 3나누기 3은 나머지 0 i=2,i=3일때도 반복
             {
                ball_count++;   // 숫자는 일치하지만 위치는 다르면 ball 증가
            }
        }

        out_count = 3 - (strike_count + ball_count);//아웃카운트=3-스트라이크 횟수 +볼 횟수
        
        try_count++;//트라이 횟수 +1

        if (strike_count == 3) {//스트라이크가 3개이면
            end = clock(); // 게임 종료 시간 기록            
            double elapsed_sec = (double)(end - start) / CLOCKS_PER_SEC; // 걸린 시간(초) 계산
            printf("Home Run! %d번 만에 맞췄습니다!\n", try_count);                                         
            // 성공 시도 횟수 출력

            printf("%f 초 시간이 걸렸습니다.\n", elapsed_sec);// 걸린 시간 출력
            break; // 게임 종료
        } else {//아닐때
            printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count); //스트라이크, 볼 ,아웃 개수 표기한다!
        }
    }
    return 0;//프로그램 종료!
}
