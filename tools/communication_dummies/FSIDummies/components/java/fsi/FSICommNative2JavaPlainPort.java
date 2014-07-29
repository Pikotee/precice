//
// ASCoDT - Advanced Scientific Computing Development Toolkit
//
// This file was generated by ASCoDT's simplified SIDL compiler.
//
// Authors: Tobias Weinzierl, Atanas Atanasov   
//
package fsi;


public class FSICommNative2JavaPlainPort extends FSICommAbstractPort {

  private long _ref;
  public FSICommNative2JavaPlainPort() {
    super();
    createInstance();
  }
  
  public native void createInstance();
  public native void destroyInstance(long ref);
  /**
   * Disconnect a port.
   * 
   * @throw If already not connected to type port.
   * @see Operation with name of any implementing component 
   */
  public void disconnect(FSIComm  port) throws de.tum.ascodt.utils.exceptions.ASCoDTException {
     super.disconnect(port);
  }
  
  public void destroy(){
     destroyInstance(_ref);    
  }
  public long getReference(){
    return _ref;
  }  
  
  public void setReference(long ref){
     _ref=ref;
  }

  public void transferCoordinates(final double coord[]) {
   // if (_destination!=null) {
      //_destination.lock();
      _destination.transferCoordinates(coord);
      //_destination.unlock();
    //}
  }
  
  public void transferCoordinatesParallel(final double coord[]) {
   // if (_destination!=null) {
      //_destination.lock();
      _destination.transferCoordinatesParallel(coord);
      //_destination.unlock();
    //}
  }
  
  
  

  public void transferData(final double data[]) {
   // if (_destination!=null) {
      //_destination.lock();
      _destination.transferData(data);
      //_destination.unlock();
    //}
  }
  
  public void transferDataParallel(final double data[]) {
   // if (_destination!=null) {
      //_destination.lock();
      _destination.transferDataParallel(data);
      //_destination.unlock();
    //}
  }
  
  
  


}
 

