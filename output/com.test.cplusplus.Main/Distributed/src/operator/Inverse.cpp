// eJx1j1ELgjAUhbl_1JXreZkiFRLAUikopDKKnGLZQmk62Zdqvbxo9FMblwIV7zne4icyR4dqgpBR33crz_1M96sAcg3YxggBA2Tcnxgq8fKkzqOpxOws0jpEHg_0sEJpYM_0TyO2T_1_02pPRMVjTyW1fLA5zKnGNtFGe5xkepbrpkCccRjQO6x201vjDDoJAFtwHHKiulMkMC8W7reX8rIAf17rChigkNItNmdhWSmbE770iyn_1T1EGSW40BWVD8AYgkvKChdBr
/* Additional includes go here */




#include "./Inverse.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Inverse_Base
#define MY_OPERATOR Inverse$OP
#line 6 "com.test.cplusplus/CplusplusTest/CplusplusTest_cpp.cgt"

// Constructor
MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
{
    // Initialization code goes here    
}

// Destructor
MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR() 
{
    // Finalization code goes here
}

// Notify port readiness
void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady() 
{
    // Notifies that all ports are ready. No tuples should be submitted before
    // this. Source operators can use this method to spawn threads.

    /*
      createThreads(1); // Create source thread
    */
}
 
// Notify pending shutdown
void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown() 
{
    // This is an asynchronous call
}

// Processing for source and threaded operators   
void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t idx)
{
    // A typical implementation will loop until shutdown
    /*
      while(!getPE().getShutdownRequested()) {
          // do work ...
      }
    */
}

// Tuple processing for mutating ports 
void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple & tuple, uint32_t port)
{
    // Sample submit code
    /* 
      submit(otuple, 0); // submit to output port 0
    */
    // Sample cast code
    /*
    switch(port) {
    case 0: { 
      IPort0Type & ituple = static_cast<IPort0Type&>(tuple);
      ...
    } break;
    case 1: { 
      IPort1Type & ituple = static_cast<IPort1Type&>(tuple);
      ...
    } break;
    default: ...
    }
    */
}

// Tuple processing for non-mutating ports
void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
    // Sample submit code
    
      IPort0Type ituple;
      list<float64> newList = ituple.get_vals();
      OPort0Type otuple;
      double doubleHolder[] = (double)newList;
      otuple.inv = inverse(doubleHolder);
      submit(otuple, 0); // submit to output port 0
    
    // Sample cast code
    /*
    switch(port) {
    case 0: { 
      IPort0Type const & ituple = static_cast<IPort0Type const&>(tuple);
      ...
    } break;
    case 1: { 
      IPort1Type const & ituple = static_cast<IPort1Type const&>(tuple);
      ...
    } break;
    default: ...
    }
    */
}

// Punctuation processing
void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{
    /*
      if(punct==Punctuation::WindowMarker) {
        // ...;
      } else if(punct==Punctuation::FinalMarker) {
        // ...;
      }
    */
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Inverse",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator() {
    PE & pe = PE::instance();
    uint32_t index = getIndex();
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("01"));
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}

void MY_BASE_OPERATOR::tupleLogic(Tuple & tuple, uint32_t port) {
}


void MY_BASE_OPERATOR::processRaw(Tuple & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    punctLogic (punct, port);
    
    if (punct == Punctuation::FinalMarker) {
        process(punct, port);
        bool forward = false;
        {
            AutoPortMutex $apm($fpMutex, *this);
            $oportBitset.reset(port);
            if ($oportBitset.none()) {
                $oportBitset.set(1);
                forward=true;
            }
        }
        if(forward)
            submit(punct, 0);
        return;
    }
    
    process(punct, port);
}


bool MY_BASE_OPERATOR::hasParameter(std::string const & param) const {
    return getParameterNames().count(param);
}
SPL::ConstValueHandle MY_BASE_OPERATOR::getParameter(std::string const & param) const {
    assert(getParameterNames().count(param));
    const ParameterValueListType& values = getParameterValues(param);
    return values[0]->getValue();
}

