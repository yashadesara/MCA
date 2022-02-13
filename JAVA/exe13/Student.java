import java.util.Scanner;

class Student
{
	int r_no, marks;
    String name, gender;
    public static int count=0;

	Student()
	{
		this.r_no=0;
		this.name="abc";
        this.marks=0;
        this.gender="male";
        count++;
	}

	Student(int r,String n,int m,String g)
	{
		this.r_no=r;
		this.name=n;
        this.marks=m;
        this.gender=g;
        count++;
	}

	void display()
	{
		System.out.println(r_no);
		System.out.println(name);
        System.out.println(marks);
        System.out.println(gender);
	}

	public static void main(String[] args) 
	{
		int r,m;
		String n,g;

		Scanner sc = new Scanner(System.in);
		Student s1 = new Student();
		
		System.out.println("enter roll");
		r = sc.nextInt();
		System.out.println("enter name");
		n = sc.next();
		System.out.println("enter marks");
        m = sc.nextInt();
        System.out.println("enter gender");
		g = sc.next();

		System.out.println("\nfrom default constructor");
		s1.display();

		System.out.println("\nfrom paramiterized constructor");
		Student s2 = new Student(r,n,m,g);
        s2.display();

		System.out.println("\ncount is: "+Student.count);
    
	}
}