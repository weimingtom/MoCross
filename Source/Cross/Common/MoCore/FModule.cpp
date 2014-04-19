#include "MoCrModule.h"

MO_NAMESPACE_BEGIN

//============================================================
// <T>����Ψһ�����ʵ����</T>
//
// @return ʵ��
//============================================================
FModule::FModule(){
   _code = 0;
}

//============================================================
// <T>����Ψһ�����ʵ����</T>
//============================================================
FModule::~FModule(){
}

//============================================================
// <T>���촦����</T>
//
// @return �������
//============================================================
TResult FModule::Construct(){
   return ESuccess;
}

//============================================================
// <T>����������</T>
//
// @return �������
//============================================================
TResult FModule::Dispose(){
   return ESuccess;
}

//============================================================
// <T>����������Ϣ��</T>
//
// @param pConfig ������Ϣ
// @return �������
//============================================================
TResult FModule::OnLoadConfig(FXmlNode* pConfig){
   return ESuccess;
}

//============================================================
// <T>��ʼ��ʼ���¼���</T>
//
// @return �������
//============================================================
TResult FModule::OnInitialize(){
   return ESuccess;
}

//============================================================
// <T>���¼����¼���</T>
//
// @return �������
//============================================================
TResult FModule::OnReload(){
   return ESuccess;
}

//============================================================
// <T>����ж���¼���</T>
//
// @return �������
//============================================================
TResult FModule::OnUnload(){
   return ESuccess;
}

//============================================================
// <T>�ͷų�ʼ���¼���</T>
//
// @return �������
//============================================================
TResult FModule::OnRelease(){
   return ESuccess;
}

//============================================================
// <T>���л��¼���</T>
//
// @return �������
//============================================================
TResult FModule::OnSerialize(){
   return ESuccess;
}

//============================================================
// <T>�����л��¼���</T>
//
// @return �������
//============================================================
TResult FModule::OnUnserialize(){
   return ESuccess;
}

//============================================================
// <T>���Ψһ��������͡�</T>
//
// @return ����
//============================================================
ESingleton FModule::SingletonType(){
   return ESingleton_Manager;
}

//============================================================
// <T>���Ψһ����Ĵ��롣</T>
//
// @return ����
//============================================================
TInt FModule::Code(){
   return _code;
}

//============================================================
// <T>���Ψһ��������ơ�</T>
//
// @return ����
//============================================================
TCharC* FModule::Name(){
   return _name.MemoryC();
}

//============================================================
// <T>����������Ϣ��</T>
//
// @param pConfig ������Ϣ
// @return �������
//============================================================
TResult FModule::LoadConfig(FXmlNode* pConfig){
   return OnLoadConfig(pConfig);
}

//============================================================
// <T>�����������</T>
//
// @return �������
//============================================================
TResult FModule::Suspend(){
   return OnSerialize();
}

//============================================================
// <T>���ѹ�������</T>
//
// @return �������
//============================================================
TResult FModule::Resume(){
   return OnUnserialize();
}

//============================================================
// <T>��ʼ��������</T>
//
// @return �������
//============================================================
TResult FModule::Initialize(){
   return OnInitialize();
}

//============================================================
// <T>���¼��ش�����</T>
//
// @return �������
//============================================================
TResult FModule::Reload(){
   return OnReload();
}

//============================================================
// <T>ж�ش�����</T>
//
// @return �������
//============================================================
TResult FModule::Unload(){
   return OnUnload();
}

//============================================================
// <T>�ͷŴ�����</T>
//
// @return �������
//============================================================
TResult FModule::Release(){
   return OnRelease();
}

MO_NAMESPACE_END