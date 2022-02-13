class exe31
{
	public static void main(String args[])
	{
		try 
		{
			int a=10,b=0;
			System.out.println("div is"+(a/b));
		}
		catch(ArithmeticException a)
		{
			System.out.println("value is not div by 0 "+a);
		}
		
	}
}