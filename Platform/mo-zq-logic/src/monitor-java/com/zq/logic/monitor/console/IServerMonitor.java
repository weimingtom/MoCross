package com.zq.logic.monitor.console;

//============================================================
// <T>服务监视接口。</T>
//============================================================
public interface IServerMonitor{

   //============================================================
   // <T>设置处理。</T>
   //============================================================
   void setup();

   //============================================================
   // <T>获得名称。</T>
   //
   // @return 名称
   //============================================================
   String name();

   //============================================================
   // <T>获得有效性。</T>
   //
   // @return 有效性
   //============================================================
   boolean valid();

   //============================================================
   // <T>获得间隔。</T>
   //
   // @return 间隔
   //============================================================
   int interval();

   //============================================================
   // <T>同步处理。</T>
   //
   // @return 处理结果
   //============================================================
   boolean process();

   //============================================================
   // <T>启动处理。</T>
   //============================================================
   void startup();

   //============================================================
   // <T>等待处理。</T>
   //============================================================
   void join();
}
