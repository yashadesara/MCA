class GEN<T,U> 
{
    T t1;
    U u1;
    public void add(T t1,U u1) 
    {
        this.t1 = t1;
        this.u1 = u1;
    }
    public void get() 
    {
        System.out.print(t1);
        System.out.println(u1);
    }
}

public class generic
{
    public static void main(String args[]) 
    {
        GEN<Integer,String> g1 = new GEN<Integer,String>();
        g1.add(10," ABC");
        g1.get();

        GEN<Integer,String> g2 = new GEN<Integer,String>();
        g2.add(20," XYZ");
        g2.get();
    }
}
