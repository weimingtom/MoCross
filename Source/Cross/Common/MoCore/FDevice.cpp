#include "MoCrDevice.h"

MO_NAMESPACE_BEGIN

MO_CLASS_IMPLEMENT_INHERITS(FDevice, FInstance);

//============================================================
// <T>��������豸��</T>
//============================================================
FDevice::FDevice(){
}

//============================================================
// <T>��������豸��</T>
//============================================================
FDevice::~FDevice(){
}

//============================================================
// <T>���ô�����</T>
//
// @return �������
//============================================================
TResult FDevice::Setup(){
   return ESuccess;
}

//============================================================
// <T>��ͣ������</T>
//
// @return �������
//============================================================
TResult FDevice::Suspend(){
   return ESuccess;
}

//============================================================
// <T>����������</T>
//
// @return �������
//============================================================
TResult FDevice::Resume(){
   return ESuccess;
}

MO_NAMESPACE_END