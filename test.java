import java.io.*;
import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;

public class test {

    public static void main (String [] args) {
	String a = "aa ;328*(834 230920934_=2{}p-2304234>? asdf o3( 7*^#%";
 	String rm = "a {}?fefa";
	String result = test.removeChars2(a, rm);
	
	System.out.println(result);
    }



    public static String removeChars(String str, String remove) {
	int length = str.length();	
	Set<Character> charSet = new HashSet<Character>();
        for(int i = 0; i < remove.length(); i++) {
	    if(charSet.contains(remove.charAt(i)))
		continue;
	    else
		charSet.add(remove.charAt(i));
  	}

	StringBuilder sb = new StringBuilder(str);
	
	for( int index = 0; index < length; index++) {
	    if(charSet.contains(sb.charAt(index)))
		sb.setCharAt(index, '\0');
	}

	StringBuilder resultBuilder = new StringBuilder();
	
	for( int index = 0; index < length; index++) {
	    if(sb.charAt(index) != '\0')
		resultBuilder.append( sb.charAt(index) );
	}

	return resultBuilder.toString();
    }

    public static String removeChars2 ( String str, String remove) {
        char[] s = str.toCharArray();
	char[] r = remove.toCharArray();
	boolean [] flags = new boolean [128];
	int len = str.length();
	int src, dst;

	for ( src = 0; src < remove.length(); ++src) {
	    flags[r[src]] = true;
	}
	src = 0;
	dst = 0;
	while (src < len ) {
	    if(!flags[(int)s[src]]){
		s[dst++] = s[src];
	    }
	    ++src;
	}
	return new String(s, 0, dst );
    }
}
