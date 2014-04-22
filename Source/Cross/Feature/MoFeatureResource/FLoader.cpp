#include "MoFrLoader.h"

MO_NAMESPACE_BEGIN

MO_CLASS_IMPLEMENT_INHERITS(FLoader, FInstance);

//============================================================
// <T>构造加载器。</T>
//============================================================
FLoader::FLoader(){
}

//============================================================
// <T>析构加载器。</T>
//============================================================
FLoader::~FLoader(){
}

//============================================================
// <T>数据处理。</T>
//
// @return 处理结果
//============================================================
TResult FLoader::Process(){
   return ESuccess;
}

MO_NAMESPACE_END
