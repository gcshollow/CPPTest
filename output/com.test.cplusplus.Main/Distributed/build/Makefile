# NOTE: This makefile is designed to be run from one level up in the directory
# hierarchy compared to where it resides. For instance, if this makefile is
# located at 'output/build/Makefile', then it can be launched as:
# 'make -f build/Makefile' from the 'output' directory.

ifeq ($(CXX),)
  CXX=g++
endif
PKGCONFIG := /opt/ibm/InfoSphereStreams/bin/dst-pe-pkg-config.sh
PE_INCLUDE := $(shell $(PKGCONFIG) --cflags dst-spl-pe-install)
PE_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install)
PE_STAND_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install-standalone)
SPL_CXXFLAGS = -Wall -Wno-unused -Wno-sign-compare
SPL_CXXFLAGS += -D_REENTRANT -fPIC -finline-functions -fmessage-length=0
SPL_CXXFLAGS += $(PE_INCLUDE) 
SPL_LDFLAGS = $(PE_LIB)

SPL_TYPES = build/type/BeJwrMcxxMylLzCkGAA_0HANC.o \
            build/type/BeJwrMcw0z8svKS1OTQEAGJUEBI.o \
            build/type/BeJwrMcxxM87MKwMADD4CDY.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Spout.o \
                build/operator/Inverse.o \
                build/operator/Printer.o 
SPL_PE_OBJS = build/pe/BeJwzDS7ILy2JBwAJ_1gKw.o \
              build/pe/BeJwz98wrSy0qTo0HABBJANz.o \
              build/pe/BeJwzDyjKzCtJLYoHABB0AN7.o 
SPL_PE_BINS = bin/com.test.cplusplus.Main-a.dpe \
              bin/com.test.cplusplus.Main-b.dpe \
              bin/com.test.cplusplus.Main-c.dpe 

.PHONY: distclean clean all types functions operators pes svar

all: bin types functions operators pes svar standalone

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/pe build/svar build/standalone

bin:
	@mkdir -m 775 bin

types: $(SPL_TYPES)

build/type/BeJwrMcxxMylLzCkGAA_0HANC.o: \
	    src/type/BeJwrMcxxMylLzCkGAA_0HANC.h \
	    src/type/BeJwrMcxxMylLzCkGAA_0HANC.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<list<float64> vals>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMcxxMylLzCkGAA_0HANC.cpp

build/type/BeJwrMcw0z8svKS1OTQEAGJUEBI.o: \
	    src/type/BeJwrMcw0z8svKS1OTQEAGJUEBI.h \
	    src/type/BeJwrMcw0z8svKS1OTQEAGJUEBI.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<int32 notused>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMcw0z8svKS1OTQEAGJUEBI.cpp

build/type/BeJwrMcxxM87MKwMADD4CDY.o: \
	    src/type/BeJwrMcxxM87MKwMADD4CDY.h \
	    src/type/BeJwrMcxxM87MKwMADD4CDY.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<list<float64> inv>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMcxxM87MKwMADD4CDY.cpp

build/type:
	-@mkdir -m 775 build/type

operators: $(SPL_OPERATORS)

-include build/operator/Spout.d
build/operator/Spout.o: \
	    src/operator/Spout.h \
	    src/operator/Spout.cpp\
	    build/dep/operator/Spout.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Spout'
	@$(CXX) -o $@ -MD -c $(SPL_CXXFLAGS) src/operator/Spout.cpp

-include build/operator/Inverse.d
build/operator/Inverse.o: \
	    src/operator/Inverse.h \
	    src/operator/Inverse.cpp\
	    build/dep/operator/Inverse.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Inverse'
	@$(CXX) -o $@ -MD -c $(SPL_CXXFLAGS) src/operator/Inverse.cpp

-include build/operator/Printer.d
build/operator/Printer.o: \
	    src/operator/Printer.h \
	    src/operator/Printer.cpp\
	    build/dep/operator/Printer.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Printer'
	@$(CXX) -o $@ -MD -c $(SPL_CXXFLAGS) src/operator/Printer.cpp

