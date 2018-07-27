#include "systemc.h" 
#include "systemc-ams"
#include <cmath>
#include <math.h>

//Instantiating and connecting
SCA_TDF_MODULE(sine) {
 sca_tdf::sca_de::sca_out<double> out; // output port
 void processing(){ // our workhorse method
 out.write( sin( sc_time_stamp().to_seconds()*(1000.*2.*M_PI))) ;
 }

 void set_attrubutes(){out.set_timestep(100,SC_NS);}
 SCA_CTOR(sine) {} // constructor does nothing here
}; 

SCA_TDF_MODULE(drain) { // a drain module to connect the signal to
 sca_tdf::sca_de::sca_in<double> in; // input port
 SCA_CTOR(drain) {} // constructor does nothing, no processing() specified!
};

int sc_main(int argc, char* argv[]){
 sc_set_time_resolution(10.0, SC_NS);
 sc_core::sc_signal<double> sig_sine ;
 sine sin("sin");
 sin.out(sig_sine);
 sin.out.set_timestep(100,SC_NS);
 //sin.set_attrubutes(); // The sampling time of the port
 drain drn("drn");
 drn.in(sig_sine);

 //sc_trace_file* sctf = sc_create_vcd_trace_file("sctr");

 sca_util::sca_trace_file* tr = sca_util::sca_create_vcd_trace_file("tr"); // Usual SystemC tracing
 sca_util::sca_trace(tr, sig_sine ,"sig_sine");
 sc_start(2, SC_MS);
 return 0;
} 