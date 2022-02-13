import java.util.*;

public class demo extends Thread
{
    public void run() 
    {
        System.out.println(currentThread().getName());
    }
    
    public static void main(String args[]) 
    {
        demo d = new demo();
        demo d2 = new demo();
        demo d3 = new demo();
        d.setName("1");
        d.setPriority(MAX_PRIORITY);
        d.start();
        d.setPriority(MIN_PRIORITY);
        d2.start();
        d3.start();
    }
}
