/*
 * File: test.c
 * Author: Damir Cavar
 * Date: 08/02/2018
 * Purpose:
 *
 * This is a tester for FomaWrapper.
 *
 * Copyright 2018 by Damir Cavar <dcavar@indiana.edu>
 */

#import "FomaWrapper.h"

int main() {
	cout << "Loading FST " << "eng.fst" << endl;
	FomaWrapper *fw = new FomaWrapper("eng.fst");
	string inp = "calls";
	cout << "Input: " << inp << endl;
	vector<string> res = fw->applyUp(inp);
	for(auto r : res) {
		cout << r << endl;
	}
	delete fw;
	return 1;
}
