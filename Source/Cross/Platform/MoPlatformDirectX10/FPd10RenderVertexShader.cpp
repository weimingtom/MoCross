#include "MoPd10Render.h"

MO_NAMESPACE_BEGIN

MO_CLASS_IMPLEMENT_INHERITS(FPd10RenderVertexShader, FRenderVertexShader);

//============================================================
// <T>������Ⱦ����</T>
//============================================================
FPd10RenderVertexShader::FPd10RenderVertexShader(){
   MO_CLEAR(_piData);
   MO_CLEAR(_piShader);
}

//============================================================
// <T>������Ⱦ����</T>
//============================================================
FPd10RenderVertexShader::~FPd10RenderVertexShader(){
   MO_RELEASE(_piData);
   MO_RELEASE(_piShader);
}

//============================================================
// <T>���ô�����</T>
//
// @return �������
//============================================================
TResult FPd10RenderVertexShader::Setup(){
   //_renderId.uint32 = glCreateShader(GL_VERTEX_SHADER);
   //TResult resultCd = _pDevice->CheckError("glCreateShader", "Create vertex shader failure. (shader_id=%d)", _renderId.uint32);
   //return resultCd;
   return ESuccess;
}

//============================================================
// <T>���봦����</T>
//
// @param pSource �����ַ���
// @return �������
//============================================================
TResult FPd10RenderVertexShader::Compile(TCharC* pSource){
   // ����豸��Ϣ
   MO_CHECK(_pDevice, return ENull);
   FPd10RenderDevice* pRenderDevice = _pDevice->Convert<FPd10RenderDevice>();
   FRenderCapability* pCapability = pRenderDevice->Capability();
   TCharC* pShaderVersion = pCapability->ShaderVertexVersion();
   // �ϴ�����
   TInt length = RString::Length(pSource);
   ID3D10Blob* piError = NULL;
   HRESULT shaderResult = S_OK;
   HRESULT dxResult = D3DX10CompileFromMemory(pSource, length, NULL, NULL, NULL, "main", pShaderVersion, 0, 0, NULL, &_piData, &piError, &shaderResult);
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
   dxResult = pRenderDevice->NativeDevice()->CreateVertexShader(pData, dataSize, &_piShader);
   if(FAILED(dxResult)){
      MO_FATAL("Create vertex shader failure.");
      return EFailure;
   }
   MO_INFO("Create vertex shader success. (status=%d)\n%s", dxResult, pSource);
   return ESuccess;
}

//============================================================
// <T>��������</T>
//
// @return �������
//============================================================
TResult FPd10RenderVertexShader::Suspend(){
   return ESuccess;
}

//============================================================
// <T>����������</T>
//
// @return �������
//============================================================
TResult FPd10RenderVertexShader::Resume(){
   return ESuccess;
}

//============================================================
// <T>����������</T>
//
// @return �������
//============================================================
TResult FPd10RenderVertexShader::Dispose(){
   //TResult resultCd = ESuccess;
   //if(_renderId.uint32 != 0){
   //   glDeleteShader(_renderId.uint32);
   //   resultCd = _pDevice->CheckError("glCreateShader", "Delete vertex shader failure. (shader_id=%d)", _renderId.uint32);
   //   _renderId.uint32 = 0;
   //}
   //return resultCd;
   return ESuccess;
}

MO_NAMESPACE_END