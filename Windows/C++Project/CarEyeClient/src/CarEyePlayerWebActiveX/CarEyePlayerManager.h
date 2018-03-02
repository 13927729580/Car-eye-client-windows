

#pragma once

#include "../libCarEyePlayer/libCarEyePlayerAPI.h"

#pragma comment(lib,"../libCarEyePlayer/libCarEyePlayer.lib")


//Gavin's Source Struct����Ϣ�ṹ
typedef struct __CarEye_LOCAL_SOURCE_T
{	
	int		rtspSourceId;
	void*	pusherHandle;

	char	pushServerAddr[128];
	int		pushServerPort;
	char	sdpName[64];
	void* pMaster;
}CarEye_LOCAL_SOURCE_T;

class CarEyePlayerManager
{
public:
	CarEyePlayerManager(void);
	~CarEyePlayerManager(void);

	//Member Function
public:
	//��ʼ��
	static int Init()
	{
		return CarEyePlayer_Init();
	}

	// �ͷ�
	static void UnInit()
	{
		CarEyePlayer_Release();
	}

	//����
	int Start(char* szURL, HWND hShowWnd, RENDER_FORMAT eRenderFormat, int rtpovertcp, const char *username, const char *password, int bHardDecode, MediaSourceCallBack callback=NULL, void *userPtr=NULL) ;
	//���ò���
	void Config(int nFrameCache,  BOOL bPlaySound, BOOL bShowToScale = TRUE, BOOL  bShowStatisticInfo = FALSE);
	//�ر���
	void	Close();
	void SetOSD(int show, CAREYE_PALYER_OSD osd);
	int InRunning();

	//Member Var
private:
	//���յ�����Ϣ
	CarEye_LOCAL_SOURCE_T		m_sSourceInfo;

};

