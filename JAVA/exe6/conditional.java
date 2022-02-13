public class conditional
{

    public static void main(String[] args) 
    {
        int a=20,b=10,c=30;
        if(a>b && a>c)
            System.out.println("a is big");
        else if(b>a && b>c)
            System.out.println("b is big");
        else
            System.out.println("c is big");
    }

}