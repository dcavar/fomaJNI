/*
 * File: FomaWrapper.h
 * Author: Damir Cavar
 * Date: 08/02/2018
 * Purpose:
 * Wrap the foma lib functions in a C++ class to communicate via JNI to Java.
 *
 * Copyright 2018 by Damir Cavar <dcavar@indiana.edu>
 */


typedef bool _Bool; // Foma uses C99 _Bool, Mac clang has trouble with that


#include <iostream>
#include <stdbool.h> // Foma uses _Bool from C99, this is necessary
#include <string>
#include <vector>
#include <fomalib.h>


using namespace std;


class FomaWrapper {

	struct fsm *net = nullptr;
	struct apply_handle *ah = nullptr;

public:
    string fstFilename;

    FomaWrapper(const string);
    ~FomaWrapper();
    vector<string> applyUp(string);
    vector<string> applyDown(string);
    vector<string> apply(string, bool up);
};

