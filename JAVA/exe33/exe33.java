import java.util.*;
class exe33
{
    static int balence=0;

    static void deposit(int d)
    {
        balence = balence+d;
        System.out.println(balence);
    }

    static void withdraw(int w) throws Exception
    {
        balence = balence-w;
        if(balence<200)
        {
           throw new Exception("not sufficiant");
        }
        else
        {
            System.out.println("withdraw is: "+w);
        }
    }

    public static void main(String args[])
    {
        try 
        {
        deposit(1000);
        withdraw(300);
        withdraw(400);
        withdraw(400);    
        } 
        catch (Exception e) 
        {
            System.out.println(e);
        }
        
    }
}