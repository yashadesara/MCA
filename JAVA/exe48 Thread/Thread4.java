class Thread4 extends Thread
{
    public void run() 
    {
        try 
        {
            for(int i=1; i<=50; i++)
            {
                if(i%2!=0)
                {
                    System.out.println(i);
                }
            }       
        } 
        catch (Exception e) 
        {
            System.out.println(e);
        }
            
    }

    public static void main(String[] args) 
    {
        Thread4 t1 = new Thread4();
        even e = new even();
        t1.start();
        e.start();
    }
}

class even extends Thread
{
    public void run() 
    {
        try 
        {
            for(int i=1; i<=50; i++)
            {
                if(i%2==0)
                {
                    System.out.println(i);
                }
            }       
        } 
        catch (Exception e) 
        {
            System.out.println(e);
        }
            
    }
}