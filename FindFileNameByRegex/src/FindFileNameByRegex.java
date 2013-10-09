/* This code is intend for solving Apple Interview Home Assignment Question.
 * User must have apache.commons.io in their library.
 */

import java.io.File;
import java.util.Collection;
import java.util.Iterator;
import org.apache.commons.io.FileUtils;
import org.apache.commons.io.filefilter.DirectoryFileFilter;
import org.apache.commons.io.filefilter.RegexFileFilter;

/**
 * <p>This class consists exclusively of a instance method that recursively look
 * for files with file name containing IP4 decimal form then output all the file name.
 * The class will catch any exception input and then output the error message
 * The class will uses java standard library Collection and Iterator.
 * The Class also uses the apache.commons.io open source RegexFileFilter which allows
 * user to look for files in input directory recursively by the input regex.
 *
 * @author  Samuel Chien
 * @see     Collection
 * @see     Iterator
 * @see     List
 * @see     Apache.commons.io
 */

public class FindFileNameByRegex {
	/**
	 * <p> This method is a instance method that takes in path and full as parameter and
	 * recursively go through the directory to find files that matches the regex, then output
	 * it on the screen. The assumption  that has been made for this class is that the IPv4 will all be
	 * in form of decimal form and the question is only asking for files (excluding the directory) that
	 * contains IPv4 as part of their filename. The function will not go into files nor record any directory
	 * that has IPv4 name, only the files containing IPv4 name will be output on the screen.
	 *
	 * <p>If path is not valid, it will simply give an error message, and if full is true, then return a full path
	 * of the file that contains IPv4 decimal form in the filename. If full is false, then it will only
	 * output the filename on the screen.
	 *
	 * Assumption: a.1.2.3.4.png is not a valid input, does not accept a IPv4 hvaing '.' in front. Also every file must end with.something and it cant be .number file such as file.4.
	 *
	 * @param path
	 * @param full
	 * @output print all files' name contain IPv4 decimal form.
	 */
	
	/* Assumption of valid input.
	 * case1: 1.1.2.3.png      address.file
	 * case2: 1a1.2.3.4.png    have number and character in front
	 * case3: a1.2.3.4.png     character in front
	 * case4:libgssapiv2.2.0.23.so.svn-base non-ending character in the end
	 */
	public void findIPName(String path, boolean full) {
		// surround the FileUtil by try and catch in case path name is not valid.
		try {
			// path is file name, Regex finds any file name that contains IPv4 decimal form
			Collection<?> files = FileUtils
            .listFiles(
                       new File(path),
                       new RegexFileFilter(
                                           "(.*[^0-9\\.])?(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)[^0-9][^0-9].*"),
                       DirectoryFileFilter.DIRECTORY);
            
			// set the iterator to loop through all file name
			Iterator<?> tool = files.iterator();
			while (tool.hasNext()) {
				// if full, output the full file path that matches regex, else print only filename
				if (full) {
					System.out.println(tool.next());
				} else {
					String s = tool.next().toString();
					String[] tokens = s.split("/");
					System.out.println(tokens[tokens.length - 1]);
				}
			}
            
            
		} catch (Exception e) {
			// if there is any error of path, then print path not valid
			System.out.println("The path name is not valid");
		}
        
	}
	
    /**
     * <p> This is the main method which gives the input to run the instance method.
     * @param args
     */
	public static void main(String[] args) {
		FindFileNameByRegex findfile = new FindFileNameByRegex();
		//findfile.findIPName("/repository", true);
		findfile.findIPName("/repository", false);
	}
}
