import java.util.*;

interface Exam{
   
     boolean pass(int mark);
}


interface Classify{
    
   String Division(int average);       
   
}

 class Result implements Exam,Classify
 {
   public static void main(String args[])
   { 
    Result r=new Result();
    System.out.println(r.pass(60));
    System.out.println(r.Division(30));
   }

  
  public String Division(int average) {
  
    if(average>=60)
      return "First";
  else if(average>=50&& average<60) 
      return "Second";
  return "No division";
  
  }

  
  public boolean pass(int mark) {
    
    return mark>=50;
  }
      
 }
