package Turtle;


import turtlePck.TurtleGraphicsWindow;
// funkcja c4 korzysta z funkcji sqrt i round
import java.lang.Math; 


/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ZTILabPI
 */
public class TurtleAlgorithms extends TurtleGraphicsWindow{
    
    public void positioningTurtle(int angle){
        right(angle);
    }

     
    public void sierpinski(int bok, int depth ){
         if (depth < 0) {
            return;
        }
          for(int i=1;i<4;i++){
              sierpinski(bok/2, depth-1);
              forward(bok);
              right(120);
          }
      }
    
    
    public void zad_a1(int bok, int depth ){
         if (depth < 0) {
            return;
        }
          for(int i=0;i<4;i++){
              forward(bok);
              zad_a1(bok/2, depth-1);
              right(90);
          }
      }
    
    
        public void zad_a2(int bok, int depth ){
         if (depth < 0) {
            return;
        }
          for(int i=0;i<3;i++){
              forward(bok);
              zad_a2(bok/2, depth-1);
              right(120);
          }
      }
    
    
    public void zad_a3(int bok, int depth ){
        if (depth < 0) {
           return;
        }
            
        for(int i=0;i<4;i++){
            forward(bok);
            zad_a3(bok/2, depth-1);
            left(90+180*(depth%2));
        }
    }
    
    
    public void zad_a4(int bok, int depth ){
        if (depth < 0) {
           return;
        }
            
        for(int i=0;i<3;i++){
            forward(bok);
            zad_a4(bok/2, depth-1);

            if(depth%2 == 1) {
                right(120);
            } else {
                left(120);
            }
        }
    }
    
    public void zad_a5(int bok, int depth ){
        if (depth < 0) {
           return;
        }
            
        for(int i=0;i<3;i++){
            forward(bok);
            right(120);

            zad_a5(bok/2, depth-1);
        }
        if(depth%2 == 0) {
            right(120);
        }
    }
    
    public void zad_a6(int bok, int depth ){
        if (depth < 0) {
           return;
        }
            
        for(int i=0;i<4;i++){
            forward(bok/4);
            left(90);
            zad_a6(bok/2, depth-1);
            right(90);
            forward(3*bok/4);
            right(90);
        }
    }  
    
    public void zad_a7(int bok, int depth ){
        if (depth < 0) {
           return;
        }
            
        for(int i=0;i<6;i++){
            forward(bok/4);
            left(60);
            zad_a7(bok/2, depth-1);
            right(60);
            forward(3*bok/4);
            right(120);
        }
    }
    
    public void zad_a8(int bok, int depth ){
        if (depth < 0) {
           return;
        }
            
        for(int i=0;i<6;i++){
            forward(bok/4);
            left(120);
            zad_a8(bok/2, depth-1);
            right(120);
            forward(3*bok/4);
            right(60);
        }
    }
    
    public void zad_a9(int bok, int maks ){
        if (bok > maks) {
           return;
        }

        forward(bok);
        left(90);
        zad_a9(bok+10, maks);
    }
    
    public void zad_a10(int bok, int maks ){
        if (bok > maks) {
           return;
        }

        forward(bok);
        right(120);
        zad_a10(bok+10, maks);
    }
    
    public void zad_a11(int bok, int maks ){
        if (bok > maks) {
           return;
        }

        forward(bok);
        right(60);
        zad_a11(bok+10, maks);
    }
    
