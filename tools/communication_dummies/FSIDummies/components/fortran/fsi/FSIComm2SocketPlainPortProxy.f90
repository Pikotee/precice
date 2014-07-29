subroutine  fsi_fsicommc2socket_plain_port_create_client_instance(self,host,port,buffer_size) bind(c)
     use, intrinsic :: iso_c_binding
     integer(kind=c_long_long)::self
     type(c_ptr)::host
     integer(kind=c_int)::port
     integer(kind=c_int)::buffer_size
     
     
end subroutine fsi_fsicommc2socket_plain_port_create_client_instance


subroutine  fsi_fsicommc2socket_plain_port_destroy_instance(self) bind(c)
     use, intrinsic :: iso_c_binding
     integer(kind=c_long_long)::self
end subroutine fsi_fsicommc2socket_plain_port_destroy_instance

subroutine  fsi_fsicommc2socket_plain_port_transferCoordinates(self,&
	coord,coord_len) bind(c)
     use, intrinsic :: iso_c_binding
     integer(kind=c_long_long)::self
     	real(kind=c_double),intent(in),dimension(*)::coord
	integer(kind=c_int),intent(in)::coord_len

end subroutine fsi_fsicommc2socket_plain_port_transferCoordinates
subroutine  fsi_fsicommc2socket_plain_port_transferData(self,&
	data,data_len) bind(c)
     use, intrinsic :: iso_c_binding
     integer(kind=c_long_long)::self
     	real(kind=c_double),intent(in),dimension(*)::data
	integer(kind=c_int),intent(in)::data_len

end subroutine fsi_fsicommc2socket_plain_port_transferData