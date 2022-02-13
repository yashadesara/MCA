class vehical
{
    String vehical_type="car";   

    public void display() 
    {
        System.out.println(vehical_type);
    }
}

class car extends vehical
{
    String model_type="new";
    String company_name="oooo";

    public static void main(String args[]) 
    {
        vehical v = new vehical();
        car c = new car();
        v.display();
        c.display();
    }

    public void display() 
    {
        System.out.println(model_type);
        System.out.println(company_name);
    }

}


