import java.util.*;
import java.lang.*;
import java.io.*;
 
 
public class Main {
    
    public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		while(n-- > 0){
		    StringTokenizer st = new StringTokenizer(br.readLine());
 
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
		    
		    if(((a+b)%3==0) && Math.max(a,b) <= 2* Math.min(a,b)){
		        System.out.println("YES");
		    }
		    else{
		        System.out.println("NO");
		    }
		    
		    
		}
		
		
	}
}
