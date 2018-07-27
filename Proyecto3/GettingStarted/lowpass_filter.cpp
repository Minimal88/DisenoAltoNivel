SCA_SDF_MODULE(lowpass) { 			// a lowpass filter using an ltf module 
	sca_sdf_in<double> in;			// input double (wave)
	sca_sdf_out<double> out;		// output is the filtered wave

	sca_ltf_nd ltf_1;				// The Laplace-Transform module
	double freq_cutoff;				// the cutoff-frequency of the lowpass 
	sca_vector<double> Nom, Denom; 	// Vectors for the Laplace-Transform module


	void sig_proc(){
		out.write(ltf_1(Nom,Denom, in.read()));
	}

	lowpass(sc_module_name n, double freq_cut){
		Nom(0)= 1.0; Denom(0)=1.0;			// values for the LTF
		Denom(1)= 1.0/(2.0*M_PI*freq_cut); 	// to describe a lowpass-filter I
	 } 
};
