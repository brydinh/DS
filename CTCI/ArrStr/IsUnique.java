import java.util.*;

public class IsUnique {
	  public static void main(String[] args)
	  {
		  String[] words = {"abcde", "hello", "aPple", "kite", "padle"};
		  for(String word: words)
		  {
			  System.out.println(word + ": " + isUnique(word));
		  }
	  }
	  
	  public static boolean isUnique(String str)
	  {
		  if(str.length() > 128) return false;
		  
		  str = str.toLowerCase();
		  
		  boolean[] char_set = new boolean[128];
		  
		  for(int x=0; x<str.length(); x++)
		  {
			  int val = str.charAt(x);
			  if(char_set[val]) return false;
			  char_set[val] = true;
		  }
		  
		  return true;
	  }
	  
}
