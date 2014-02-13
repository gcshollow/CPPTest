// eJx1kEFPAjEQhTNXfwbxAJd2F4mSakwWFo3gKmQhxpNpliqN3bZpZ1ng11saOYmZTDKHN_097M94q0qBUEveMjRuPpoYkVh86hFDcW0FHYtq6omqTw9BvZ2X6ulxMssfpajJ6IpvOH91uVwxvillbZHk_0GOfvR83REejG1IJ6dILXnr4Z9_00trwR9yco8W9Cl8EjXHDloo0VYSENLaxxeJlDOnxn7BwA1uEhgLMoeGl2hNNoztjrdZp3UqHT31498CfyQetvt9W4vIJDCDEp6vPtUhuP14D7SzRn6uTfEBGnIjY0X62CGV31IgsMPfYJpB4


#ifndef SPL_OPER_INSTANCE_PRINTER_H_
#define SPL_OPER_INSTANCE_PRINTER_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMcw0z8svKS1OTQEAGJUEBI.h"
#include "../type/BeJwrMcxxM87MKwMADD4CDY.h"

#include <bitset>

#define MY_OPERATOR Printer$OP
#define MY_BASE_OPERATOR Printer_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMcxxM87MKwMADD4CDY IPort0Type;
    typedef SPL::BeJwrMcw0z8svKS1OTQEAGJUEBI OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple & tuple, uint32_t port);
    void processRaw(Tuple & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
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
   MY_OPERATOR() {}
   
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_PRINTER_H_

