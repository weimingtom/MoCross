#include "MoFgBase.h"
#include "MoFgVisual.h"
#include "MoFgRender.h"
#include "MoFgTechnique.h"

MO_NAMESPACE_BEGIN

MO_CLASS_IMPLEMENT_INHERITS(FRenderable, FInstance);

//============================================================
// <T>构造可绘制对象。</T>
//============================================================
FRenderable::FRenderable(){
   _pVisualInfo = MO_CREATE(FVisualNode);
   _pVisualInfo->SetRenderable(this);
   MO_CLEAR(_pIndexBuffer);
   MO_CLEAR(_pActiveEffect);
}

//============================================================
// <T>析构可绘制对象。</T>
//============================================================
FRenderable::~FRenderable(){
   MO_DELETE(_pVisualInfo);
}

//============================================================
// <T>查找指定代码的属性。</T>
//
// @param pCode 代码
// @return 属性
//============================================================
FRenderableAttribute* FRenderable::AttributeFind(TCharC* pCode){
   TInt count = _attributes.Count();
   for(TInt n = 0; n < count; n++){
      FRenderableAttribute* pRenderableAttribute = _attributes.Get(n);
      if(pRenderableAttribute->IsCode(pCode)){
         return pRenderableAttribute;
      }
   }
   return NULL;
}

//============================================================
// <T>获得指定代码的属性。</T>
//
// @param pCode 代码
// @return 属性
//============================================================
FRenderableAttribute* FRenderable::AttributeGet(TCharC* pCode){
   FRenderableAttribute* pRenderableAttribute = AttributeFind(pCode);
   if(pRenderableAttribute == NULL){
      MO_FATAL("Can't find renderable attribute. (code=%s)", pCode);
   }
   return pRenderableAttribute;
}

//============================================================
// <T>查找指定代码的取样器。</T>
//
// @param pCode 代码
// @return 取样器
//============================================================
FRenderableSampler* FRenderable::SamplerFind(TCharC* pCode){
   TInt count = _samplers.Count();
   for(TInt n = 0; n < count; n++){
      FRenderableSampler* pRenderableSampler = _samplers.Get(n);
      if(pRenderableSampler->IsCode(pCode)){
         return pRenderableSampler;
      }
   }
   return NULL;
}

//============================================================
// <T>获得指定代码的取样器。</T>
//
// @param pCode 代码
// @return 取样器
//============================================================
FRenderableSampler* FRenderable::SamplerGet(TCharC* pCode){
   FRenderableSampler* pRenderableSampler = SamplerFind(pCode);
   if(pRenderableSampler == NULL){
      MO_FATAL("Can't find renderable sampler. (code=%s)", pCode);
   }
   return pRenderableSampler;
}

//============================================================
// <T>查找指定名称的效果器。</T>
//
// @param pName 名称
// @return 效果器
//============================================================
FRenderableEffect* FRenderable::EffectFind(TCharC* pName){
   TInt count = _effects.Count();
   for(TInt n = 0; n < count; n++){
      FRenderableEffect* pRenderableEffect = _effects.Get(n);
      if(pRenderableEffect != NULL){
         FEffect* pEffect = pRenderableEffect->Effect();
         MO_CHECK(pEffect, continue);
         if(pEffect->IsName(pName)){
            return pRenderableEffect;
         }
      }
   }
   return NULL;
}

//============================================================
// <T>绑定指定名称的效果器。</T>
//
// @param pEffect 效果器
// @return 处理结果
//============================================================
FRenderableEffect* FRenderable::EffectBind(FEffect* pEffect){
   FRenderableEffect* pRenderableEffect = FRenderableEffect::InstanceCreate();
   pRenderableEffect->SetEffect(pEffect);
   _effects.Push(pRenderableEffect);
   return pRenderableEffect;
}

//============================================================
// <T>计算模型矩阵。</T>
//
// @param matrix 模型矩阵
// @return 处理结果
//============================================================
TResult FRenderable::CalculateModelMatrix(SFloatMatrix3d& matrix){
   return ESuccess;
}

//============================================================
// <T>计算模型矩阵。</T>
//
// @param pMatrix 矩阵集合
// @param offset 位置
// @param count 容量
// @return 处理个数
//============================================================
TInt FRenderable::CalculateBoneMatrix(SFloatMatrix3d* pMatrix, TInt offset, TInt capacity){
   return 0;
}

//============================================================
// <T>建立标志集合。</T>
//============================================================
TResult FRenderable::BuildDescriptor(){
   //// 设置骨头个数
   //_descriptor.vertexCount = _pVertexStreams->VertexCount();
   //// 设置属性集合
   //FRenderVertexStreamCollection* pStreams = _pVertexStreams->Streams();
   //TInt count = pStreams->Count();
   //for(TInt n = 0; n < count; n++){
   //   FRenderVertexStream* pStream = pStreams->Get(n);
   //   TCharC* pCode = pStream->Code();
   //   TInt bufferCd = RRenderAttribute::Parse(pCode);
   //   _descriptor.vertexBuffers[bufferCd] = ETrue;
   //}
   return ESuccess;
}

//============================================================
// <T>更新处理。</T>
//
// @param pContext 环境
// @return 处理结果
//============================================================
TResult FRenderable::Update(TAny* pContext){
   return ESuccess;
}

//============================================================
// <T>功能前置处理。</T>
//
// @param pContext 环境
// @return 处理结果
//============================================================
TResult FRenderable::ProcessBefore(TAny* pParameter){
   return ESuccess;
}

//============================================================
// <T>功能后置处理。</T>
//
// @param pContext 环境
// @return 处理结果
//============================================================
TResult FRenderable::ProcessAfter(TAny* pParameter){
   return ESuccess;
}

//============================================================
// <T>释放内容。</T>
//============================================================
TResult FRenderable::Free(){
   return ESuccess;
}

//============================================================
// <T>挂起处理。</T>
//
// @return 处理结果
//============================================================
TResult FRenderable::Suspend(){
   _pActiveEffect = NULL;
   _effects.Clear();
   return ESuccess;
}

//============================================================
// <T>继续处理。</T>
//
// @return 处理结果
//============================================================
TResult FRenderable::Resume(){
   return ESuccess;
}

//============================================================
// <T>析构处理。</T>
//
// @return 处理结果
//============================================================
TResult FRenderable::Dispose(){
   return ESuccess;
}

MO_NAMESPACE_END
