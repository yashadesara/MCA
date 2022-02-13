import java.util.*;
public class listexe2
{
	int emp_code;
	String emp_name;
	double basic_sal;
	
	listexe2(int emp_code,String emp_name,double basic_sal)
	{
			this.emp_code = emp_code;
			this.emp_name = emp_name;
			this.basic_sal = basic_sal;
	}
	
	public static void main(String args[])
	{
		ArrayList<listexe2> list = new ArrayList<listexe2>();
		list.add(new listexe2(1,"xyz",4000));
		list.add(new listexe2(2,"abc",2000));
		list.add(new listexe2(3,"pqr",1000));
		list.add(1, new listexe2(4,"pqr",1000));
		
		for(listexe2 data:list)
		{
			System.out.println(data.emp_code);
			System.out.println(data.emp_name);
			System.out.println(data.basic_sal);
			System.out.println(data.getGrossSalary());
			System.out.println();
		}
	}	
	
	public double getGrossSalary()
	{
		return (basic_sal+( basic_sal*.2)+( basic_sal*.3)) ;
	}
	
}
