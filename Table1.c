#include<stdio.h>
#include<conio.h>
main()
{
      int X1[7] = {100,200,300,400,500,600,700}, X2[7] = {10,20,10,30,20,20,30}, Y[7] = {40,50,50,70,65,65,80};
      int x1_sq[7], x2_sq[7], x1x2[7], x1y[7], x2y[7];
      int i, n=7, k=3, sum_x1=0, sum_x2=0, sum_y=0, sum_x1_sq=0, sum_x2_sq=0, sum_x1x2=0, sum_x1y=0, sum_x2y=0;
      float x1_bar, x2_bar, y_bar, sx2_sq, sx1_sq, sx1x2, sx1y, sx2y, D, b_one, b_two, b_not, y_hat[7], T[7], M[7], R[7], TSS=0, MSS=0, RSS=0, MSE, vb1, vb2, vb0;
      
      printf("\n\t\t\t\t** Table 1 **\n\n");
      // -------------------------- x1_bar -------------------------------
      printf("\n--------------------------------------------\n\n");
      for(i=0;i<7;i++)
      {
                      sum_x1 = sum_x1 + X1[i];
                      x1_bar = sum_x1 / n;
                      }
                      printf("x1_bar = %.2f\n", x1_bar);
      
      // -------------------------- x2_bar -------------------------------                
      for(i=0;i<7;i++)
      {
                      sum_x2 = sum_x2 + X2[i];
                      x2_bar = sum_x2 / n;
                      }
                      printf("x2_bar = %.2f\n", x2_bar);
                      
      // -------------------------- y_bar -------------------------------                
      for(i=0;i<7;i++)
      {
                      sum_y = sum_y + Y[i];
                      y_bar = sum_y / n;
                      }
                      printf("y_bar = %.2f\n", y_bar);
                      
      // -------------------------- x1_sq -------------------------------                
      for(i=0;i<7;i++)
      {
                      x1_sq[i] = X1[i] * X1[i];
                      sum_x1_sq = sum_x1_sq + x1_sq[i];
                      }
                      printf("sum_x1_sq = %d\n", sum_x1_sq);
                      
      // -------------------------- x2_sq -------------------------------                
      for(i=0;i<7;i++)
      {
                      x2_sq[i] = X2[i] * X2[i];
                      sum_x2_sq = sum_x2_sq + x2_sq[i];
                      }
                      printf("sum_x2_sq = %d\n", sum_x2_sq);
                      
      // -------------------------- x1x2 -------------------------------                
      for(i=0;i<7;i++)
      {
                      x1x2[i] = X1[i] * X2[i];
                      sum_x1x2 = sum_x1x2 + x1x2[i];
                      }
                      printf("sum_x1x2 = %d\n", sum_x1x2);
                      
      // -------------------------- x1y -------------------------------                
      for(i=0;i<7;i++)
      {
                      x1y[i] = X1[i] * Y[i];
                      sum_x1y = sum_x1y + x1y[i];
                      }
                      printf("sum_x1y = %d\n", sum_x1y);
                      
      // -------------------------- x2y -------------------------------                
      for(i=0;i<7;i++)
      {
                      x2y[i] = X2[i] * Y[i];
                      sum_x2y = sum_x2y + x2y[i];
                      }
                      printf("sum_x2y = %d\n", sum_x2y);
                      
      // -------------------------- sx2_sq -----------------------------
      sx2_sq = sum_x2_sq - (n * x2_bar * x2_bar);
      printf("sx2_sq = %2.f\n", sx2_sq);
      
      // -------------------------- sx1_sq -----------------------------
      sx1_sq = sum_x1_sq - (n * x1_bar * x1_bar);
      printf("sx1_sq = %2.f\n", sx1_sq);
      
      // -------------------------- sx1x2 -----------------------------
      sx1x2 = sum_x1x2 - (n * x1_bar * x2_bar);
      printf("sx1x2 = %2.f\n", sx1x2);
      
      // -------------------------- sx1y -----------------------------
      sx1y = sum_x1y - (n * x1_bar * y_bar);
      printf("sx1y = %2.f\n", sx1y);
      
      // -------------------------- sx2y -----------------------------
      sx2y = sum_x2y - (n * x2_bar * y_bar);
      printf("sx2y = %2.f\n", sx2y);
      
      // ----------------------- Denominator ------------------------
      D = (sx1_sq * sx2_sq) - (sx1x2 * sx1x2);
      
      // -------------------------- b1 ------------------------------
      printf("\n--------------------------------------------\n\n");
      b_one = ((sx2_sq * sx1y) - (sx1x2 * sx2y)) / D;
      printf("b1 = %.3f\n", b_one);
      
      // -------------------------- b2 ------------------------------
      b_two = ((sx1_sq * sx2y) - (sx1x2 * sx1y)) / D;
      printf("b2 = %.2f\n", b_two);
      
      // -------------------------- b0 ------------------------------
      b_not = y_bar - (b_one * x1_bar) - (b_two * x2_bar);
      printf("b0 = %.2f\n", b_not);
      
      // -------------------------- y_hat ---------------------------                
      for(i=0;i<7;i++)
      {
                      y_hat[i] = b_not + (b_one * X1[i]) + (b_two * X2[i]);
                      }
                      
      // -------------------------- TSS -------------------------------                
      printf("\n--------------------------------------------\n\n");
      for(i=0;i<7;i++)
      {
                      T[i] = (Y[i] - y_bar) * (Y[i] - y_bar);
                      TSS = TSS + T[i];
                      }
                      printf("Total Sum of Squares = %.2f\n", TSS);
                      
      // -------------------------- MSS -------------------------------                
      for(i=0;i<7;i++)
      {
                      M[i] = (y_hat[i] - y_bar) * (y_hat[i] - y_bar);
                      MSS = MSS + M[i];
                      }
                      printf("Model Sum of Squares = %.2f\n", MSS);
                      
      // -------------------------- RSS -------------------------------                
      for(i=0;i<7;i++)
      {
                      R[i] = (Y[i] - y_hat[i]) * (Y[i] - y_hat[i]);
                      RSS = RSS + R[i];
                      }
                      printf("Residue Sum of Squares = %.2f\n", RSS);
                      
      // -------------------------- MSE -------------------------------                
      printf("\n--------------------------------------------\n\n");
      MSE = RSS / (n-k);
      printf("MSE = %.2f\n", MSE);
      
      // -------------------------- vb1 -------------------------------                
      vb1 = MSE * (sx2_sq / D); 
      printf("vb1 = %.6f\n", vb1);
      
      // -------------------------- vb2 -------------------------------                
      vb2 = MSE * (sx1_sq / D); 
      printf("vb2 = %.3f\n", vb2);
      
      // -------------------------- vb0 -------------------------------                
      vb0 = MSE * (((0.14) + ((x1_bar * x1_bar * sx2_sq) + (x2_bar * x2_bar * sx1_sq) - (2 *  x1_bar * x2_bar * sx1x2)) / D));
      printf("vb0 = %.3f\n", vb0);
      printf("\n--------------------------------------------\n\n");
                      
      getch();
      }
      
