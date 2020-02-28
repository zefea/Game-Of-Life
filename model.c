/* Zeyenep Ferah Akkurt 
 * 18120205001
 * proje 2 
 * model.c
 * provides the grid (model) 
 * and functions to handle the grid for the game of life
 * 
 */



#include "gameoflife.h"

int grid[M][N]; 	/*M and N are constants defined in gameOfLife.h*/
int blinker();         
int glider() ; 

/*grid üzerine seçilen değere göre blinker ya da glider koyan fonksiyon*/
int initGrid(int initialState)
{      
       for (int x=0 ; x<M ; x++) {
            for (int y=0 ; y<N ; y++ ) {
                grid[x][y] = 0 ;    /*grid üzerindeki her bir hücrenin değerinin sıfırlanması*/
            }
       }
	
	
       if(initialState==1){     
	      blinker();	            /*başlangıc değeri 1 ise grid üzerine blinker koyar.*/
       }else if(initialState==2){
          glider() ; 	            /*başlangıc değeri 2 ise grid üzerine glider koyar.*/
       }  
       return 0;
}



/* (x,y) noktasındaki hücrenin etrafındaki komşu sayısını döndürür
 */
int getNumberOfLiveNeighbors(int x, int y)
{        
   int neighbors = 0 ;             /*başlangıc komşu sayısı*/
   for(int i=x-1 ; i<=x+1 ; i++){  
       for(int j=y-1 ; j<=y+1 ; j++){  
           if(!(i==x && j==y)&&(x>=0) && (y>=0)&& x<M && y<N){
               if(grid[i][j]==1){   /*hücrenin etrafında olan (i,j)noktası canlı ise komşu sayısı 1 arttırılır.*/                      
                 neighbors ++ ;    		        
              }	
              
	     
  	      }		
		
       }	 
		 
	
    }	
    return neighbors;

}


/* komşu sayısına bağlı 
 * hücrelerin değerlerini kurallara göre günceller.*/
int updateGrid(){

   int neighbor[M][N] = {0};                                  /*grid üzerindeki her bir (x,y)noktasının komşu sayısını tutan komşu dizisinin tüm elemanlarının sıfırlanmaı*/

   for(int x=0 ; x<M ; x++){
       for(int y=0 ; y<N ; y++){
	   neighbor[x][y] = getNumberOfLiveNeighbors(x,y);    /*dizi elemanlarının komşu sayısını bulan fonksiyon ile oluşturulması*/
       }
	
   } 



    for(int x=0 ; x<M ; x++){
       for(int y=0; y<N ; y++){	
		   
	     if(grid[x][y]==1){                /*(x,y)hücresi canlı ise*/
		
			  if(neighbor[x][y]==1 || neighbor[x][y]==0 || neighbor[x][y]>3){           /*oyunun kuralları*/
				grid[x][y]=0 ;             /*(x,y) hücresi ölü olarak güncellenir.*/
				
			  }else if (neighbor[x][y]==3 || neighbor[x][y]==2){                        /*oyunun kuralları*/		 
				grid[x][y]=1 ;             /*(x,y) hücresi canlı olarak güncellenir.*/	
			   }
	  

         }else if(grid[x][y]==0){          /*(x,y)hücresi ölü ise*/
		   
            if(neighbor[x][y]==3){                                                     /*oyunun kuralları*/
	          grid[x][y]=1 ; 	     /*(x,y) hücresi canlı olarak güncellenir.*/
			
	        }	   
         }		 
	
       }
	
  
   }
 
   return 0;
}





/*blinker oluşturan fonksiyon*/
int blinker(){
	
    int x = CSIZE/2 ;          /*köşegenin orta noktasındaki değerinin x e atanması*/
    int y = CSIZE/2 ;          /*köşegenin orta noktasındaki değerinin y e atanması*/
	
    while(x<M && y<N){    
	    grid[x-1][y] = 1 ;     /*grid üzerindek,(x-1,y)noktasını canlandırıp blinkerın ilk parçasının konulması*/
        grid[x][y] = 1 ;       /*grid üzerindek,(x,y)noktasını canlandırıp blinkerın ikinci parçasının konulması*/
        grid[x+1][y] =1 ;      /*grid üzerindek,(x+1,y)noktasını canlandırıp blinkerın üçüncü parçasının konulması*/
    
        x = x+CSIZE;           /*her CSIZExCSIZE koşegeni üzerinde olan orta x değerinin arttırılması*/
        y = y+CSIZE;           /*her CSIZExCSIZE koşegeni üzerinde olan ortay değerinin arttırılması*/
   }
   return 1 ;
} 



/*glider oluşturan fonksiyon*/
int glider(){ 
	
   int x=CSIZE/2 ;          /*köşegenin orta noktasındaki değerinin x e atanması*/
   int y=CSIZE/2 ;          /*köşegenin orta noktasındaki değerinin y e atanması*/
	
   while(x<M && y<N){       /*gliderın şekline göre hücrelerin canlandırılması*/
	
      grid[x][y-2] = 1 ;        
      grid[x+1][y-1] = 1 ;
      grid[x+1][y] = 1 ; 
      grid[x][y] = 1 ; 
      grid[x-1][y] = 1 ;
    
      x = x+CSIZE ;         /*her CSIZExCSIZE koşegeni üzerinde olan orta x değerinin arttırılması*/
      y = y+CSIZE ;         /*her CSIZExCSIZE koşegeni üzerinde olan orta x değerinin arttırılması*/
  
   }
  return 2 ; 

}
	 
	 
	
	




















