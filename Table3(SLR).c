// This data helps to study software quality on the basis of execution time. Here,
// X = Execution Time (in seconds)
// Y = Software Quality Score (out of 10)

#include<stdio.h>
#include<conio.h>

main()
{
      int X[10] = {3,5,7,9,10,11}, i, n=6;
      int Y[10] = {8,7,6,6,5,4};
      float y_hat[6], sxy[6], sx_sq[6], mult1[6], mult2[6], mult3[6];
      float x_bar, y_bar, sum_x = 0, sum_y = 0, b_not_hat, b_one_hat, sum_sxy=0, sum_sx_sq=0, z = 0, sigma1 = 0, sigma2 = 0, sigma3 = 0, MSE, v_b_not_hat, v_b_one_hat;
      
      printf("\n\t\t\t\t** Table 3 (SLR) **\n\n");
      printf("This data helps to study software quality on the basis of execution time. Here, \nX = Execution Time (in seconds)\nY = Software Quality Score (out of 10)\n");
      
      ////////////////////// Print x and y //////////////////////
      printf("\n------------------------------------------------------\n\n");
      printf("X = ");
      for(i=0; i<6; i++)
      {   
           printf("\t%d", X[i]);
           } 
           
      printf("\nY = ");
      for(i=0; i<6; i++)
      {   
           printf("\t%d", Y[i]);
           }    
      ////////////////////// x bar /////////////////////////////
      printf("\n\n------------------------------------------------------\n\n");
      for(i=0; i<6; i++)
      sum_x = sum_x + X[i];
      
      x_bar = sum_x / 6;
      printf("x_bar = %.2f\n", x_bar);
      
      //////////////////////// y bar ///////////////////////////
      for(i=0; i<6; i++)
      sum_y = sum_y + Y[i];
      
      y_bar = sum_y / 6;
      printf("y_bar = %.2f\n" , y_bar);
      
      /////////////////////// b1 hat /////////////////////////
      printf("\n------------------------------------------------------\n\n");
      for(i=0; i<6; i++)
      {
               sxy[i] = (X[i]-x_bar) * (Y[i]-y_bar);
               sx_sq[i] = (X[i]-x_bar) * (X[i]-x_bar);
               z = z + sx_sq[i];
               }
      for(i=0; i<6; i++)
      {
               sum_sxy = sum_sxy + sxy[i];
               sum_sx_sq = sum_sx_sq + sx_sq[i];
               }
      b_one_hat = sum_sxy / sum_sx_sq;
      printf("b1 = %.3f\n", b_one_hat);
      
      //////////////////// b0 hat /////////////////////////
      b_not_hat = y_bar - (b_one_hat * x_bar);
      printf("b0  = %.2f\n" , b_not_hat);
      
      /////////////////// TSS /////////////////////////////
      printf("\n------------------------------------------------------\n\n");
      for(i=0; i<6; i++)
      {
               mult1[i] = Y[i] - y_bar;
               mult1[i] = mult1[i] * mult1[i];
               sigma1 = sigma1 + mult1[i];
               }
               printf("Total Sum of Squares = %.2f\n" , sigma1);
               
      ////////////////// MSS ////////////////////////////
      for(i=0; i<6; i++)
      {
               y_hat[i] = (b_not_hat) + (b_one_hat * X[i]);
               mult2[i] = y_hat[i] - y_bar;
               mult2[i] = mult2[i] * mult2[i];
               sigma2 = sigma2 + mult2[i];
               }
               printf("Model Sum of Squares = %.2f\n" , sigma2);
               
      ////////////////// RSS ////////////////////////////
      for(i=0; i<6; i++)
      {
               mult3[i] = Y[i] - y_hat[i];
               mult3[i] = mult3[i] * mult3[i];
               sigma3= sigma3+ mult3[i];
               }
               printf("Residue Sum of Squares = %.2f\n" , sigma3);
               
      ////////////////// v(b_not_hat) /////////////////////
      printf("\n------------------------------------------------------\n\n");
      MSE = sigma3/4;
      printf("MSE = %.2f\n", MSE);

      v_b_not_hat = MSE * ((0.17) + ((x_bar*x_bar)/z));
      printf("vb0 = %.2f\n", v_b_not_hat);
      
      ///////////////// v(b_one_hat) ////////////////////////
      v_b_one_hat = MSE / z;
      printf("vb1 = %.4f\n", v_b_one_hat);
      
      getch();
      }
