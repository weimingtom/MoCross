#include "MoCmShared.h"

MO_NAMESPACE_BEGIN

//============================================================
// <T>���칲�������ʵ����</T>
//
// @return ʵ��
//============================================================
MShared::MShared(){
   MO_CLEAR(_gMemory);
}

//============================================================
// <T>�ͷŹ��������ʵ����</T>
//============================================================
MShared::~MShared(){
   MO_CLEAR(_gMemory);
}

//============================================================
// <T>�����ڴ������ɡ�</T>
//============================================================
void MShared::OnSharedLinked(){
}

//============================================================
// <T>�����ڴ��ʼ����</T>
//============================================================
void MShared::OnSharedInitialize(){
}

//============================================================
// <T>ʹ�����еĹ����ڴ档</T>
//============================================================
void MShared::OnSharedResume(){
}

//============================================================
// <T>�����ڴ��ʼ����ɡ�</T>
//============================================================
void MShared::OnSharedComplete(){
}

//============================================================
// <T>�Ƿ��Ѿ������������ڴ档</T>
//
// @return �Ƿ������
//============================================================
TBool MShared::IsSharedLinked(){
   return (NULL != _gMemory);
}

//============================================================
// <T>��ù����ڴ�ָ�롣</T>
//
// @return �ڴ�ָ��
//============================================================
TByte* MShared::SharedMemory(){
   return _gMemory;
}

//============================================================
// <T>����������ڴ档</T>
// <P>�ڴ����½���ʱ�򣬳�ʼ�������ڴ档</P>
//
// @param segment �����ڴ�
//============================================================
void MShared::SharedLink(TShareSegment segment){
   // �����ڴ�ָ��
   _gMemory = (TByte*)segment.Memory();
   // �����ڴ�
   OnSharedLink(segment);
   // �������
   OnSharedLinked();
   // ����ڴ�
   segment.Check();
   if(segment.IsCreated()){
      // �����ڴ��ʼ��
      OnSharedInitialize();
   }else{
      // �����ڴ�����
      OnSharedResume();
   }
   // �������
   OnSharedComplete();
}

//============================================================
// <T>���������ڴ档</T>
//
// @return �������
//============================================================
TBool MShared::SharedCreate(){
   // ����ڴ�
   if(NULL != _gMemory){
      MO_FATAL(TC("Shared memory is already exists."));
   }
   // ��������
   TSize capacity = SharedCapacity();
   // �����ڴ�
   TByte* pValue = MO_TYPES_ALLOC(TByte, capacity);
   TShareSegment segment(pValue, capacity, ETrue);
   SharedLink(segment);
   return ETrue;
}

//============================================================
// <T>�ͷŹ����ڴ档</T>
//
// @return �������
//============================================================
TBool MShared::SharedDestory(){
   // ����ڴ�
   if(NULL == _gMemory){
      MO_FATAL(TC("Shared memory is not exists."));
   }
   // ��������
   MO_FREE(_gMemory);
   return ETrue;
}

//============================================================
// <T>���������Ϣ��</T>
//============================================================
void MShared::DumpShared(){
}

MO_NAMESPACE_END