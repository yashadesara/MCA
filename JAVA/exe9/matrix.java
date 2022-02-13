public class matrix
{    
    public static void main(String[] args) {    
        int rows, cols, sumRow, sumCol;    
            
        int a[][] = {       
                        {10, 20, 30},    
                        {40, 50, 60},    
                        {70, 80, 90}    
                    };    
              
        rows = a.length;    
        cols = a[0].length;    
            
        
        for(int i = 0; i < rows; i++){    
            sumRow = 0;    
            for(int j = 0; j < cols; j++){    
              sumRow = sumRow + a[i][j];    
            }    
            System.out.println("Sum of " + (i+1) +" row: " + sumRow);    
        }    
            
    }    
} 