import java.util.*;
class Student
{
	int r_no,marks;
	String name;

	Student()
	{
		r_no=1;
		name="abc";
		marks=80;
	}

	Student(int r,String n,int m)
	{
		r_no=r;
		name=n;
		marks=m;
	}

	void display()
	{
		System.out.println(r_no);
		System.out.println(name);
		System.out.println(marks);
	}

	public static void main(String[] args) 
	{
		int r,m;
		String n;

		Scanner sc = new Scanner(System.in);
		System.out.println("enter roll no");
		r = sc.nextInt();
		System.out.println("enter name");
		n = sc.next();
		System.out.println("enter marks");
		m = sc.nextInt();
		sc.close();

		Student s1 = new Student();
		System.out.println("\nfrom default constructor");
		s1.display();

		System.out.println("from paramiterized constructor");
		Student s2 = new Student(r,n,m);
		s2.display();
	}

}