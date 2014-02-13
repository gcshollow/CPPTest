// eJxjdCwtyWdkNGQMKMrMK0ktAgAifASz


#include "BeJwzDyjKzCtJLYoHABB0AN7.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>

#include <SPL/Runtime/Utility/MessageFormatter.h>

#include <streams_boost/filesystem/operations.hpp>
namespace bf = streams_boost::filesystem;


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzDyjKzCtJLYoHABB0AN7



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 30;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}


void MYPE::registerResources(const std::string & applicationDir)
{
    SPL::RuntimeMessageFormatter & formatter = SPL::RuntimeMessageFormatter::instance();
    bf::path appDir(applicationDir);
    bf::path p;

    p = "/opt/ibm/InfoSphereStreams/toolkits/com.ibm.streams.bigdata";
    if (!p.is_complete()) {
        p = appDir / p;
    }
    formatter.registerToolkit("com.ibm.streams.bigdata", p.string());

    p = "/opt/ibm/InfoSphereStreams/toolkits/com.ibm.streams.cep";
    if (!p.is_complete()) {
        p = appDir / p;
    }
    formatter.registerToolkit("com.ibm.streams.cep", p.string());

    p = "/opt/ibm/InfoSphereStreams/toolkits/com.ibm.streams.db";
    if (!p.is_complete()) {
        p = appDir / p;
    }
    formatter.registerToolkit("com.ibm.streams.db", p.string());

    p = "/opt/ibm/InfoSphereStreams/toolkits/com.ibm.streams.financial";
    if (!p.is_complete()) {
        p = appDir / p;
    }
    formatter.registerToolkit("com.ibm.streams.financial", p.string());

    p = "/opt/ibm/InfoSphereStreams/toolkits/com.ibm.streams.inet";
    if (!p.is_complete()) {
        p = appDir / p;
    }
    formatter.registerToolkit("com.ibm.streams.inet", p.string());

    p = "/opt/ibm/InfoSphereStreams/toolkits/com.ibm.streams.messaging";
    if (!p.is_complete()) {
        p = appDir / p;
    }
    formatter.registerToolkit("com.ibm.streams.messaging.xms", p.string());

    p = "/opt/ibm/InfoSphereStreams/toolkits/com.ibm.streams.mining";
    if (!p.is_complete()) {
        p = appDir / p;
    }
    formatter.registerToolkit("com.ibm.streams.mining", p.string());

    p = "/opt/ibm/InfoSphereStreams/toolkits/com.ibm.streams.timeseries";
    if (!p.is_complete()) {
        p = appDir / p;
    }
    formatter.registerToolkit("com.ibm.streams.timeseries", p.string());

}


MAKE_PE(SPL::MYPE);

