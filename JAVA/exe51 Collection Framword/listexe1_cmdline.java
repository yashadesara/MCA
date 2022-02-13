import java.util.*;

public class Student{
   
    private String Name;
    private int rollNo;
    private int marks[];
    
    public Student(int rollNo,String Name,int[] marks) {
        this.Name=Name;
        this.rollNo=rollNo;
        this.marks=marks;
    }


    public int[] getMarks() {
        return marks;
    }

    public int getRollNo() {
        return rollNo;
    }

    public String getName() {
        return Name;
    }

    public int total_Marks()
    {   
        int total=0;
        for (int i : this.marks) {
            total+=i;
        }
        return total;
    }

    public static void main(String[] args) {

        List<Student> s1 = new LinkedList<Student>();
        s1.add(new Student(1, "Hardik", new int[]{95,95,10,25,14}));
        s1.add(new Student(2, "Yash", new int[]{95,90,20,2,40}));
        s1.add(new Student(3, "Harshit", new int[]{90,95,45,75,64}));
   

         for (Student s: s1) {
                 if(s.getName().equals(args[0])){
                System.out.println();
                System.out.println("Roll NO:"+s.getRollNo());
                System.out.println("Name:"+s.getName());
                System.out.println("Marks:"+Arrays.toString(s.getMarks()));
                System.out.println("Total Of Marks:"+s.total_Marks());
             }
         }
    }

}


