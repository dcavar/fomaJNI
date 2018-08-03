/**
 * App.cpp
 * (C) 2018 by Damir Cavar <dcavar@indiana.edu>
 *
 * Date: 08/03/2018
 * Version: 0.1
 *
 * This is the C++ interface between JNI and the FomaWrapper class and library.
 *
 * The morphological analyzer Foma takes a string and returns n strings. Since it is
 * using a bidirectional model here, the input can be a token and the output a
 * list of analyzes, or the other way around, it could be an analysis string and
 * the final surface form of a morpheme.
 */


#include "include/foma_App.h"
#include "FomaWrapper.h"


/*
 * Class:     foma_App
 * Method:    getFST
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_foma_App_getFST(JNIEnv *env, jobject obj, jstring inJNIStr) {
	if (!inJNIStr) return NULL;
	jboolean isCopy;
	string fname = (env)->GetStringUTFChars(inJNIStr, &isCopy);
	FomaWrapper *fw = new FomaWrapper(fname);
	return (jlong) fw;
}


/*
 * Class:     foma_App
 * Method:    destroyFST
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_foma_App_destroyFST(JNIEnv *env, jobject obj, jlong ptr_) {
	FomaWrapper* cls = (FomaWrapper*)ptr_;
	delete cls;
}


/*
 * Class:     foma_App
 * Method:    applyUp
 * Signature: (JLjava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_foma_App_applyUp(JNIEnv *env, jclass obj, jlong ptr_, jstring inJNIStr) {
	FomaWrapper* cls = (FomaWrapper*) ptr_;
	jobjectArray ret;
	string inCStr = (env)->GetStringUTFChars(inJNIStr, NULL);
	vector<string> res = cls->applyUp(inCStr);
	long l = res.size();
	ret = (jobjectArray) env->NewObjectArray(l, env->FindClass("java/lang/String"), env->NewStringUTF(""));
	for (int i = 0; i < l; i++) {
		string r = res.at(i);
		env->SetObjectArrayElement(ret, i, env->NewStringUTF(r.c_str()));
	}
	return (ret);
}


/*
 * Class:     foma_App
 * Method:    applyDown
 * Signature: (JLjava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_foma_App_applyDown(JNIEnv *env, jclass obj, jlong ptr_, jstring inJNIStr) {
	FomaWrapper* cls = (FomaWrapper*) ptr_;
	jobjectArray ret;
	string inCStr = (env)->GetStringUTFChars(inJNIStr, NULL);
	vector<string> res = cls->applyDown(inCStr);
	int l = res.size();
	ret = (jobjectArray) env->NewObjectArray(l, env->FindClass("java/lang/String"), env->NewStringUTF(""));
	for (int i = 0; i < l; i++) {
		string r = res.at(i);
		env->SetObjectArrayElement(ret, i, env->NewStringUTF(r.c_str()));
	}
	return (ret);
}
