//link to the question
//https://codeforces.com/contest/1520/problem/C
import java.util.*;
import java.io.*;
public class NotAdjacentNumber{
 
     public static void main(String []args) throws IOException{
        Scanner sc= new Scanner(System.in);
        int loop = sc.nextInt();
        for(int ij=0;ij<loop;ij++)
        {
           
           int n=sc.nextInt();
           if(n==1)
           {
               System.out.println(1);
               continue;
           }
           if(n==2)
           {
               System.out.println(-1);
               continue;
           }
           int n2 = n*n;
           int a[]=new int[n2+1];
           int j=1;
           for(int i=1;i<=n*n;i++)
           {
               
               if(i%2==0)
               {
                   int store = (n2+1)/2;
                   a[store+j] = i;
                   j++;
               }
               else{
                   a[j] = i;
               }
               
           }
           for(int i=1;i<=n2;i++)
           {
               
               if(i%n==0)
               {
                   System.out.println(a[i]);
               }
               else
               {
                   System.out.print(a[i]+" ");
               }
           }
        }
     }
     
}
