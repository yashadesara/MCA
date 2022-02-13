abstract class shape
{
	abstract void area();
}

class triangle extends shape
{
	int l=10,w=20;
	
	void area()
	{
		System.out.println(l*w);
	}
	
	public static void main(String args[])
	{
		
		shape s = new triangle();
		s.area();
		
	    	shape r = new rectangle();
		r.area();
		
		shape c = new circle();
		c.area();
	}
	
}

class rectangle extends shape
{
	int l=10,w=20;
	void area()
	{
		System.out.println(l+w);
	}
}

class circle extends shape
{
	int l=10,w=20;
	void area()
	{
		System.out.println(l-w);
	}
}