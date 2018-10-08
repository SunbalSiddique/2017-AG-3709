# This data helps to study the Software Quality Score on the basis of Execution Time and Reliability Score. Here,
# X1 = Execution Time (in seconds)
# X2 = Reliability Score (out of 10)
# Y = Software Quality Score (out of 10)
X1 = c(3,5,7,9,10,11)
X2 = c(9,8,8,7,5,4)
Y = c(8,7,6,6,5,4)

x1_bar = sum(X1)/length(X1)
x2_bar = sum(X2)/length(X2)
y_bar = sum(Y)/length(Y)

#--------------------- x1_sq ------------------------
x1_sq = X1 * X1
sum_x1_sq = sum(x1_sq)

#--------------------- x2_sq ------------------------
x2_sq = X2 * X2
sum_x2_sq = sum(x2_sq)

#--------------------- x1x2 -------------------------
x1x2 = X1 * X2
sum_x1x2 = sum(x1x2)

#--------------------- x1y --------------------------
x1y = X1 * Y
sum_x1y = sum(x1y)

#--------------------- x2y --------------------------
x2y = X2 * Y
sum_x2y = sum(x2y)

#--------------------- sx2_sq -----------------------
n = 6
sx2_sq = sum_x2_sq - (n * x2_bar * x2_bar)

#--------------------- sx1_sq -----------------------
sx1_sq = sum_x1_sq - (n * x1_bar * x1_bar)

#--------------------- sx1x2 ------------------------
sx1x2 = sum_x1x2 - (n * x1_bar * x2_bar)

#--------------------- sx1y -------------------------
sx1y = sum_x1y - (n * x1_bar * y_bar)


#--------------------- sx2y -------------------------
sx2y = sum_x2y - (n * x2_bar * y_bar)

#--------------------- b1 ---------------------------
D = (sx1_sq * sx2_sq) - (sx1x2 * sx1x2)
b1 = ((sx2_sq * sx1y) - (sx1x2 * sx2y)) / D

#--------------------- b2 ---------------------------
b2 = ((sx1_sq * sx2y) - (sx1x2 * sx1y)) / D

#--------------------- b0 ---------------------------
b0 = y_bar - (b1 * x1_bar) - (b2 * x2_bar)

#--------------------- y_hat ------------------------
y_hat = b0 + (b1 * X1) + (b2 * X2)

#--------------------- TSS --------------------------
T = (Y - y_bar) * (Y - y_bar)
TSS = sum(T)

#--------------------- MSS --------------------------
M = (y_hat - y_bar) * (y_hat - y_bar)
MSS = sum(M)

#--------------------- RSS --------------------------
R = (Y - y_hat) * (Y - y_hat)
RSS = sum(R)

#--------------------- MSE --------------------------
k = 3
MSE = RSS / (n-k)

#--------------------- vb1 --------------------------
vb1 = MSE * (sx2_sq / D)

#--------------------- vb2 --------------------------
vb2 = MSE * (sx1_sq / D)

#--------------------- vb0 --------------------------
vb0 = MSE * ((1/n) + ((x1_bar * x1_bar * sx2_sq) + (x2_bar * x2_bar * sx1_sq) - (2 * x1_bar * x2_bar * sx1x2)) / D )