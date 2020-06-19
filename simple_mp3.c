#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void stopPlayer();
void pausePlayer();
void resumePlayer();
void startPlayer();

//按键的动作类型
typedef enum {
    EV_STOP,
    EV_PLAY_PAUSE
}EventCode;

//MP3的状态
enum {
    ST_IDLE,
    ST_PLAY,
    ST_PAUSE
};

//MP3当前状态
char state;

//MP3状态初始化
void init(){
    //使MP3在空闲状态
    state = ST_IDLE;
}

//函数功能： 状态机处理MP3的过程变化
//参数说明： EventCode ec：按键操作
void onEvent(EventCode ec){
    //不同的按键操作在三种不同的状态对应的处理
    switch (state)
    {
        //空闲状态
        case ST_IDLE:
            if (EV_PLAY_PAUSE == ec) {
                startPlayer();
            }            
            break;
        //播放状态
        case ST_PLAY:
            if (EV_STOP == ec) {
                stopPlayer();
            }
            else if (EV_PLAY_PAUSE == ec) {
                pausePlayer();
            }
            break;
        //暂停状态
        case ST_PAUSE:
            if (EV_STOP == ec) {
                stopPlayer();
            }
            else if (EV_PLAY_PAUSE == ec) {
                resumePlayer();
            }
            break;
        default:
            break;
    }
}

void stopPlayer(){
    state = ST_IDLE;
    printf("停止播放音乐\n");
}

void pausePlayer(){
    state = ST_PAUSE;
    printf("暂停播放音乐\n");
}

void resumePlayer(){
    state = ST_PLAY;
    printf("恢复播放音乐\n");
}

void startPlayer(){
    state = ST_PLAY;
    printf("开始播放音乐\n");
}

//主程序实现MP3的播放控制
int main(void){
    init();

    //在空闲状态输入EV_PLAY_PAUSE，变成播放状态
    onEvent(EV_PLAY_PAUSE);

    //在播放状态输入EV_PLAY_PAUSE，变成暂停状态
    onEvent(EV_PLAY_PAUSE);

    //在暂停状态输入EV_PLAY_PAUSE，变成播放状态
    onEvent(EV_PLAY_PAUSE);

    //输入EV_STOP，变成停止状态
    onEvent(EV_STOP);      

    return 0;
}
