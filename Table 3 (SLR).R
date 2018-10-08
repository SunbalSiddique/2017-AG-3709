# This data helps to study the Software Quality Score on the basis of Execution Time. Here,
# X = Execution Time (in seconds)
# Y = Software Quality Score (out of 10)

X = c(3,5,7,9,10,11)
Y = c(8,7,6,6,5,4)
x_bar = sum(X) / length(X)
y_bar = sum(Y) / length(Y)

# ------------ xi-x_bar -------------------
x = X - x_bar

# ----------- yi-y_bar --------------------
y = Y - y_bar

# ----------- sxy -------------------------
sxy = sum( x * y)

# ---------- sx_sq ------------------------
sx_sq = sum (x * x)

# -------------- b1 -----------------------
b1  = sxy / sx_sq

# -------------- b0 -----------------------
b0 = y_bar - (b1 * x_bar)

# ------------ TSS ------------------------
TSS = sum((Y - y_bar) * (Y - y_bar))

#------------ MSS -------------------------
y_hat = b0 + (b1 * X)

MSS = sum((y_hat-y_bar) * (y_hat-y_bar))
                
# ------------- RSS -----------------------
RSS = sum((Y - y_hat) * (Y - y_hat))

#-------------- MSE -----------------------
n = 6
k = 2
MSE = RSS / (n-k)
  
#-------------- vb0-----------------------
vb0 = MSE * ((1/n) + ((x_bar*x_bar)/sx_sq))
                
#-------------- vb1 -----------------------
vb1 = MSE / sx_sq
                