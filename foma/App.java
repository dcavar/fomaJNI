/**
 * App.java
 * (C) 2018 by Damir Cavar <dcavar@indiana.edu>
 *
 * Date: 08/03/2018
 * Version: 0.1
 *
 * This is the Java component of the JNI C++ interface to the FomaWrapper class and
 * the Foma library.
 *
 * The morphological analyzer Foma takes a string and returns n strings. Since it is
 * using a bidirectional model here, the input can be a token and the output a
 * list of analyzes, or the other way around, it could be an analysis string and
 * the final surface form of a morpheme.
 */


package foma;



/**
 * Use foma library to load a FST and process a string.
 *
 */
public class App {

	private long ptr_; // class pointer to net

	private native long getFST(String fname); // returns a net pointer

	private native void destroyFST(long ptr); // calls fsm_destroy on net pointer

	private static native String[] applyUp(long ptr, String token);

	private static native String[] applyDown(long ptr, String token);

	static {
		System.loadLibrary("fomaJNI");
	}

	public App(String fname) {
		ptr_ = getFST(fname);
	}

	protected void finalize() throws Throwable {
		destroy();
	}

	public void destroy() {
		System.out.println(ptr_);
		destroyFST(ptr_);
	}

	public String[] getAnalysisUp(String token) {
		String[] res = applyUp(ptr_, token);
		return res;
	}

	// Test the App class
	public static void main(String[] args) {
		foma.App myApp = new foma.App("eng.fst");
		String someInput = "calls";
		String[] res = myApp.getAnalysisUp(someInput);
		// make sure to call destroy to free up the memory from foma
		myApp.destroy();
		System.out.println("Input: " + someInput);
		System.out.println("Number of results: " + res.length);
		System.out.println("Results:");
		for (String r : res) {
	        System.out.println(r);
	    }
	}
}
