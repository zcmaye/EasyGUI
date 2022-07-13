#pragma once
#include"Configer.h"
class SElapsedTimer
{
public:
	SElapsedTimer();

	void start();		//��ʼ
	void reStart();		//�ؿ�
	void stop();		//ֹͣ
	void pause();		//��ͣ
	void resume();		//��֮ͣ��ָ�

	uint32  elapsed();	//������SElapsedTimer�ϴ����������ĺ����� 
	bool isStarted();	//�Ƿ�������
	bool isPaused();	//�Ƿ���ͣ��
private:
	uint32 m_startTicks;	//��ʱ����ʼʱ��ʱ��ʱ��
	uint32 m_pausedTicks;	//��ʱ��ͣʱ�洢��ʱ��
	
	bool m_paused;			//�Ƿ���ͣ��
	bool m_started;			//�Ƿ�ʼ��
};

