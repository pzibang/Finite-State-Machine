#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void stopPlayer();
void pausePlayer();
void resumePlayer();
void startPlayer();

//�����Ķ�������
typedef enum {
    EV_STOP,
    EV_PLAY_PAUSE
}EventCode;

//MP3��״̬
enum {
    ST_IDLE,
    ST_PLAY,
    ST_PAUSE
};

//MP3��ǰ״̬
char state;

//MP3״̬��ʼ��
void init(){
    //ʹMP3�ڿ���״̬
    state = ST_IDLE;
}

//�������ܣ� ״̬������MP3�Ĺ��̱仯
//����˵���� EventCode ec����������
void onEvent(EventCode ec){
    //��ͬ�İ������������ֲ�ͬ��״̬��Ӧ�Ĵ���
    switch (state)
    {
        //����״̬
        case ST_IDLE:
            if (EV_PLAY_PAUSE == ec) {
                startPlayer();
            }            
            break;
        //����״̬
        case ST_PLAY:
            if (EV_STOP == ec) {
                stopPlayer();
            }
            else if (EV_PLAY_PAUSE == ec) {
                pausePlayer();
            }
            break;
        //��ͣ״̬
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
    printf("ֹͣ��������\n");
}

void pausePlayer(){
    state = ST_PAUSE;
    printf("��ͣ��������\n");
}

void resumePlayer(){
    state = ST_PLAY;
    printf("�ָ���������\n");
}

void startPlayer(){
    state = ST_PLAY;
    printf("��ʼ��������\n");
}

//������ʵ��MP3�Ĳ��ſ���
int main(void){
    init();

    //�ڿ���״̬����EV_PLAY_PAUSE����ɲ���״̬
    onEvent(EV_PLAY_PAUSE);

    //�ڲ���״̬����EV_PLAY_PAUSE�������ͣ״̬
    onEvent(EV_PLAY_PAUSE);

    //����ͣ״̬����EV_PLAY_PAUSE����ɲ���״̬
    onEvent(EV_PLAY_PAUSE);

    //����EV_STOP�����ֹͣ״̬
    onEvent(EV_STOP);      

    return 0;
}
