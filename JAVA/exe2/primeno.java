//find prime number 
class primeno
{
	public static void main(String args[])
	{
		int i,j,flag=0,start=5,end=15;
		for(i=start;i<end;i++)
		{
			for(j=i;j<i;j++)
			{
				if(flag==0)
				{
					System.out.println("not prime");
					break;
				}
				
			}
			if(j%2!=0)
			{
				System.out.println("prime no"+j);
			}
			flag=0;
		}
	}
}