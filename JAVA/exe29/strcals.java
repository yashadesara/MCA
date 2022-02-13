class strcals
{
	public static void main(String args[])
	{
		String s = "Hello";
		String f = " Hey ";
		String str = "my goal is be happy always.";
		
		System.out.println("upper case is :"+s.toUpperCase());
		System.out.println("Lower case is :"+s.toLowerCase());
		
		int len = s.length();
		System.out.println("string lenght is :"+len);
		
		String con = s.concat(f);
		System.out.println("concating is :"+con);
	
		String join = String.join("",s,f ,str);
		System.out.println("Joining is :"+join);
		
		System.out.println("replace is :"+s.replace('H','a'));
		
		System.out.println("cahrAt is :"+str.charAt(6));
		
		System.out.println("Substring is :"+str.substring(4,9));
		
		boolean res = str.contains("goal");
		System.out.println("containg or not :"+res);
		
		String sq = "    helllooooo  h ooo ww are u ? ????   ";
		System.out.println("Trimming is :"+sq.trim());
		
		System.out.println("split is :");
		String[] txt = str.split(" ");
		for(String st : txt)
		{
			System.out.println(st + ", ");
		}
		
		int d;
		d= str.indexOf('h');
		System.out.println("index of is :"+d);
		
		String s1= "Hello Harry";
		String s2= "Hello Harshit";
		
		d = s1.compareTo(s2);
		System.out.println("compare To is :"+d);//based on unicode value. of each char
		
		double data = 789.825d;
		System.out.println("valueof is :"+String.valueOf(data));//converting may be
		
		boolean s3;
		s3 = s1.equals(s2);
		System.out.println("first is equals or not :"+s3);
		
		
		String q="hy";
		String qq="hy";
		s3=q.equals(qq);
		System.out.println("Second is equals or not :"+s3);
	}
}