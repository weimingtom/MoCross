#include <ft2build.h>
#include FT_FREETYPE_H 
#include <MoFeatureLogger.h>
#include <MoFeatureGraphic.h>
#include <MoEngine.h>
#include <MoEngineFace.h>
#include <MoEngineRender.h>
#include <MoPlatformOpenGLES2.h>
#include <MoPlatformWindows.h>
#include <MoPluginScriptMono.h>
#include <MoGameEngine.h>
#include "MoTestLogic.h"
#include "MpMain.h"

MO_NAMESPACE_INCLUDE;

#define MO_RESOURCE_CODE 910010001

typedef TVector<FTemplate3d*> TTemplate3dVector;
TTimeTick g_lastTick = 0;
TTimeTick g_templateTick = 0;
TTemplate3dVector g_pTemplates;

//============================================================
// <T>鼠标事件处理。</T>
//
// @param pEvent 事件
// @return 处理结果
//============================================================
TResult OnKeyDown(SKeyboardEvent* pEvent){
   if(pEvent->keyCode == EKeyCode_P){
      TBool pause = RDeviceManager::Instance().StatusPause();
      if(pause){
         RDeviceManager::Instance().Resume();
         REffectManager::Instance().Resume();
         RGameSceneManager::Instance().Resume();
      }else{
         RDeviceManager::Instance().Suspend();
         REffectManager::Instance().Suspend();
         RGameSceneManager::Instance().Suspend();
      }
   }
   return ESuccess;
}

//============================================================
// <T>鼠标事件处理。</T>
//
// @param pEvent 事件
// @return 处理结果
//============================================================
TResult OnEnterFrame(SFrameEvent* pEvent){
   // MO_STATIC_INFO("------------------------------------------------------------");
   // return ESuccess;
   TTimeTick currentTick = RTimeTick::Current();
   if(g_templateTick == 0){
      g_lastTick = currentTick;
      g_templateTick = currentTick;
      return ESuccess;
   }
   TTimeSpan span = currentTick - g_templateTick;
   TFloat rate = (TFloat)span / 1000000.0f;
   TTemplate3dVector::TIteratorC iterator = g_pTemplates.IteratorC();
   while(iterator.Next()){
      FTemplate3d* pTemplate = *iterator;
      pTemplate->MatrixModel().SetRotation(0.0f, MO_PI_FLOAT / 180.0f * 220.0f + rate * 0.7f, 0.0f);
      pTemplate->MatrixModel().UpdateForce();
   }
   // 显示统计信息
   TTimeSpan spanSecond = (currentTick - g_lastTick) / 1000000;
   if(spanSecond >= 5){
      RStatisticsManager::Instance().Track();
      RStatisticsManager::Instance().Reset();
      FRenderDevice* pRenderDevice = RDeviceManager::Instance().Find<FRenderDevice>();
      FRenderStatistics* pStatistics = pRenderDevice->Statistics();
      pStatistics->Track();
      pStatistics->Reset();
      g_lastTick = currentTick;
   }
   return ESuccess;
}

//============================================================
// <T>释放游戏库。</T>
//============================================================
TInt WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, TInt nCmdShow){
   // 初始化处理
   MoGameEngineInitialize();
   MoPluginScriptMonoInitialize();
   //............................................................
   // 设置信息
   RApplication::Instance().Parameters()->Setup(lpszCmdLine);
   RApplication::Instance().SetHinstance(hInstance);
   RApplication::Instance().SetCommandShow(nCmdShow);
   RAssetManager::Instance().Setup();
   //............................................................
   FMonoMachine* pMachine = MO_CREATE(FMonoMachine);
   pMachine->Setup();
   //............................................................
   // 创建窗口
   SIntSize2 screenSize(1200, 800);
   FRenderWindow* pWindow = MO_CREATE(FRenderWindow);
   pWindow->Size().Assign(screenSize);
   pWindow->Setup();
   // 初始化渲染设备
   FRenderDevice* pRenderDevice = RDeviceManager::Instance().Find<FRenderDevice>();
   pRenderDevice->Setup();
   // 初始化舞台
   MoGameEngineStartup();
   // 选择渲染方式
   RPipelineManager::Instance().SelectPipeline("simple");
   //RPipelineManager::Instance().SelectPipeline("shadow");
   // 注册字体
   FEoFont* pFont = FEoFont::InstanceCreate();
   pFont->CharSize().Set(14, 14);
   pFont->SetAssetName("asset:/font/DroidSansFallback.ttf");
   RFontManager::Instance().RegisterFont(pFont);
   //............................................................
   // 打开资源管理器
   RResource3dManager::Instance().ThemeConsole()->Open("asset:/theme/color.ser");
   //RResource3dManager::Instance().ThemeConsole()->Open("asset:/theme/shadow.ser");
   //RGmResourceManager::Instance().Open();
   //RGmTemplateConsole::Instance().Open();
   //............................................................
   // 注册事件
   FMouseDevice* pMouseDevice = RDeviceManager::Instance().Find<FMouseDevice>();
   FKeyboardDevice* pKeyboardDevice = RDeviceManager::Instance().Find<FKeyboardDevice>();
   pKeyboardDevice->ListenersKeyDown().Register(&OnKeyDown);
   //............................................................
   // 激活舞台
   //RInstance3dManager::Instance().TemplateConsole()->Alloc("pvw.sc.courtyard.item.02.022");
   //FGameScene* pScene = RGameSceneManager::Instance().Load("pvw.show.item.001");
   FGameScene* pScene = RGameSceneManager::Instance().Load("pvw.sc.car.01.001");
   //FGameScene* pScene = RGameSceneManager::Instance().Load("pvw.sc.car.01.002");
   //FGameScene* pScene = RGameSceneManager::Instance().Load("pvw.sc.car.01.003");
   //FGameScene* pScene = RGameSceneManager::Instance().Load("pvw.sc.house.01.scene");
   //FGameScene* pScene = RGameSceneManager::Instance().Load("pvw.show.skeleton.01");
   //FGameScene* pScene = RGameSceneManager::Instance().Load("pvw.show.skeleton.02");
   //FGameScene* pScene = RGameSceneManager::Instance().Load("pvw.show.skeleton.05");
   //FGameScene* pScene = RGameSceneManager::Instance().Load("pvw.sc.courtyard.scene");
   pScene->ListenersFrameEnter().Register(&OnEnterFrame);
   RStageManager::Instance().SelectStage(pScene);
   //............................................................
   // 处理窗口
   pWindow->Startup();
   pWindow->Process();
   //............................................................
   MoGameEngineShutdown();
   //............................................................
   // 释放处理
   MoGameEngineRelease();
	return 0;
}