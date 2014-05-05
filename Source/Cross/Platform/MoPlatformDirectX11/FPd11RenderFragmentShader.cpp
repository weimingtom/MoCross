#include "MoPd11Render.h"

MO_NAMESPACE_BEGIN

MO_CLASS_IMPLEMENT_INHERITS(FPd11RenderFragmentShader, FRenderFragmentShader);

//============================================================
// <T>������Ⱦ����</T>
//============================================================
FPd11RenderFragmentShader::FPd11RenderFragmentShader(){
   MO_CLEAR(_piData);
   MO_CLEAR(_piShader);
}

//============================================================
// <T>������Ⱦ����</T>
//============================================================
FPd11RenderFragmentShader::~FPd11RenderFragmentShader(){
   MO_RELEASE(_piData);
   MO_RELEASE(_piShader);
}

//============================================================
// <T>���ô�����</T>
//
// @return �������
//============================================================
TResult FPd11RenderFragmentShader::Setup(){
   //_renderId.uint32 = glCreateShader(GL_FRAGMENT_SHADER);
   //TResult resultCd = _pDevice->CheckError("glCreateShader", "Create fragment shader failure. (shader_id=%d)", _renderId.uint32);
   //return resultCd;
   return ESuccess;
}

//============================================================
// <T>���봦����</T>
//
// @param pSource �����ַ���
// @return �������
//============================================================
TResult FPd11RenderFragmentShader::Compile(TCharC* pSource){
   // ����豸��Ϣ
   MO_CHECK(_pDevice, return ENull);
   FPd11RenderDevice* pRenderDevice = _pDevice->Convert<FPd11RenderDevice>();
   FRenderCapability* pCapability = pRenderDevice->Capability();
   TCharC* pShaderVersion = pCapability->ShaderFragmentVersion();
   // �ϴ�����
   TInt length = RString::Length(pSource);
   ID3D10Blob* piError = NULL;
   HRESULT shaderResult = S_OK;
   HRESULT dxResult = D3DX11CompileFromMemory(pSource, length, NULL, NULL, NULL, "main", pShaderVersion, 0, 0, NULL, &_piData, &piError, &shaderResult);
   if(FAILED(dxResult) || FAILED(shaderResult)){
      TCharC* pBuffer = (TCharC*)piError->GetBufferPointer();
      MO_ERROR("Compile from memory failure.\n%s", pBuffer);
      MO_RELEASE(piError);
      MO_FATAL("Compile failure.");
      return EFailure;
   }
   // ������Ⱦ��
   TAny* pData = _piData->GetBufferPointer();
   TInt dataSize = _piData->GetBufferSize();
   dxResult = pRenderDevice->NativeDevice()->CreatePixelShader(pData, dataSize, NULL, &_piShader);
   if(FAILED(dxResult)){
      MO_FATAL("Create fragment shader failure.");
      return EFailure;
   }
   MO_INFO("Create fragment shader success. (status=%d)\n%s", dxResult, pSource);
   return ESuccess;
}

//============================================================
// <T>��������</T>
//
// @return �������
//============================================================
TResult FPd11RenderFragmentShader::Suspend(){
   return ESuccess;
}

//============================================================
// <T>����������</T>
//
// @return �������
//============================================================
TResult FPd11RenderFragmentShader::Resume(){
   return ESuccess;
}

//============================================================
// <T>����������</T>
//
// @return �������
//============================================================
TResult FPd11RenderFragmentShader::Dispose(){
   //TResult resultCd = ESuccess;
   //if(_renderId.uint32 != 0){
   //   glDeleteShader(_renderId.uint32);
   //   resultCd = _pDevice->CheckError("glCreateShader", "Delete fragment shader failure. (shader_id=%d)", _renderId.uint32);
   //   _renderId.uint32 = 0;
   //}
   //return resultCd;
   return ESuccess;
}

MO_NAMESPACE_END