build/operator:
	-@mkdir -m 775 -p build/operator

functions: $(SPL_FUNCTIONS)

pes: $(SPL_PE_BINS)

build/pe/BeJwzDS7ILy2JBwAJ_1gKw.o: \
	    src/pe/BeJwzDS7ILy2JBwAJ_1gKw.h \
	    src/pe/BeJwzDS7ILy2JBwAJ_1gKw.cpp  \
	    build/cppOptions \
	    | build/pe
	@echo ' [CXX-pe] pe com.test.cplusplus.Main-a'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/pe/BeJwzDS7ILy2JBwAJ_1gKw.cpp

PEcom.test.cplusplus.Main-a = \
	    build/pe/BeJwzDS7ILy2JBwAJ_1gKw.o \
	    build/operator/Spout.o \
	    build/type/BeJwrMcxxMylLzCkGAA_0HANC.o 

bin/com.test.cplusplus.Main-a.dpe: \
	$(PEcom.test.cplusplus.Main-a) \
	build/dep/com.test.cplusplus.Main-a.dep \
	build/ldOptions
	@echo ' [LD-pe] pe com.test.cplusplus.Main-a'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/com.test.cplusplus.Main-a.dpe -fPIC -shared $(PEcom.test.cplusplus.Main-a) $(SPL_LDFLAGS)

build/pe/BeJwz98wrSy0qTo0HABBJANz.o: \
	    src/pe/BeJwz98wrSy0qTo0HABBJANz.h \
	    src/pe/BeJwz98wrSy0qTo0HABBJANz.cpp  \
	    build/cppOptions \
	    | build/pe
	@echo ' [CXX-pe] pe com.test.cplusplus.Main-b'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/pe/BeJwz98wrSy0qTo0HABBJANz.cpp

PEcom.test.cplusplus.Main-b = \
	    build/pe/BeJwz98wrSy0qTo0HABBJANz.o \
	    build/operator/Inverse.o \
	    build/type/BeJwrMcxxMylLzCkGAA_0HANC.o \
	    build/type/BeJwrMcxxM87MKwMADD4CDY.o 

bin/com.test.cplusplus.Main-b.dpe: \
	$(PEcom.test.cplusplus.Main-b) \
	build/dep/com.test.cplusplus.Main-b.dep \
	build/ldOptions
	@echo ' [LD-pe] pe com.test.cplusplus.Main-b'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/com.test.cplusplus.Main-b.dpe -fPIC -shared $(PEcom.test.cplusplus.Main-b) $(SPL_LDFLAGS)

build/pe/BeJwzDyjKzCtJLYoHABB0AN7.o: \
	    src/pe/BeJwzDyjKzCtJLYoHABB0AN7.h \
	    src/pe/BeJwzDyjKzCtJLYoHABB0AN7.cpp  \
	    build/cppOptions \
	    | build/pe
	@echo ' [CXX-pe] pe com.test.cplusplus.Main-c'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/pe/BeJwzDyjKzCtJLYoHABB0AN7.cpp

PEcom.test.cplusplus.Main-c = \
	    build/pe/BeJwzDyjKzCtJLYoHABB0AN7.o \
	    build/operator/Printer.o \
	    build/type/BeJwrMcw0z8svKS1OTQEAGJUEBI.o \
	    build/type/BeJwrMcxxM87MKwMADD4CDY.o 

bin/com.test.cplusplus.Main-c.dpe: \
	$(PEcom.test.cplusplus.Main-c) \
	build/dep/com.test.cplusplus.Main-c.dep \
	build/ldOptions
	@echo ' [LD-pe] pe com.test.cplusplus.Main-c'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/com.test.cplusplus.Main-c.dpe -fPIC -shared $(PEcom.test.cplusplus.Main-c) $(SPL_LDFLAGS)

build/pe:
	-@mkdir -m 775 build/pe

standalone: 
	@rm -f bin/standalone

