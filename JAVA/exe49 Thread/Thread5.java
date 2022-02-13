class Thread5 extends Thread 
{
    int time=0;
    String c;
    
    Thread5(int time,String c)
    {
        this.time=time;
        this.c=c;
    }
    public void run() 
    {
        try 
        {
            for(int i=1; i<=time; i++)
            {
                System.out.println(c);
            }   
        } 
        catch (Exception e) 
        {
            System.out.println(e);
        }
    }

    public static void main(String args[]) 
    {
        Thread5 t1 = new Thread5(20,"A");
        Thread5 t2 = new Thread5(30,"B");
        Thread5 t3 = new Thread5(15,"c");
        t1.start();
        t2.start();
        t3.start();
    }
}