/*
 * File: FomaWrapper.cpp
 * Author: Damir Cavar
 * Date: 08/02/2018
 * Purpose:
 * Wrap the foma lib functions in a C++ class to communicate via JNI to Java.
 *
 * Copyright 2018 by Damir Cavar <dcavar@indiana.edu>
 */


#include "FomaWrapper.h"



FomaWrapper::FomaWrapper (const string fname) {
	fstFilename = fname;
	net = fsm_read_binary_file((char *)fname.c_str());
	ah = apply_init(net);
}


FomaWrapper::~FomaWrapper() {
    if (ah != nullptr) {
    	apply_clear(ah);
    }
	if (net != nullptr) {
		fsm_destroy(net);
	}
}


vector<string> FomaWrapper::applyUp(string token) {
	return apply(token, true);
}


vector<string> FomaWrapper::applyDown(string token) {
	return apply(token, false);
}


vector<string> FomaWrapper::apply(string token, bool up) {
	vector<string> results;
	if (ah == nullptr) return results;

	// create the function pointer for up or down
	char *(*applyFunction)(struct apply_handle *, char *);

	if (up) applyFunction = &apply_up;
	else applyFunction = &apply_down;

	char *res = applyFunction(ah, (char *)token.c_str());
	while (res != nullptr) {
		results.push_back(string(res));
	    res = applyFunction(ah, nullptr);
	}
	return results;
}

