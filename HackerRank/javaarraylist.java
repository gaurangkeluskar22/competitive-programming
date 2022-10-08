import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc=new Scanner(System.in);
        int n;
        n=sc.nextInt();
        int[][] arr=new int[n][];
        for(int i=0;i<n;i++){
            int j;
            j=sc.nextInt();
            arr[i]=new int[j];
            for(int k=0;k<j;k++){
                arr[i][k]=sc.nextInt();
            }
        }
        int q;
        int t;
        int x,y;
        q=sc.nextInt();
        for(int l=0;l<q;l++){
            x=sc.nextInt();
            y=sc.nextInt();
            if(x<=n){
            t=arr[x-1].length;
            //System.out.println(t);
            if(y<=t){
            System.out.println(arr[x-1][y-1]);
            }
            else
            System.out.println("ERROR!");
            }
            else{
                System.out.println("ERROR!");
            
            }
            continue;
        }
        
    }
}
