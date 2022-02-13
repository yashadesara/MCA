class A
{
	static int x=10;
}

class B extends A
{
	int x=20;
	public static void main(String args[])
	{
		B x = new B();
		x.display();
	}
	
	void display()
	{
		System.out.println(x);
		System.out.println(super.x);
	}
}