            public void zad_a12(int bok, int depth ){
                if (depth < 0) {
                    return;
                }

                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        zad_a12(bok/3, depth-1);
                        for(int k=0;k<3;k++){
                            forward(bok/3);
                            right(120);
                        }
                        forward(bok/3);  
                    }
                    right(120);
                }

            }
    
    public void zad_a13(int bok, int depth ){
        if (depth < 0) {
           return;
        }

        forward(bok);
        right(45);
        zad_a13(2*bok/3, depth-1);
        left(90);
        zad_a13(2*bok/3, depth-1);
        right(45);
        back(bok);
    }
    
    public void zad_a14(int bok, int depth ){
        if (depth < 0) {
           return;
        }

        forward(bok);
        right(45);
        zad_a14(2*bok/3, depth-1);
        left(90);
        zad_a14(2*bok/3, depth-1);
        right(45);
        back(bok);
    }
    
    public void zad_b1(int bok, int depth ){
        if (depth < 0) {
           return;
        }
        for(int j=0;j<2;j++){
            zad_b1(bok/2, depth-1);
            for(int i=0;i<2;i++){
                left(90);
                forward(bok);
            }
        }
    }
    
    public void zad_b2(int bok, int depth ){
        if (depth < 0) {
           return;
        }
        for(int j=0;j<3;j++){
            left(90);
            forward(bok/2);
            right(60);
            forward(bok/2);
            left(90);
            zad_b2(bok/2, depth-1);
            right(90);
            forward(bok/2);
            right(60);
            forward(bok/2);
            right(90);
        }
    }
    
    public void zad_b3(int bok, int depth ){
        if (depth < 0) {
           return;
        }
        for(int j=0;j<2;j++){
            right(90);
            forward(bok);
            left(90);
            forward(bok/4);
            zad_b3(bok/2, depth-1);
            forward(3*bok/4);      
            right(180);
        }
    }
    
    public void zad_b4(int bok, int depth ){
        if (depth < 0) {
           return;
        }
        for(int j=0;j<2;j++){
            forward(bok);
            right(90);
            zad_b4(bok/2, depth-1);     
            right(180);
            forward(bok);
            left(90);
        }
    }
    
    public void zad_b5(int bok, int depth ){
        if (depth < 0) {
           return;
        }
        for(int j=0;j<4;j++){
            zad_b5(bok/3, depth-1);     
            right(90);
            forward(bok);
            right(180);
        }
    }
    
    public void zad_b6(int bok, int depth ){
        if (depth < 0) {
           return;
        }
        for(int j=0;j<3;j++){
            zad_b6(bok/3, depth-1);     
            forward(bok);
            right(120);
        }
    }
    
    public void zad_b7(int bok, int depth ){
        if (depth < 0) {
           return;
        }
        for(int j=0;j<3;j++){
            forward(bok/2);
            zad_b7(bok/2, depth-1);
            forward(bok/2);
            right(60);
            forward(bok);
            right(60);
        }
    }
    
    public void zad_b8(int bok, int depth ){
        if (depth < 0) { 
           return;
        }
        for(int j=0;j<3;j++){
            forward(bok);
            right(45);
            zad_b8(2*bok/3, depth-1);
            left(45);
            back(bok);
            left(45);
        }
        right(135);
    }
    
    public void zad_c1(int bok, int min ){
        if (bok < min) {
           return;
        }
        
        forward(bok);
        left(122);
        zad_c1(bok-2, min);
    }
    
    public void zad_c2(int bok, int min ){
        if (bok < min) {
           return;
        }
        
        forward(bok);
        //2 * 360 / 5
        //Wykonuje 2 pełne obroty pokonując 5 kątów
        left(144);
        zad_c2(bok-15, min);
    }
    
    public void zad_c3(int bok, int min ){
        if (bok < min) {
           return;
        }
        
        forward(bok);
        left(94);
        zad_c3(bok-4, min);
    }
    
    public void zad_c4(int bok, int depth ){
        if (depth < 0) {
           return;
        }
        forward(bok);
        left(45);
        zad_c4((int) Math.round(Math.sqrt(2)* (double) bok / 2.0), depth-1);
        right(90);
        forward((int) Math.round(Math.sqrt(2)* (double) bok / 2.0));
        zad_c4((int) Math.round(Math.sqrt(2)* (double) bok / 2.0), depth-1);
        right(90);
        forward((int) Math.round(Math.sqrt(2)* (double) bok / 2.0));
        right(45);
        forward(bok);
        right(90);
        forward(bok);
        right(90);
    }
    
    public void zad_c5(int bok, int depth ){
        if (depth < 0) {
            return;
        }
            
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                zad_c5(bok/3, depth-1);
                for(int k=0;k<4;k++){
                    forward(bok/3);
                    right(90);
                }
                forward(bok/3);  
            }
            right(90);
        }
        
    }
    
    public void zad_c6(int bok, int depth ){
        if (depth < 0) { 
           return;
        }
        zad_c6(bok/2, depth-1);
        for(int j=0;j<3;j++){
            forward(bok);
            zad_c6(bok/2, depth-1);
            back(bok);
            right(120);
        }
    }
    
    public void zad_c7(int bok, int depth ){
        if (depth < 0) { 
           return;
        }
        zad_c7(bok/3, depth-1);
        for(int j=0;j<4;j++){
            forward(2*bok/3);
            zad_c7(bok/3, depth-1);
            back(2*bok/3);
            right(90);
        }
    }
  
    public void snowFlake(int n, int bok){
        if (n==0){
            forward(bok);
            return;
        }
        snowFlake(n-1, bok/3);
        right(60);
        snowFlake(n-1, bok/3);
        left(120);
        snowFlake(n-1, bok/3);
        right(60);
        snowFlake(n-1, bok/3);

    }


public void callSnowFlake(int n, int bok){
    for(int i=1; i<4; i++){
      snowFlake(n, bok);
      left(120);
    }
}

}
