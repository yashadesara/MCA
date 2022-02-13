import java.util.*;
public class listexe4
{
	int std_id;
	String std_name;
	int marks[];
	
	listexe4(int std_id, String std_name,int marks[])
	{
		this.std_id = std_id;
		this.std_name = std_name;
		this.marks = marks;
	}
	
	public static void main(String args[])
	{	
		LinkedList<listexe4> list = new LinkedList<listexe4>();
		list.add(new listexe4(1,"xyz",new int[]{60,70,80}));
		list.add(new listexe4(2,"abc",new int[]{50,70,40}));
		list.add(new listexe4(3,"pqr",new int[]{40,90,70}));
        Collections.sort(list,new AgeComparator());
        //Collections.sort(list,new NameComparator());
		
		for(listexe4 data:list)
		{
			System.out.println(data.std_id);
			System.out.println(data.std_name);
			System.out.println(Arrays.toString(data.marks));
			System.out.println(data.TotalMarks());
			System.out.println();
		}
	}	


	
	public int TotalMarks()
	{
		int total=0;
		for(int i=0; i<this.marks.length; i++)
			total += marks[i];
		
		return total;
	}	
}

class NameComparator implements Comparator<listexe4>
    {  
        public int compare(listexe4 o1,listexe4 o2)
         {  
            return o1.std_name.compareTo(o2.std_name);  
        }  
    }  

class AgeComparator implements Comparator<listexe4>
    {  
        public int compare(listexe4 o3,listexe4 o4)
        {  
            if(o3.std_id==o4.std_id)  
                return 0;  
            else if(o3.std_id>o4.std_id)  
                return 1;  
            else  
                return -1;  
        }  
    }  
