class Thread3 extends Thread 
{
    int sec=0;
    String t;
    
    Thread3(int sec,String t)
    {
        this.sec=sec;
        this.t=t;
    }
    public void run() 
    {
        try 
        {
            for(int i=1; i<=3; i++)
            {
                System.out.println(t);
                Thread.sleep(sec);
            }   
        } 
        catch (Exception e) 
        {
            System.out.println(e);
        }
    }

    public static void main(String args[]) 
    {
        Thread3 t1 = new Thread3(2000,"Theard 1");
        Thread3 t2 = new Thread3(5000,"Theard 2");
        t1.start();
        t2.start();
    }
}