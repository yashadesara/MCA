interface Exam
{
    boolean pass(int marks);
}

interface Classify
{
    String division(int average);    
}

public class Result implements Exam,Classify
{

    public static void main(String[] args) {
        Result r = new Result();
        System.out.println(r.pass(50));
        System.out.println(r.division(60));
    }

    public boolean pass(int marks)
    {
        return marks>=50;
    }

    public String division(int average)
    {
        if (average>=60) 
            return "Firstclass";
        else if (average>=50 && average<60) 
            return "second";
        else
            return "no divison";
    }    
}
