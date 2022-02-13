class primeno
{
	
	public static void main(String args[])
	{
		int i,j,start=5,end=25,flag=0;
		for(i=start; i<=end; i++)
		{
			for(j=2; j<i; j++)
			{
				if(i%j==0)
				{
					flag++;
					break;
				}
			}
			if(flag==0)
				System.out.println("prime "+i);
			
			flag=0;
		}
	}
	
}
