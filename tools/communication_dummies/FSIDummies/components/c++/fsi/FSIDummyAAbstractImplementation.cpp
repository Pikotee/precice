#include "fsi/FSIDummyAAbstractImplementation.h"

fsi::FSIDummyAAbstractImplementation::FSIDummyAAbstractImplementation(){
     _b = 0;

}

fsi::FSIDummyAAbstractImplementation::~FSIDummyAAbstractImplementation(){

}

/**
 * @see Case class 
 */
 void fsi::FSIDummyAAbstractImplementation::connectb(fsi::FSICommNativeDispatcher* port){
   _b = port; 
 }
 
 void fsi::FSIDummyAAbstractImplementation::disconnectb(){
    //delete _b;
    _b=NULL;
 }
 
void fsi::FSIDummyAAbstractImplementation::testParallel(){
     // @todo Insert your code here
}