#include "MoCmClassBase.h"

MO_NAMESPACE_BEGIN

//============================================================
// <T>����ʵ���๤����</T>
//============================================================
FClassInstanceFactory::FClassInstanceFactory(){
   _pClasses = MO_CREATE(FClassDictionary);
   _pInstances = MO_CREATE(FInstanceDictionary);
}

//============================================================
// <T>����ʵ���๤����</T>
//============================================================
FClassInstanceFactory::~FClassInstanceFactory(){
   MO_DELETE(_pClasses);
   MO_DELETE(_pInstances);
}

//============================================================
// <T>ע��һ�������</T>
//
// @param pName ����
// @param pClass �����
// @return �������
//============================================================
TResult FClassInstanceFactory::Register(TCharC* pName, FClass* pClass){
   MO_ASSERT(pName);
   MO_ASSERT(pClass);
   _pClasses->Set(pName, pClass);
   return ESuccess;
}

//============================================================
// <T>ע��һ�������</T>
//
// @param pName ����
// @return �������
//============================================================
TResult FClassInstanceFactory::Unregister(TCharC* pName){
   MO_ASSERT(pName);
   _pClasses->Remove(pName);
   return ESuccess;
}

//============================================================
// <T>����һ��ʵ����</T>
//
// @param pName ����
// @return ʵ��
//============================================================
FInstance* FClassInstanceFactory::Find(TCharC* pName){
   MO_ASSERT(pName);
   FInstance* pInstance = _pInstances->Find(pName);
   if(pInstance == NULL){
      FClass* pClass = _pClasses->Find(pName);
      if(pClass != NULL){
         pInstance = pClass->InstanceCreate();
      }
   }
   return pInstance;
}

//============================================================
// <T>�ռ�һ��ʵ����</T>
//
// @param pName ����
// @return ʵ��
//============================================================
FInstance* FClassInstanceFactory::Get(TCharC* pName){
   MO_ASSERT(pName);
   FInstance* pInstance = _pInstances->Find(pName);
   if(pInstance == NULL){
      FClass* pClass = _pClasses->Get(pName);
      pInstance = pClass->InstanceCreate();
      _pInstances->Set(pName, pInstance);
   }
   return pInstance;
}

//============================================================
// <T>���������ͷ�һ��ʵ����</T>
//
// @param pName ����
//============================================================
void FClassInstanceFactory::Free(TCharC* pName){
   MO_ASSERT(pName);
   FInstance* pInstance = _pInstances->Find(pName);
   if(pInstance != NULL){
      _pInstances->Remove(pName);
      MO_DELETE(pInstance);
   }
}

//============================================================
// <T>���������Ϣ��</T>
//
// @param pDump ��������
// @param capacity ����
// @return ������Ϣ
//============================================================
TCharC* FClassInstanceFactory::Dump(TChar* pDump, TInt capacity){
   MO_ASSERT(pDump);
   MO_ASSERT(capacity > 0);
   TStringRefer dump(pDump, capacity);
   dump.AppendFormat(TC("count=%d, instance=%d"), _pClasses->Count(), _pInstances->Count());
   return pDump;
}

MO_NAMESPACE_END