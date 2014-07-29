#ifndef FSI_FSIDUMMYAIMPLEMENTATION_H_
#define FSI_FSIDUMMYAIMPLEMENTATION_H_ 

//
// ASCoDT - Advanced Scientific Computing Development Toolkit
//
// This file was generated by ASCoDT's simplified SIDL compiler.
//
// Authors: Tobias Weinzierl, Atanas Atanasov   
//

#include "fsi/FSIDummyAAbstractImplementation.h"
#include <string>
namespace fsi { 

     class FSIDummyAImplementation;
}

class fsi::FSIDummyAImplementation : public fsi::FSIDummyAAbstractImplementation{
private:
	void transferAllData();

public:
          FSIDummyAImplementation();
          ~FSIDummyAImplementation();
          void test();
};     


#endif