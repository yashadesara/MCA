import java.util.*;

class customer
{
    int Bill_no;
    String cust_mobile_no;
    String item_name[] = new String[5];
    int price[] = new int[5];
    int unit[] = new int[5];

    customer(int Bill_no, String cust_mobile_no, String item[], int price[],int unit[])
    {
        this.Bill_no = Bill_no;
		this.cust_mobile_no = cust_mobile_no;
		this.item_name = item_name;
        this.price = price;
        this.unit = unit;
    }
    public static void main(String args[]) 
    {
        String phone;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter phone no.");
        phone = sc.nextLine();
        HashMap<String,customer> map = new HashMap<String,customer>();

        String item1[] = {"apple","banana","orange"};
        int price1[] = {10,10,10};
        int unit1[] = {1,2,3};
        customer c1 = new customer(1001,"6568768790",item1,price1,unit1);
        map.put("6568768790",c1);

        String item2[] = {"burger","pizza"};
        int price2[] = {20,20};
        int unit2[] = {1,2};
        customer c2 = new customer(1002,"9090909090",item2,price2,unit2);
        map.put("9090909090",c2);

        String item3[] = {"pasta","meggi"};
        int price3[] = {30,30};
        int unit3[] = {1,2};
        customer c3 = new customer(1001,"8080808080",item3,price3,unit3);
        map.put("8080808080",c3);

        for(Map.Entry<String,customer> m:map.entrySet())
        {
            customer obj = m.getValue();
            if(obj.cust_mobile_no.equals(phone))
            {
                System.out.println("Details are:");
                System.out.println("bill no: "+obj.Bill_no);
                System.out.println("mob no.: "+obj.cust_mobile_no);
                System.out.println("total price: "+obj.get_price());
                System.out.println("***************");
            }
        
        }
    }

    int get_price()
    {
        int sum=0;
		for(int i=0;i<price.length;i++)
		{
			sum +=  (this.unit[i]*this.price[i]);
		}
		return sum;
    }
}


