//cd ~/BAU/ACM-ICPC/Teams/A++/BlackBurn95
//sudo apt-get Accepted

import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Double.parseDouble;
import static java.lang.String.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        StringTokenizer tk;
        
        long n = parseLong(in.readLine());
        
        for(int s=0; s<=90; s++) {
            long d = s*s+4*n;
            long sq = (long)Math.sqrt(d);
            
            if(sq*sq == d) {
                long x = (-s+sq)/2;
                
                if(x>=0 && sum(x)==s) {
                    System.out.println(x);
                    return;
                }
                
                x = (-s-sq)/2;
                
                if(x>=0 && sum(x)==s) {
                    System.out.println(x);
                    return;
                }
            }
        }
        
        System.out.println("-1");
    }
    
    static int sum(long x) {
        int s = 0;
        
        while(x > 0) {
            s += x%10;
            x /= 10;
        }
        
        return s;
    }
   
}