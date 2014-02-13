// eJx1j1ELgjAUhbl_1JXreZkiFRLAUikopDKKnGLZQmk62Zdqvbxo9FMblwIV7zne4icyR4dqgpBR33crz_1M96sAcg3YxggBA2Tcnxgq8fKkzqOpxOws0jpEHg_0sEJpYM_0TyO2T_1_02pPRMVjTyW1fLA5zKnGNtFGe5xkepbrpkCccRjQO6x201vjDDoJAFtwHHKiulMkMC8W7reX8rIAf17rChigkNItNmdhWSmbE770iyn_1T1EGSW40BWVD8AYgkvKChdBr
/* Additional includes go here */


#ifndef SPL_OPER_INSTANCE_INVERSE_H_
#define SPL_OPER_INSTANCE_INVERSE_H_

#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMcxxM87MKwMADD4CDY.h"
#include "../type/BeJwrMcxxMylLzCkGAA_0HANC.h"

#include <bitset>

#define MY_OPERATOR Inverse$OP
#define MY_BASE_OPERATOR Inverse_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMcxxMylLzCkGAA_0HANC IPort0Type;
    typedef SPL::BeJwrMcxxM87MKwMADD4CDY OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple & tuple, uint32_t port);
    void processRaw(Tuple & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    
    
    bool hasParameter(std::string const & param) const;
    SPL::ConstValueHandle getParameter(std::string const & param) const;
    
    
    
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
#line 4 "com.test.cplusplus/CplusplusTest/CplusplusTest_h.cgt"

class MY_OPERATOR : public MY_BASE_OPERATOR 
{
public:
  // Constructor
  MY_OPERATOR();

  // Destructor
  virtual ~MY_OPERATOR(); 

  // Notify port readiness
  void allPortsReady(); 

  // Notify termination
  void prepareToShutdown(); 

  // Processing for source and threaded operators   
  void process(uint32_t idx);
    
  // Tuple processing for mutating ports 
  void process(Tuple & tuple, uint32_t port);
    
  // Tuple processing for non-mutating ports
  void process(Tuple const & tuple, uint32_t port);

  // Punctuation processing
  void process(Punctuation const & punct, uint32_t port);
  

private:
  // Members
}; 

extern "C" { 

}
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_INVERSE_H_


