import java.util.*;
class prime_atr
{
	public static void main(String args[])
	{
		int n,j,start,end ,flag=0,a=0,b=1,t=1,i,c;
		Scanner sc= new Scanner(System.in);
		System.out.println("enter start :");
		
		start = sc.nextInt();
		
		System.out.println("enter end :");
		end = sc.nextInt();
		System.out.println(" prime");
		for(n=start; n<=end; n++)
		{
			for(j=2; j<n; j++)
			{
				if(n%j==0)
				{
					flag++;
					break;
				}
			}
			if(flag==0)
			{
				System.out.println(n);
			}
			flag=0;
		}
		System.out.println(" fibo");	
			System.out.println(a+" "+b);
			for(j=2; j<=n; j++)
			{
				c=a+b;
				System.out.println(c);
				a=b;
				b=c;
			}
	}
}
