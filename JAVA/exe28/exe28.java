import java.util.Scanner;

class exe28
{
	public static void main(String args[])
	{
		String str="";
		System.out.println("enter a stirng:");
		Scanner sc = new Scanner(System.in);
		
		str = sc.nextLine();
		
		if(str.equals(str.toLowerCase()))
		{
			System.out.println(str.toUpperCase());
		}
		
		else if(str.equals(str.toUpperCase()))
		{
			System.out.println(str.toLowerCase());
		}
		
	}
}