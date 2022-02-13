//find prime number using start point and ending point is given
class prime_atr
{
	public static void main(String args[])
	{
		int n,j,start = 5,end = 15,flag=0;
		
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
				System.out.println("prime"+n);
				
			}
			flag=0;
			
		}
	}
}
