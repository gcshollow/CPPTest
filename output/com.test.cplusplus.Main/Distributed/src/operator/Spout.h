// eJx1j9FqAjEQRZk_1KdLnTWLFh0WErEVrUako_0FjSdcRgTJbMrHX79V2iCIIyL8Nwh3MuVS6r2TrLTZ4XaMrgQaZR0MkywU2FosDP3zgvz_0d542Z_1o8NE62_15oRejbN9pk11o318lrL5meV5bz29dSCd1OTlLPEjbzgXD_1d7LEADEPhxREEc0RxKbEA9UmRLFQq_1e9VKskVhsDRvwwWNrYxmjYRs8gbpDqSteM0f7UzOOI2IqICFUId7UntYAC7GNn4wjSLJXzyEoTdMb71GPC1zJf2I7GIU

#include <SPL/Runtime/Utility/Mutex.h>

#ifndef SPL_OPER_INSTANCE_SPOUT_H_
#define SPL_OPER_INSTANCE_SPOUT_H_

#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMcxxMylLzCkGAA_0HANC.h"


#define MY_OPERATOR Spout$OP
#define MY_BASE_OPERATOR Spout_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMcxxMylLzCkGAA_0HANC OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    
    
    
    SPL::uint32 lit$0;
    SPL::list<SPL::float64 > lit$1;
    
    
protected:
    Mutex $svMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const {
    }
    void restoreStateVariables(NetworkByteBuffer & opstate) {
    }
private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR 
{
public:
   MY_OPERATOR();
  
   void allPortsReady();
   void process(uint32_t index);
   virtual void getCheckpoint(NetworkByteBuffer & opstate);
   virtual void restoreCheckpoint(NetworkByteBuffer & opstate);
private:
   SPL::BeJwrMcxxMylLzCkGAA_0HANC _tuple;
   SPL::uint32 _iters;
   Mutex _mutex;
   uint64_t _iterationCount;
   uint64_t IterationCount() const { return _iterationCount;}
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_SPOUT_H_


