public class conditional
{

    public static void main(String[] args) 
    {
        int a=20,b=10,c=30,d=50;
        if(a>b && a>c)
            System.out.println("a is big");
        else if(b>a && b>c)
            System.out.println("b is big");
        else if(c>a && b>b)
            System.out.println("c is big");
        else
            System.out.println("d is big");
    }

}
