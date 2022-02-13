package dpeck;
import bpeck.B;
import cpeck.C;

public class ProtectedDemo
{
	public static void main(String args[])
	{
		B b = new B();
		C c = new C();
		b.display();
		c.display();
	}
}
